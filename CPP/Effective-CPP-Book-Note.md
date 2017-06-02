#Note

# Accustoming Yourself to C++

### Item1: View C++ as a federation of languages
+ C
+ Object-Oriented C++
+ Template C++
+ STL

### Item2: Prefer const, enums, and inlines to #define
+ 用编译器替换预处理器
+ class专属常量
```cpp
class GamePlayer {
private:
	static const int NumTurns = 5;
	int scores[NumTurns];
};
```
+ 向上面的"in-class初值设定"只有在新编译器，而且类型为整数类(如ints, chars, bools)才可以。否则要以下方式
+ 还有一种情况，如果你要取某个class专属常量的地址，这个时候，你也需要提供定义式。
```cpp
// header file
class CostEstimate {
private:
	static const double FudgeFactor;
};
// implementation file
const double CostEstimate::FudgeFactor = 1.35;
```
+ 还有一种方式
```cpp
class GamePlayer {
private:
	enum { NumTurns = 5; }
	int scores[NumTurns];
};
```
+ 从某种意义上将，enum行为更像#define而不像const,比如取一个const的地址是合法的，但是取一个enum的地址就不合法
+ 用inline函数替代宏
+ 除#define外，#include和#ifdef/#ifndef还是必需品

### Item3: Use const whenever possible
```cpp
const char* p = greeting;	// non-const pointer, const data
char* const p = greeting;	// const pointer, non-const data

const写在类型之前，或者写在类型之后、星号之前均可,以下写法均可
void f1(const Widget* pw);
void f2(Widget const* pw);

std::vector<int> vec;
const std::vector<int>::iterator iter = vec.begin();  //iter作用类似T* const
*iter = 10; // OK
++iter;     // error
std::vector<int>::const_iterator cIter = vec.begin(); //iter作用类型const T*
*iter = 10; // error
++iter;     // OK

令函数返回一个常量值，往往可以降低客户错误造成的意外，而又不至于放弃安全性和高效性。
class Rational { ... };
const Rational operator* (const Rational& lhs, const Rational& rhs);
```
+ const成员函数
	+ 将const实施于成员函数的目的，是为了确认该成员函数可作用于const对象
	+ 两个成员函数如果只是常良性不同，可以被重载
	+ const成员函数不可以更改对象内任何non-static成员变量
	+ 编译器强制实施bitwise constness，但编写程序时应该使用"概念上的常量性"logical constness
	+ mutable变量可以在const成员函数内可被修改
+ 运用const成员函数实现出其non-const孪生兄弟
```cpp
class TextBlock {
public:
	const char& operator[](std::size_t position) const {
		...
		return text[position];
	}
	char& operator[](std::size_t position) {
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}
};
```

### Item4: Make sure that objects are initialized before they're used.
+ 为内置型对象进行手工初始化，因为c++不保证初始化它们
+ 构造函数最好使用成员初值列表，而不要在构造函数本体内使用赋值操作。初值列出的成员变量，其排列顺序应该和它们在class中的声明次序相同。
	+ 如果成员变量是const或references,它们就一定需要初值，不能被赋值。
	+ c++有着十分固定的“成员初始化次序”，先base class再derived class，而class的成员变量总是以其声明次序被初始化
+ 函数内的static对象成为local static对象，其他static对象成为non-local static对象。
+ 为避免“跨编译单元之初始化次序”问题，请以local static对象替换non-local static对象。因为c++对于“定义于不同编译单元内的non-local static对象”的初始化顺序并无明确定义。这里是通过“c++保证，函数内的local static对象会在该函数被调用期间，首次遇上该对象之定义式时被初始化”
+ Demo Code
```cpp
// original code which could fail
// File A
class FileSystem {
public:
	std::size_t numDisk() const;
};
extern FileSystem tfs;
// File B
class Directory {
public:
	Directory(...);
};
Directory::Directory(...) {
	std::size_t disks = tfs.numDisks();
}

// right code
// File A
class FileSystem { ... };
FileSystem& tfs() {
	static FileSystem fs;
	return fs;
}
// File B
class Directory { .... };
Directory::Directory(...) {
	std::size_t disks = tfs().numDisks();
}
Directory& tempDir() {
	static Directory td;
	return td;
}
```
+ non-local static对象被local static对象替换了，这在**Singleton**模式也用到了。


# Constructors, Destructors, and Assignment Operators

### Item5: Know what functions C++ silently writes and calls
+ 编译器可以为`class`创建default构造函数、copy构造函数、copy assignment操作符以及析构函数
+ 但是在出现例外情况时，编译器会拒绝为编译器生成`operator =`(copy assignment操作符）
	+ 当一个类中”内含reference成员"
	+ 当一个类中"内含`const`成员"
	+ 如果某个`base class`将`copy assignment`声明为`private`,编译器会拒绝为derived class生成一个copy assignment操作符
	
### Item 6: Explicitly disallow the use of compiler-generated functions you don't want. ###
  +  将相应的成员函数声明为`private`,并且不予实现;因而被用在c++ `iostream`程序库中阻止copying行为
  +   使用像Uncopyable这样的基类，如下
```C++
class Uncopyable {
protected:
	Uncopyable() { }
	~Uncopyable() { }
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale: private Uncopyable {
};
```
+ Uncopyable的实现和运用颇为微妙，不一定得以`public`继承它；析构函数不一定得是`virtual`

### Item7: Declare destructors virtual in polymorphic base classes
+ polymorphic base class应该声明一个`virtual`析构函数。如果class带有任何`virtual`函数，它就应该拥有一个`virtual`析构函数。
+ 当class不企图被当做base class,令其析构函数为virtual是一个馊主意，因为virtual函数为增大对象的体积（vptr和vtbl）
+ 绝对不要继承string, vector, list, set, unordered_map，因为这些类都不作为base class,它们在设计的时候就没有virtual析构函数
+ 构建abstract class的很好的方法，提供pure virtual析构函数，**但记住一定要给出析构函数的定义（哪怕是空的）**,因为编译器会在AWOV的derived classes的析构函数中创建一个对~AWOV的调用动作，如果未提供，连接器会发出抱怨
```cpp
class AWOV {
public:
	virtual ~AWOV() = 0;
};
AWOV::~AWOV() { }
```

### Item8: Prevent exceptions from leaving destructors
+ 考虑下面这种情况
```cpp
class DBConnection {
public:
	static DBConnection create();
	void close();
};
//为了确保客户不忘记在DBConnection对象上调用close(),一个合理的想法是创建一个管理DBConnection资源的class,并在析构函数中调用close
class DBConn {
public:
	~DBConn() {
		db.close();
	}
private:
	DBConnection db;
};
```
+ 现在要讨论的问题是，如果close调用会导致异常该怎么办？
+ 两个办法：
```cpp
// 1st way: 结束程序
DBConn::~DBConn() {
	try { db.close(); }
	catch (...) {
		//log, 记下close的调用失败
		std::abort();
	}
}
// 2nd way: 吞下因调用close而发生的异常
DBConn::~DBConn() {
	try { db.close(); }
	catch (...) {
		//log 
	}
}
```
+ 以上办法都没什么吸引力，因为都无法对"导致close抛出异常"的情况作出反应
+ 一个比较好的设计：DBConn提供一个close函数，因而赋予客户一个机会得以处理“因该操作而发生的异常”，同时DBConn也追踪其所管理之DBConnection是否已经关闭，并在答案为否的情况下由析构函数关闭之。
```cpp
class DBConn {
public:
	void close() {
		db.close();
		closed = true;
	}
	~DBConn() {
		if (!closed) {
			try {
				db.close();
			} catch (...) {
				// log
				// do something
			}
		}
	}
private:
	DBConnection db;
	bool closed;
};
```
+ 总结： 析构函数突出异常总是危险的，总会带来“过早结束程序”或“发生不明确行为”的风险。
+ 如果一个析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们（不传播）或结束程序
+ 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个**普通函数**（而非在析构函数中）执行该操作。

### Item9: Never call virtual functions during construction or destruction
+ 在构造和析构期间不要调用`virtual`函数，因为这类调用从不下降至derived class（比起当前执行构造函数和析构函数的那层）
+ 因为在derived class对象的base class构造期间，对象的类型是base class而不是derived class.
+ 错误代码
```cpp
class Transaction {
public:
	Transaction() { init(); }
	virtual void logTransaction() const = 0;
private:
	void init() {
		....
		logTransaction();
	}
};
```
+ 正确做法：在class Transaction内将logTransaction函数改为non-virtual，然后要求derived class构造函数传递必要信息给Transaction构造函数。
```cpp
class Transaction {
public:
	explicit Transaction(const std::string& logInfo);
	void logTransaction(const std::string& logInfo) const;
};
Transaction::Transaction(const std::string& logInfo) {
	...
	logTransaction(logInfo);
}
class BuyTransaction: public Transaction {
public:
	BuyTransaction( ... )
		: Transaction(createLogString( ... ))
	{ }
private:
	static std::string createLogString(...);

```
+ 由于你无法使用virtual函数从base classes向下调用，在构造期间，你可以用“令derived class将必要的构造信息向上传递至base class构造函数”替代。

### Item10: Have assignment operators return a reference to *this
+ 为了实现“连续复制”，赋值操作符必须返回一个reference指向操作符的左侧实参。
+ 这只是一个协议，然而这份协议被所有内置类型和标准程序库提供的类型如string, vector, complex, std::shared_ptr共同遵守。
+ 这个协议不仅仅适用标准赋值形式，也适用于所有赋值相关运算。
+ Demo Code
```cpp
class Widget {
public:
	Widget& operator=(const Widget& rhs) {
		...
		return *this;
	}
	Widget& operator+=(const Widget& rhs) {
		...
		return *this;
	}
	Widget& operator=(int rhs) {
		...
		return *this;
	}
};
```

### Item11: Handle assignments to self in operator=
+ 如果是运用智能指针(Item13,Item14)来管理资源，而且确定所谓“资源管理对象”在copy时有正确的举措。这种情况下你的赋值操作符或许是“自我赋值安全的”，不需要额外操心。如果要自行管理资源，可能会调入陷阱
+ 方法一：证同测试,具备“自我赋值安全性”，但是不具备“异常安全性”
```cpp
Widget& Widget::operator=(const Widget& rhs) {
	if (this == &rhs) 
		return *this;
	delete pb;
	pb = new Bitmap(*rhs.pb);
	return *this;
}
```
+ 方法二：精心安排的语句可以导出异常安全（以及自我赋值安全）的代码
```cpp
Widget& Widget::operator=(const Widget& rhs) {
	Bitmap* pOrig = pb;
	pb = new Bitmap(*rhs.pb);
	delete pOrig;
	return *this;
}
```
+ 方法三：copy and swap技术,常见而且较好
```cpp
Widget& Widget::operator=(const Widget& rhs) {
	Widget temp(rhs);
	swap(temp);
	return *this;
}
Widget& Widget::operator=(Widget rhs) {
	swap(rhs);
	return *this;
}
```

### Item12: Copy all parts of object
+ 当编写一个copying函数时，请确保(1)复制所有local成员变量(2)调用所有base class内的适当的copying函数
+ 如果你发现copy构造函数和copy assignment操作符有相近的代码，消除重复代码的做法是，建立一个新的成员函数给两者调用。这样的函数往往是private而且常被命名init。
+ Demo Code
```cpp
class Date { ... };
class Customer {
public:
	...
private:
	std::string name;
	Date lastTransaction;
};
class PriorityCustomer: public Customer {
public:
	PriorityCustomer(const PriorityCustomer& rhs);
	PriorityCustomer& operator=(const PriorityCustomer& rhs);
private:
	int priority;
};
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs) 
	: Customer(rhs), priority(rhs.priority) {
	...
}
PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
	Customer::operator=(rhs);
	priority = rhs.priority;
	return *this;
}
```

# Resource Management

### Item 13: Use objects to manage resources. ###
 + 把资源放进对象内，依赖C++的“析构函数自动调用机制”确保资源被释放。
 + C++11中智能指针`auto_ptr`和`shared_ptr`.  
```cpp
#include <memory>
void f() {
	std::auto_ptr<Investment> pInv(createInvestment());
}
```
 + 获得资源后立刻放进管理对象(RAII)(Resource Acquisition is Initialization)(资源取得时机便是初始化时机)
 + 但是不能让多个`auto_ptr`指向同一对象，若通过copy构造函数或copy assignment操作符复制它们，原来`auto_ptr`会指向`NULL`,而复制的指针将取得资源唯一拥有权
```cpp
std::auto_ptr<Investment> pInv2(pInv); //此时pInv2指向对象，而pInv1为NULL
pInv1 = pInv2;						   //此时pInv1指向对象，而pInv2为NULL
```
 + 但是STL容器要求其元素具有“正常”的复制行为，所以引入`shared_ptr`.
```cpp
void f() {
	std::shared_ptr<Investment> pInv(createInvestment());
	std::shared_ptr<Investment> pInv2(pInv1);  //pInv1和pInv2指向同一个对象
	pInv1 = pInv2;  //无变化
}					//pInv1和pInv2被销毁，所指向的对象也自动销毁		
```
+ `auto_ptr`和`shared_ptr`两者在其析构函数做`delete`而不是`delete[]`,所以不要让它们管理动态分配的`array`.
```cpp
std::auto_ptr<std::string> aps(new std::string[10]);	//wrong usage;
std::shared_ptr<int> spi(new int[1024]);				//wrong usage;
```
+ 在c++11中，并没有特别针对“C++动态分配数组”而设计的智能指针，因为`vector`和`string`几乎总是可以取代动态分配.如果一定想用，参考`boost::scoped_array`和`boost::shared_array`.

### Item 14: Think carefully about copying behavior in resource-managing classes ###
+ 对于非heap-based资源，就要建立自己的资源管理类
```cpp
void lock(Mutex* pm);
void unlock(Mutex* pm);
```
+ 为了确保不会忘记将一个锁住的Mutex解锁，建立一个类来管理锁
```cpp
class Lock {
public:
	explicit Lock(Mutex* pm) 
		: mutexPtr(pm) {
		lock(mutexPtr);
	}
	~Lock() {
		unlock(mutexPtr);
	}
private:
	Mutex* mutexPtr;
}
```
+ 以上已经符合RAII方式，但是如果Lock对象被复制，怎么办?
```cpp
Lock ml1(&m);
Lock ml2(ml1);
```
+ **禁止复制** _Refer to Item 6 for detail_
+ **对底层资源用“引用计数法"**,通常只要内含`std::shared_ptr`变量，RAII classes便可实现出reference-counting copying行为。但是`std::shared_ptr` 缺省行为是"引用次数为0时删除其所指物",但对于Mutex，我们只需要释放锁。
+ 幸运的是，`std::shared_ptr`允许制定"删除器"
```cpp
class Lock {
public:
	explicit Lock(Mutex* pm)
		: mutexPtr(pm, unlock) {         //unlock即为之前定义的释放锁函数
			lock(mutexPtr.get());
		}
private:
	std::shared_ptr<Mutex> mutexPtr;
};
```
+ 复制底部资源
+ 转移底部资源的拥有权，比如`auto_ptr` 奉行的宗旨


### Item15: Provide access to raw resources in resources-managing classes###
+ 资源管理类很棒，但是很多API需要直接访问原始资源，如下
```cpp
int daysHeld(const Investment* pi);
std::shared_ptr<Investment> pInv(createInvestment());
int days = daysHeld(pInv); 			// wrong usage!
```
+ 需要一个函数将RAII class对象(此例中的`std::shared_ptr` 转换为其所内含的原始资源，两种方法：
**显示转换**和**隐式转换**
+ `std::shared_ptr`和`std::auto_ptr`都提供了get成员函数，用以显式转换
```cpp
int days = daysHeld(pInv.get());
```
+ 几乎所有智能指针，包括`std::shared_ptr`和`std::auto_ptr`重载了指针取值操作符(`operator->`和`operator*`，允许隐式转换至底部原始指针
```cpp
class Investment {
public:
	bool isTaxFree() const;
	...
};
Investment* createInvestment();
std::shared_ptr<Investment> pi1(creatInvestment());
bool taxable1 = !(pi1->isTaxFree());	//经由operator->访问资源
std::auto_ptr<Investment> pi2(createInvestment());
bool taxable2 = !((*pi2).isTaxFree());  //经由operator*访问资源
```

+ RAII class example II
```cpp
FontHandle getFont();
void releaseFont(FontHandle fh);
class Font {
public:
	explicit Font(FontHandle fh)
		: f(fh) { }
	~Font() { releaseFont(f); }
private:
	FontHandle f;
};
```
+ 显示转换函数
```cpp
class Font {
public:
	FontHandle get() const { return f; }
};
```
+ 用法
```cpp
void changeFontSize(FontHandle f, int newSize); //C API
Font f(getFont());
int newFontSize;
changeFontSize(f.get(), newFontSize);
```
+ 隐式转换函数
```cpp
class Font {
public:
	operator FontHandle() const { return f; } //隐式转换函数
};
```
+ 用法
```cpp
Font f(getFont());
int newFontSize;
changeFontSize(f, newFontSize);
```

+ 一般而言，**显示转换比较安全**，推荐使用显示转换

### Item16: Use the same form in corresponding uses of new and delete###
+ C++标准库含有的`string`和`vector`等`template`,可将数组的需求降至几乎为0
+ `new`中用`[]`,则`delete`中也要用`[]`


### Item 17: Store newd objects in smart pointers in standalone statements. ###
```cpp
int priority();
void processWidget(std::tr1::shared_ptr<Widget> pw, int priority);

//以下调用方式仍然可能会导致内存泄露
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
//不同与Java和C#,总是以特定次序完成函数参数的计算，c++编译器以怎样的方式完成函数参数的计算弹性是很大的。

//避免这类问题，以独立语句将newd对象置于智能指针中
std::tr1::shared_ptr<Widget> pw(new Widget);
processWidget(pw, priority());

// runnable src demo
#include <memory>
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;

class Widget {
    public:
        Widget(string name) : _name(name) {    }
        string getName() const { return _name; }
    private:
        string _name;
};

int priority() {
    return 2;
}

void processWidget(std::shared_ptr<Widget> pw, int priority) {
    cout << pw->getName() << endl;
}

int main() {
    std::shared_ptr<Widget> pw (new Widget("hello, shared_ptr!") );
    processWidget(pw, priority());
}

```
 + run it with -std=c++0x and get screen output "hello, shared_ptr!"

# Design and Declarations

### Item18: Make interfaces easy to use correctly and hard to use incorrectly
+ 明智而审慎地导入新类型对预防"接口被误用"有神奇疗效
+ 以`const`修饰`operator*`的返回类型可以阻止客户因“用户自定义类型"而犯错，如将`if (a * b == c)`写成` if (a * b = c)`时，编译会主动报错提示
+ 除非有好理由，否则应该尽量令你的types的行为同内置types行为一致
+ 任何接口如果要求客户必须记得做某些事情，就是有着"不正确使用"的倾向。（用智能指针把客户从“释放资源”这项任务中解脱）
 
### Item19: Treat class design as type design
+ Lots of things have to be considered before a good class designed !

### Item20: Prefer pass-by-reference-to-const to pass-by-value
+ 避免不必要的构造、析构
+ 以by reference方式传递参数也可以避免slicing(对象切割)问题
+ 以上规则不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，用pass-by-value比较适当。

### Item21: Don't try to return a reference when you must return an object
+ 像Rational的operator*而言，就是一种“必须返回新对象"的函数
```cpp
inline const Rational operator* (const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
```
+ 决不能返回pointer或reference指向一个local stack对象(error)，或返回reference指向一个heap-allocated对象(who would delete the resource),或返回一个pointer或reference指向一个local static对象而有可能需要多个这样的对象(This item gave us an example that would work wrong)。
+ error demo code for local static
```cpp
const Rational& operator*(const Rational& lhs, const Rational& rhs) {
	static Rational result;
	result = ...;
	return result;
}
bool operator==(const Rational& lhs, const Rational& rhs);
Rational a, b, c, d;
if ((a * b) == (c * d)) {
	// do something 
} else {
	// do else
}
// in this if code, ((a * b) == (c * d)) would always be true, because the return of local static reference!
```

### Item22: Declare data members private
+ 切记将成员变量声明为`private`。这可以赋予客户访问数据的一致性、可细微划分访问控制、允诺约束条件获得保证，并提供`class`作者以充分的实现弹性
+ `protected`并不比`public`更具有封装性；从封装的角度看，只有两种访问权限：`private`提供封装，其他不提供封装

### Item23: Prefer non-member non-friend functions to member functions
+ 愈多东西被封装，我们改变那些东西的能力就愈大，推崇封装的原因是：它使我们可以改变事物而只影响有限客户
+ 在`member function`和`non-member non-friend function`中，后者导致更大封装性，因为它不会增加“能够访问`class`内之`private`成分的函数数量。
+ 将类以及类相关的`non-member non-friend function`放入同一个`namespace`中
```cpp
namespace WebBrowserStuff {
	class WebBrowser { ... };
	void clearBrowser(WebBrowser& wb);
	...
}
```

### Item24: Declare non-member functions when type conversions should apply to all parameters
+ 令classes支持隐式类型转换通常是个糟糕的注意。最常见的例外就是在建立数值类型时
+ 只有当参数被列于参数列内，这个参数才是隐式类型转换的合格参与者。地位相当于"被调用之成员函数所隶属的那个对象"-即this对象-的那个隐喻参数，绝不是隐式转换的合格参与者。
+ member函数的反面是non-member函数，而不是friend函数。无论何时如果你可以避免使用friend函数就应该避免，因为就像真实世界一样，朋友带来的麻烦往往多过价值。

### Item25: Consider support for a non-throwing swap.
+ 缺省情况下swap动作可由标准程序库提供的swap算法完成
```cpp
namespace std {
	template<typename T>
	void swap(T& a, T& b) {
		T temp(a);
		a = b;
		b = temp;
	}
}
```
+ 为了提供swap效率，用"pimpl(pointer to implementation)手法"
+ 以下代码已经很好地完成我们想要的高效swap功能
```cpp
class WidgetImpl {
public:
	...
private:
	int a, b, c;
	std::vector<double> v;
	...
};
class Widget {
public:
	Widget(const Widget& rhs);
	Widget operator=(const Widget& rhs) {
		...
		pImpl = rhs.pImpl
		...
	}
	void swap(Widget& other) {
		using std::swap;
		swap(pImpl, other.pImpl);
	}
private:
	WidgetImpl* pImpl;
};	
namespace std {
	template<>
	void swap<Widget>(Widget& a, Widget& b) {
		a.swap(b);
	}
}
```
+ 但是如果Widget和WidgetImpl都是`class template`而非`class`时，我们该如何完成
```cpp
//错误，因为C++只允许对class template进行偏特化，在function templates身上偏特化是不行的
namespace std {
	template<typename T>
	void swap< Widget<T> >(Widget<T>& a, Widget<T>& b) {
		a.swap(b);
	}
}
```
+ 正确做法：当你想偏特化一个`function template`时,惯常做法是为它添加一个重载版本,但是注意std是个特殊的命名空间，客户可以全特化`std`的`template`,但不可以添加新的`templates`到`std`里头。代码如下：
```cpp
namespace WidgetStuff {
    template<typename T>
    class WidgetImpl { ... };
    
	template<typename T>
	class Widget { ... };  //同前，含有swap成员函数

	template<typename T>
	void swap(Widget<T>& a, Widget<T>& b) {
		a.swap(b);
	}
```
+ C++的名称查找法则确保将找到global作用域或T所在之命名空间内的任何T专属的swap.如果T是Widget并位于命名空间WidgetStuff内，编译器会使用“实参取决之查找规则"(argument-dependent lookup)找到WidgetStuff的swap.如果没有T专属的swap存在，编译器就使用std内的swap(因为using std::swap让其在函数曝光),然而即便如此，编译器还是比较喜欢std::swap的T专属特化版，而非一般的那个template.

# Implementation

### Item 26: Postpone variable definitions as long as possible
+ 延后变量的定义，知道非得使用该变量的前一刻为止，甚至应该尝试延后这份定义直到能够给他初值实参为止。这样就能够避免无意义的default构造行为。Item4解释了"通过default构造函数构造出一个对象然后对它赋值"比"直接在构造时指定初值"效率差。
+ 比较一下A和B两种方法
```cpp
// A
Widget w;
for (size_t i = 0; i < n; ++i) {
	w = ...;
}

// B
for (size_t i = 0; i < n; ++i) {
	Widget w(...);
}
```
+ 除非（1）直到赋值成本比“构造+析构”成本低（2）正在处理代码中效率高度敏感的部分，否则应该使用B.

### Item27: Minimizing casting
+ `const_cast dynamic_cast reinterpret_cast static_cast`
+ 转型代码用错案例一
```cpp
class Window {
public:
	virtual void onResize() { ... }
};
class SpecialWindow : public Window {
public:
	virtual void onResize() {
		static_cast<Window>(*this).onResize(); //将*this转型为Window，然后调用其onResize，这样不可行
	}
};
```
+ 上面代码是在"当前对象base class成分"的**副本**上调用onResize
+ 修改如下：
```cpp
class SpecialWindow : public Window {
public:
	virtual void onResize() {
		Window::onResize(); //调用Window::onResize作用于*this身上
	} 
```
+ 尽量少用`dynamic_cast`,因为执行速度是相当慢的。正确的替代办法
	+ 使用类型安全容器
	+ 将`virtual`函数往继承体系上方移动
+ 代码展示
```cpp
class Window { ... };
class SpecialWindow : public Window {
public:
	void blink();
};
typedef std::vector<std::shared_ptr<Window> > VPW;
VPW winPtrs;
for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter) {
	if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(iter->get())
		psw->blink();
}
// The first way to improve
typedef std::vector<std::shared_ptr<SpecialWindow> > VPSW;
VPSW winPtrs;
for (VPSW::iterator it = winPtrs.begin(); it != winPtrs.end(); ++it)
	(*it)->blink();
// The second way to improve
class Window {
public:
	virtual void blink() { }
};
class SpecialWindow {
public:
	virtual void blink() { }
}
typedef std::vector<std::shared_ptr<Window> > VPW;
VPW winPtrs;
for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter) 
	(*iter)->blink();
```
+ 绝对要避免"连串(cascading)`dynamic_casts`",如下,这种代码应该**总是用"基于`virtual`函数调用的东西取代"**
```cpp
class Window { ... };
class SpecialWindow1 : public Window { ... };   // derived class
typedef std::vector<std::shared_ptr<Window> > VPW;
VPW winPtrs;
for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter) {
	if (SpecialWindow1 *psw1 = 
			dynamic_cast<SpcialWindow1*>(iter->get())) { ... }
	else if (SpecialWindow2 *psw2 =
			dynamic_cast<SpcialWindow2*>(iter->get())) { ... }
	...
```
+ 总结：优良的C++代码很少用转型，尤其是要在注重效率的代码中避免`dynamic_cast`，如果要用转型，也尽量用C++-style的新式转型，而不要使用旧转型。

### Item28: Avoid returning "handles" to object internals
+ 反例1
```cpp
class Point {
public:
	Point(int x, int y);
	void setX(int newVal);
	void setY(int newVal);
};
struct RectData {
	Point ulhc;
	Point lrhc;
};
class Rectangle {
public:
	Point& upperLeft() const { return pData->ulhc; }
	Point& lowerRight() const { return pData->lrhc; } 
private:
	std::shared_ptr<RectData> pData;
};
```
+ 显然上面的`upperLeft()`和`lowerRight()`函数返回`handle`是有问题的，因为在外面拿到`Point&`之后是可以修改内部数据的，这也是bitwise constness的一个附带结果。
+ 解决办法如下
```cpp
class Rectangle {
public:
	const Point& upperLeft() const { return pData->ulhc; }
	const Point& lowerRight() const { return pData->lrhc; }
};
```
+ 但是还有更严重的问题，返回“handles"可能会导致dangling handles
+ 反例2
```cpp
class GUIObject { ... };
const Rectangle boundingBox(const GUIObject& obj);

GUIObject* pgo;
const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft());
//上述代码产生之后，pUpperLeft会变成空悬的指针。
```
+ 避免返回handles（包括references、指针、迭代器）指向对象内部。遵守这个条款可以增加封装性，帮助`const`成员函数表现的像个`const`,并将发生"dangling handles"的几率降至最低。


### Item29: Strive for exception-safe code
+ 当异常抛出时，带有异常安全性的函数会：
	+ 不泄露任何资源（用"资源管理类"解决）
	+ 不允许破坏数据
+ 异常安全函数（Exception-safe function)提供以下三个保证之一：
	+ 基本承诺
	+ 强烈保证
	+ 不抛掷保证
+ 强烈保证往往能够以copy-and-swap实现出来

### Item30: Understand the ins and outs of inlining
+ 没有免费的午餐，`inline`函数背后的整体观念是，将”此函数的调用“都以函数本体代替，很显然这会导致目标码膨胀
+ `inline`是个申请，编译器可以忽略。
的调用会使`inlining`落空。因为`virtual`意味着"等待，直到运行期才能确定调用哪个函数，`inline`意味"执行前，先将调用动作替换为被调用函数的本体”
	+ 如果程序要取某个`inline`函数的地址，编译器通常必须为此函数生成一个outlined函数
	+ 编译器拒绝为太复杂（带有循环和递归）的函数`inlining`
+ 将大多数`inlining`限制在小型、被频繁调用的函数身上。
+ 实际上，构造函数和析构函数往往是`inlining`的糟糕候选人，虽然有时你很方便的就这么做了（比如空的构造函数）。

### Item31: Minimize compilation dependencies between files
+ 将接口与实现分离
+ Handle class
```cpp
#include <string>
#include <memory>

class PersonImpl;
class Date;
class Address;

class Person {
public:
	Person(const std::string& name, const Date& birthday, const Address& addr);
	std::string name() const;
	std::string birthDate() const;
	std::string address() const;
private:
	std::shared_ptr<PersonImpl> pImpl;
};
```
+ Implementation Code
```cpp
#include "Person.h"
#include "PersonImpl.h"

Person::Person(const std::string& name, const Date& birthday, const Address& addr)
	: pImpl(new PersonImpl(name, birthday, addr) { }

std::string Person::name() const {
	return pImpl->name();
}
```
+ 在以上实现代码中，Person的客户就完全和Date,Address,Person的实现细节分离了。那些classes的任何实现修改都不需要Person客户重新编译了。
 + 如果使用object reference或object pointer可以完成任务，就不要使用object
 + 如果能够，尽量以class声明式替换class定义式
 + 为声明式和定义式提供不同的头文件
+ Interface class
```cpp
class Person {
public:
	static std::shared_ptr<Person> create(const std::string name,
		const std::string birthday,
		const std::string address);
	virtual ~Person();
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
	virtual std::string address() const = 0;
};
```
+ 具象的derived class来实现继承而来的virtual函数
```cpp
class RealPerson : public Person {
public:
	RealPerson(const std::string& name, const Date& birthday, const Address& addr)
		: theName(name), theBirthDate(birthday), theAddress(addr) { }
	virtual ~RealPerson() { }
	std::string name() const;
	std::string birthday() const;
	std::string address() const;
private:
	std::string theName;
	Date theBirthDate;
	Address theAddress;
};
```
+ 则Person的createPerson实现细节就如下
```cpp
std::shared_ptr<Person> Person::createPerson(const std::string& name,
	const Date& birthday, 
	const Address& addr) {
	return std::shared_ptr<Person>(new RealPerson(name, birthday, addr);
}
```


# Inheritance and Object-Oriented Design

### Item32: Make sure public inheritance models "is-a"
+ 好的接口可以防止无效的代码通过编译，因此你应该宁可采取"在编译期拒绝企鹅飞行"的设计，而不是"只在运行期才能侦测它们"的设计
+ public继承主张，能够施行于base class对象身上的**每件事情**，也可以施行于derived class对象身上！

### Item33: Avoid hiding inherited names
+ C++的名称遮掩规则（name-hiding rules)所做的唯一一件事情：遮掩名称。至于其他(参数类型，函数返回类型，函数是否virtual),并不重要。
+ derived classes内的名称会遮掩base classes内的名称。在public继承下从来没有人希望如此。
+ 为了让遮掩的名称再见天日，可使用using声明式或转交函数(forwarding functions)

### Item34: Differentiate between inheritance of interface of implementation
+ 声明一个`pure virtual`函数的目的是为了让`derived classes`只继承函数接口。（但是注意：`pure virtual`函数可以有定义的）
+ 声明简朴的`impure virtual`函数的目的，是为了让`derived classes`继承该函数的接口和缺省实现
+ 切断"`virtual`函数接口"和"缺省实现"之间的连接
```cpp
class Airplane {
public:
	virtual void fly(const Airport& destination) = 0;
};
void Airplane::fly(const Airport& destination) { 
	// pure function implementation 
}
class ModelA : public Airplane {
public: 
	virtual void fly(const Airport& destination) {
		Airplane::fly(destination);
	}
};
class ModelB : public Airplane {
public:
	virtual void fly(const Airport& destination) {
		Airplance::fly(destination);
	}
};
class ModelC : public Airplane {
public:
	virtual void fly(const Airport& destination) {
		// implementation from ModelC
	}
};
```
+ 声明`non-virtual`函数的目的是为了令derived classes继承函数接口及一份强制性实现

### Item35: Consider alternatives to virtual functions
+ **目标：**不同人物以不同的方式来计算健康指数
+ 最传统的方法
```cpp
class GameCharacter {
public:
	virtual int healthValue() const;
};
```
+ 藉由Non-Virtual Interface手法实现**Template Method**模式
	+ 令客户通过public non-virtual 成员函数间接调用private virtual函数，称为non-virtual interface(NVI)手法,是所谓**Template Method设计模式**的一个独特表现方式。
```cpp
class GameCharacter {
public:
	int healthValue() const {
		//...
		int retVal = doHealthValue();
		//...
		return retVal;
	}
private:
	virtual int doHealthValue() const {
		//...
	}
};
```
* 藉由Function Pointers实现**Strategy模式**
```cpp
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);
class GameCharacter {
public:
	typedef int (*HealthCalcFunc)(const GameCharacter&);
	explicit GameCharacter(HealthCalcFunc hcf = defaltHealthCalc) :
		healthFunc(hcf) { }
	int healthValue() const { return healthFunc(*this); }
private:
	HealthCalcFunc healthFunc;
};
```
* 藉由tr1::function完成**Strategy模式**
```cpp
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);
class GameCharacter {
public:
	typedef std::tr1::function<int (const GameCharacter&)> HealthClcFunc;
	explicit GameCharacter(HealthCalcFunc hcf = defaltHealthCalc) :
		healthFunc(hcf) { }
	int healthValue() const { return healthFunc(*this); }
private:
	HealthCalcFunc healthFunc;
};
```
+ 古典**Strategy模式**
```cpp
class GameCharacter;
class HealthCalcFunc {
public:
	virtual int calc(const GameCharacter& gc) const { ... }
};

HealthCalcFunc defaultHealthCalc;
class GameCharacter {
public:
	explicit GameCharacter(HealthCalcFunc& phcf = &defaultHealthCalc) :
		pHealthCalc(phcf) { }
	int healthValue() const { return pHealthCalc->calc(*this); }
private:
	HealthCalcFunc* pHealthCalc;
};
```

### Item36: Never redefine an inherited non-virtual function
+ `Non-virtual function`都是静态绑定的！一旦子类重新定义`Non-virtual`函数，会出现同样的一个对象因为赋给不同的类型（比如把子类的指针赋给父类），从而导致不同的函数调用，形同精神分裂！

### Item37: Never redefine a function's inherited default parameter value
+ `virtual`函数系动态绑定(dynamically bound),而缺省参数值却是动态绑定(statically bound)
+ 正确的代码格式(NVI)
```cpp
class Shape {
public :
	enum ShapeColor { Red, Green, Blue };
	void draw(ShapeColor color = Red) const {
		doDraw(color);
	}
private :
	virtual void doDraw(ShapeColor color) const = 0;
};
class Rectangle : public Shape {
public :
private :
	virtual void doDraw(ShapeColor color) const;
}
```
+ 由于Item36已经说过，non-virtual函数绝对不能被derived classes覆写，这个设计就可以很清楚地使得draw函数的color缺省值总是Red.

### Item38: Model "has-a" or "is-implemented-in-terms-of" through composition
+ 实现一个“空间比速度更重要"的Set类
+ 比较拙劣的想法
```cpp
template<typename T>
class Set: public std::list<T> { ... };
```
+ 上面的做法之所比较拙劣，是因为set "is-not-a" list,因为list可以有重复元素，但是set不行，而public继承的含义就是"is-a"!
+ 正确的做法用“复合”
```cpp
template<class T>
class Set {
public:
	bool member(const T& item) const;
	void insert(const T& item);
	void remove(const T& item);
	std::size_t size() const;
private:
	std::list<T> rep;
}
```

### Item39: Use private inheritance judiciously ###
+ 由`private base class`继承而来的所有成员，在derived class中都会变成`private`属性,所以`private`继承意味着implemented-in-terms-of而不是is-a关系
+ 尽量用复合，必要时（当要访问`protected`成员和重写`virtual`函数时)才使用`private`继承，无论什么时候，只要可以，你还是应该选择复合
```cpp
class Timer {
public:
	explicit Timer(int tickFrequency);
	virtual void onTick() const;
};
// one way 
class Widget : private Timer {
private:
	virtual void onTick() const;
}
// another way using composition
class Widget {
private:
	class WidgetTimer: public Timer {
	public:
		virtual void onTick() const;
	};
	WidgetTimer timer;
};
```

### Item40: Use multiple inheritance judiciously
+  多重继承会带来“歧义性”（如果多个类中存在相同名字的函数或变量）
+ 有时，还会有`virtual base class`的需求,而`virtual base class`继承会增加大小、速度、初始化（及赋值）复杂度等等成本。如果`virtual base classes`不带任何数据，将是最具实用价值的情况（因为`virtual base class`的初始化责任是由继承体系中的最底层负责的）。
+ 一般而言“单一继承方案几乎一定是更受欢迎的”
+ 当然，多重继承也有正当用途，其中一个情节就是"`public` 继承某个`Interface class`"和"`private`继承某个协助实现的`class`"



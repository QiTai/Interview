# Note

### C++对象内存分配(考虑虚函数，虚继承)
+ [C++对象内存模型](http://www.cnblogs.com/kekec/archive/2013/01/27/2822872.html)
+ [C++中虚函数工作原理和(虚)继承类的内存占用大小计算](http://blog.csdn.net/hackbuteer1/article/details/7883531)
+ [2013亚马逊面试题--虚继承的内存模型分析](http://blog.csdn.net/wangqiulin123456/article/details/8059536)

### Miscellany
+ exception

> If a function throws an exception not listed in its exception specification, the function unexpected(), defined in the C++ standard library, is invoked. The default behavior of unexpected() is to call terminate(). (In some situations, it may be necessary to override the actions performed by unexpected(). The C++ standard library provides a mechanism to override the default behavior of unexpected(). [STROUSTRUP97] discusses this in more detail.)

+ iomanip
```cpp
#inlcude <iomanip>
int main() {
    int n;
	std::cin >> n;								// INPUT 21
	std::cout << n << ' '						// PRINT 21
		<< std::hex << n << ' '					// PRINT 15
		<< std::dec << n << ' '					// PRINT 21
		<< std::oct << n << ' '					// PRINT 25
		<< std::setbase(10) << n << std::endl;	// PRINT 21
    return 0;
}
```
+ namespace
```cpp
namespace { static int n; }

namespace A {
	namespace { static int n; }
}
using namespace A;

int main() {
	::n = 5;	// ERROR
	n = 5;		// ERROR

	return 0;
}
```
+ sort on array
```cpp
    int a[] = { 4, 5, 2, 10, 9 };
	std::sort(a, a + 5);
	std::copy(a, a + 5, std::ostream_iterator<int>(std::cout, " ")); // PRINT 2 4 5 9 10
```
+ const 
```cpp
    int a = 2;
	int b = 3;
	const int *p(&a);
	p = &b;					// OK
	//*p = b;				// ERROR
	
	int *const p2(&a);
	*p2 = b;				// OK
	//p2 = &b;				// ERROR

	const int *const p3(&a);
	//p3 = &b;				// ERROR
	//*p3 = &b;				// ERROR
```
+ [reverse_iterator::base()](http://stackoverflow.com/questions/16609041/c-stl-what-does-base-do)
```cpp
    std::vector<int> myvector;
	for (int i = 0; i<10; i++) myvector.push_back(i);

	typedef std::vector<int>::iterator iter_type;

	std::reverse_iterator<iter_type> rev_end(myvector.begin());
	std::reverse_iterator<iter_type> rev_begin(myvector.end());

	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "==========================" << std::endl;
	// PRINT  0 1 2 3 4 5 6 7 8 9

	for (std::reverse_iterator<iter_type> it = myvector.rbegin(); it != myvector.rend(); it++) // mind : it++ not it--
		std::cout << ' ' << *it;
	std::cout << '\n';
	// PRINT  9 8 7 6 5 4 3 2 1 0

	std::cout << "==========================" << std::endl;
	std::vector<int> v1{ 0, 1, 2, 3, 4 };
	auto i = find(begin(v1), end(v1), 2);

	std::cout << *i << std::endl;						// PRINT 2

	std::reverse_iterator<decltype(i)> ri(i); 
	std::cout << *ri << std::endl;						// PRINT 1
	std::cout << *(ri.base()) << std::endl;				// PRINT 2

	auto j = v1.begin();
	std::reverse_iterator<decltype(j)> rj(j);
	//std::cout << *rj << std::endl;					// ERROR
	std::cout << *(rj.base()) << std::endl;				// PRINT 0

	std::cout << "==========================" << std::endl;

	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	std::cout << *(std::find(v.rbegin(), v.rend(), 2)) << std::endl;                // PRINT 2
	std::cout << *(std::find(v.rbegin(), v.rend(), 2).base()) << std::endl;;		// PRINT 3
	v.erase(std::find(v.rbegin(), v.rend(), 2).base());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));		// PRINT 0 1 2 4
	std::cout << std::endl;
	std::cout << *(std::find(v.rbegin(), v.rend(), 1)) << std::endl;				// PRINT 1
	cout << *(std::find(v.rbegin(), v.rend(), 1).base()) << endl;					// PRINT 2
	v.insert(std::find(v.rbegin(), v.rend(), 1).base(), 10);
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));		// PRINT 0 1 10 2 4
	std::cout << std::endl;
```
+ [STL Algorithm](http://en.cppreference.com/w/cpp/algorithm)
+ [functional](http://www.cplusplus.com/reference/functional/)
+ [How to choose between map and unordered_map?](http://stackoverflow.com/questions/13799593/how-to-choose-between-map-and-unordered-map)
+ derived class重新定义继承而来的private virtual函数，参考Herb Sutter [virtuality](http://www.gotw.ca/publications/mill18.htm)
+ 对父类的同名函数的访问：
	* base class name::访问基类同名函数或属性（*而Java中可以用super,C#中可以用base*）
+ 继承:
	* 实现机理：内存中包含了父类的所有内容（*除了虚函数*）
+ C++空类中自动创建的函数：
  * 缺省构造函数、拷贝构造函数、赋值运算符、析构函数、取址运算符
+ default constructor: consts and references must be initialized, so a class including them cannot be default-constructed unless explicitly supply constructor.

  ```C++
  struct X {
	  const int a;
	  const int& r;
  }
  X x; //error
  ```
+ An classical bug related to operato= returing object rather than reference
 ```C++
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class B {
public:
	B() { _array_ptr = NULL; }
	B(int h) {
		_h = h; 
		_array_ptr = new int[h]; 
		memset(_array_ptr, 111, _h * sizeof(int));
	}
	B(const B& rhs) : _h(rhs._h) {
		// error : because here _array_ptr may be any value that's originally in memory (not equal NULL), but this does not mean _array_ptr has been allocated memory!
		// so when use memcpy to a non-allocated _array_ptr, there will be errors;
		if (_array_ptr == NULL)
			_array_ptr = new int[rhs._h];
		else
			cout << _array_ptr << endl;
		memcpy(_array_ptr, rhs._array_ptr, _h * sizeof(int));
	}
	B operator=(const B& rhs) {
		_h = rhs._h;
		if (_array_ptr == NULL)
			_array_ptr = new int[_h];
		memcpy(_array_ptr, rhs._array_ptr, _h * sizeof(int));
		return *this;
	}
	~B() { 
		if (_array_ptr != NULL) 
			delete[] _array_ptr; 
	}

private:
	int _h;
	int *_array_ptr;
};
class A {
public:
	A(int a) {
		B tmp(3);
		b = tmp;
	}
private:
	B b;
	int _a;
};

int main() {
	A a(5);
	return 0;
}
 ```

+ Move Semantics
 * [C++11 Tutorial: Introducing the Move Constructor and the Move Assignment Operator](http://blog.smartbear.com/c-plus-plus/c11-tutorial-introducing-the-move-constructor-and-the-move-assignment-operator/)

 * [Move semantics and rvalue references in C++11](http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)*这篇文章写的很好*
     + 从函数中返回的值变量可以赋给const reference,但是不能赋给refrenece
	  ```cpp
	  string getName() {
	     return "Alex";
	  }
	
	  int main() {
	     const string& name = getName(); // OK
	     string & name = getName();      // Not OK
             
         const string&& name = getName(); //OK
         string&& name = getName(); //also OK
	  }
	  ```
     + Move constructor and move assignment operator
     ```cpp
     class ArrayWrapper {
     	public:
       		//move constructor
           ArrayWrapper(ArraWrapper && other)
           	: _p_vals(other._p_vals)
            , _size(other.size) {
            	other._p_vals = NULL;
                other._size = 0;
            }
        private:
        	int * _p_vals;
            int _size;
     };
	
		
     ```
     + **std::move** *change lvalue to rvalue, in order to call move constructor instead of copy constructor*
     ```cpp
	 ArrayWrapper (ArrayWrapper &&other)
		 : _p_vals(other._p_vals)
		 , _metadata(std::move(other._metadata)) {
			other._p_vals = NULL;
		}
     ```
+ Boost Library Usage
	* VS2012
		+ 下载boost包
		+ 将工程属性->C/C++->常规->附加包目录中添加下载的boost包所在目录
		+ 在cpp或h文件`include <boost/lexical_cast.hpp>`
	* Linux
		+ 下载boost包
        + 在cpp或h文件`include <boost/lexical_cast.hpp>`
		+ 在编译的时候在命令中添加`-I/home/charles/Software/boost_1_59_0/`,全部命令为
		`g++ -o boost_practice boost_practice.cpp -I/home/charles/Software/boost_1_59_0/` 


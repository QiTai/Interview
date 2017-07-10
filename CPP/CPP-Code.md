# Excellent C++ Code!

+ C++ support for heap

  + one way use **priority_queue**

    ```cpp
    // Interview 剑指Offer-64:数据流中的中位数
    class Solution {
    public:
        void Insert(int num) {
            if ( ((minHeap.size() + maxHeap.size()) & 1) == 0) {
                if (maxHeap.size() > 0 && num < maxHeap.top()) {
                    maxHeap.push(num);
                    num = maxHeap.top();
                    maxHeap.pop();
                }
                minHeap.push(num);
            } else {
                if (minHeap.size() > 0 && num > minHeap.top()) {
                    minHeap.push(num);
                    num = minHeap.top();
                    minHeap.pop();
                }
                maxHeap.push(num);
            }
        }
        double GetMedian() {
            int size = minHeap.size() + maxHeap.size();

            double median = 0;
            if ((size & 1) == 1) {
                median = minHeap.top()
            } else {
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            return median;
        }
    private:
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
    };
    ```

  + one way use **make_heap, push_heap, pop_heap** 

    ```cpp
    // Interview 剑指Offer-64:数据流中的中位数
    class Solution {
    public:
        void Insert(int num)
        {
            if (((min.size() + max.size()) & 1) == 0) {
                if (max.size() > 0 && num < max[0]) {
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<int>());
                     
                    num = max[0];
                    pop_heap(max.begin(), max.end(), less<int>());
                    max.pop_back();
                }
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
            } else {
                if (min.size() > 0 && min[0] < num) {
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<int>());
                     
                    num = min[0];
                     
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back();
                }
                 
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
            }
        }
     
        double GetMedian()
        {
            int size = min.size() + max.size();
             
            double median = 0;
            if ((size & 1) == 1)
                median = min[0];
            else
                median = (min[0] + max[0]) / 2.0;
             
            return median;
        }
    private:
        vector<int> min;
        vector<int> max;
     
    };
    ```

    ​

+ beautiful way to get words from a ' \n\t' seperated string.
```c++
string str("dog\tcat\ncat dog");
string word;
std::istringstream strstream(str);
for (; strstream >> word; ) {
	cout << word << endl;
}
```

+ memset/memcpy
```c++
memset(_pIndx, 0, (nCol + 1) * sizeof(int));
memcpy(_PIndx, rhs._pIndx, (_nCol + 1)*sizeof(int));
```

+ split a string by a delim, and return a vector of strings containing no delim
```C++
// 1. Using stringstream getline
// NOTE: this solution does not skip empty tokens, so the following will find 4 items, one of which is empty;
// std::vector<std::string> x = split("one:two::three", ':');
vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

// 2. Using string's find function
// Need to be careful when using substr to truncate the tokens
void split(const string& s, char delim, vector<string>& v) {
	auto i = 0;
	auto pos = s.find(delim);
	while (pos != string::npos) {
		v.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == string::npos) {
			v.push_back(s.substr(i, s.length()));
		}
	}
}

// 3. Use std::strtok
// char* strtok(char* str, const char* delim); 
// return a pointer to the begining of the next token or NULL if there are no more tokens.
void split(const string& s, const char* delim, vector<string>& v) {
	// to avoid modifying original string
	// first duplicate the original string and return a char pointer then free the memory
	char *dup = strdup(s.c_str());
	char *token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		token = strtok(NULL, delim);
	}
	free(dup);
}

// 4. Use boost tokenizer
```

+ string hex2bin and bin2hex

```cpp
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
//#include <boost/algorithm/string.hpp>

using namespace std;

const unsigned g_unMaxBits = 32;

string Hex2Bin(const string& s)
{
	stringstream ss;
	ss << hex << s;
	unsigned n;
	ss >> n;
	bitset<g_unMaxBits> b(n);

	unsigned x = 0;
	
	// way I: boost way
	//if (boost::starts_with(s, "0x") || boost::starts_with(s, "0X")) x = 2;
	
	// way II: substr
	if (s.substr(0, 2) == "0x" || s.substr(0, 2) == "0x")
		x = 2;

	// way III: 
	//if (strncmp(s.c_str(), "0x", 2) == 0 || strncmp(s.c_str(), "0X", 2) == 0)
	//	x = 2;

	return b.to_string().substr(32 - 4 * (s.length() - x));
}


string Bin2Hex(const string& s)
{
	bitset<g_unMaxBits> bs(s);
	unsigned n = bs.to_ulong();
	stringstream ss;
	ss << hex << n;

	// way I: boost
	//return "0x" + boost::to_upper_copy(ss.str());

	// way II: transform + toupper
	string res = ss.str();
	std::transform(res.begin(), res.end(), res.begin(), ::toupper);

	return "0x" + res;
}

int main() {
	cout << "0xA1 => " << Hex2Bin("0xA1") << endl;
	cout << "B3 => " << Hex2Bin("B3") << endl;
	cout << "11110001 => " << Bin2Hex("11110001") << endl;

	return 0;
}
```
+ Int2Str, Str2Int, Float2Str, Str2Float 

```C++
//----------------------string2double---------------------- 
//Best: C++ 11 feature
#include <string>
double string2double(const string& stringNum) {
	return std::stod(stringNum);
}

//I : use atof (C function)
#include <stdlib.h>
double string2double(const string& stringNum) {
	double tmp;
	return atof(stringNum.c_str());
}

//II : use stringstream
#include <stringstream>
using std::stringstream
double string2double(const string& stringNum) {
	double tmp;
	stringstream stream(stringNum);
	stream >> tmp;
	return tmp;
}

//III: use boost
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
double string2double(const string& stringNum) {
	return lexical_cast<double>(stringNum);
}


//-------------------float2string---------------------------
//I: C++ 11 feature
#include <string>
string float2string(float val) {
	return std::to_string(val);
}

//II : boost
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
string float2string(float val) {
	return lexical_cast<string>(val);
}

//I : use stringstream, unless you're worried about performance
string float2string(float val) {
	std::stringstream ss;
	ss << val;
	string s(ss.str());
	return s;
}



//------------------string2int--------------------------------
//I : stoi c++11 feature
int string2int(const string& stringNum) {
	return std::stoi(stringNum);
}

//II : atoi (C function)
#include <stdlib.h>
int string2int(const string& stringNum) {
	return atoi(stringNum.c_str());
}

//III : stringstream; same string2double


//-------------------int2string--------------------------------
//best way c++11 feature
#include <string>
string int2string(int val) {
	string numStr = std::to_string(val);
	return numStr;
}

//II : use stringstream; same as float2string
string int2string(int val) {
	stringstream ss;
	ss << val;
	return ss.str();
}

// In C: we can use sprintf, just like the following
char* str;
int num = 378;
sprintf(str, "%d", num);

//III : boost lexical_cast; same as float2string
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

//Bad idea : use itoa (got some problems)
//This function is not defined in ANSI-C and is not part of C++, but is supported by some compilers.
//But why would we use this, if we have better ways!!!
//According to my test: VC2012 support this function, but if we run it by "g++ -std=c++0x", we fail!
string int2string(int val) {
	char* intStr;
	itoa(val, intStr, 10)
	return string(intStr);
}
```

+ Miscellany

```C++
//-------------------for i---------------------------
for (std::size_t i = 0; i < 10; i++) //instead of int i;

//------------------string::size_type----------------
string str;
string::size_type  fig_end = str.find_first_not_of(delims);

//----------------------动态生成数组------------------
int N;
int* array = new int[N];

//--------------------nth_element---------------------
vector<int> vals;
for (size_t i = 0; i < 10; i++)
	vals.push_back(i);
std::random_shuffle (vals.begin(), vals.end());
std::nth_element (vals.begin(), vals.begin() + 5, vals.end());

//-------------------accumulate-----------------------
int titleToNumber(string s) {
    return accumulate(s.begin(), s.end(), 0, [](int num, char ch) { return num * 26 + ch - 'A' + 1; });
}

//------------------reverse vector---------------------
// Way I : reverse original vector
std::reverse(tmp.begin(), tmp.end());
// Way II : generate new reversed vector
vector<int> (tmp.rbegin(), tmp.rend());

//-------------------file stream----------------------
string filename;
ifstream ifid;
ifid.open(filename.c_str());
//equal, but the latter used oftern,since there is no reason to separate construction and open//
string filename;
ifstream ifid(filename.c_str());
//-----------------------------------------------------

//----------------typename----------------------------
//refer to http://pages.cs.wisc.edu/~driscoll/typename.html
typename std::vector<T>::iterator it;
typedef typename std::vector<T>::iterator iterator_type;
//in the above two examples, we all need typename;

//------------c++ private-------------------------------------
//同Java一样，c++的private也是针对类而言，即同类之间可以互相访问私有变量
//如下例---------Item.h--------------
#ifndef ITEM_H
#define ITEM_H

class Item {
public:
	Item(int val = 0): val(val) {}
	int addVal(const Item& a, const Item& b) const;
private:
	int val;
};

#endif

//--------------Item.cpp---------------
#include "Item.h"

int Item::addVal(const Item& a, const Item& b) const {
	return a.val + b.val;	//这里访问a的私有变量val是合法的。
}

//--------------Another way initialize vector----------
static const int arr[] = {16,2,77,29};
vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

//--------------Self-reference--------------
void f(Date &d) {
	//...
	d.add_day(1).add_month(1).add_year(1);
	//...
}

class Data {
	//...
	Data& add_day(int n) {
		//self-reference
		return *this;
	}

};

//-----------------Singleton-----------------
class Singleton {
public:
	static Singleton &GetInstance() {
		static Singleton instance;
		return instance;
	}
protected:
	Singleton();
	~Singleton();
};
Singleton& si = Singleton::GetInstance();

//--------------用于公共代码的私有函数-------------
//notice: 在普通的非const成员函数中，this的类型是一个指向类类型的const指针
//	  在const成员函数中，this的类型是一个指向const类类型的const指针
class Screen {
public:
	//display overloaded on whethere the object is const or not 
	Screen& display(std::ostream &os) { do_display(os);  return *this; }
	const Screen& display(std::ostream &os) const { do_display(os); return *this;}
private:
	void do_display(std::ostream &os) const { os << contents; }
};
```

+ About explicit

```C++
//-------------about explicit------------------
//Advice:除非有明显的理由想要定义隐式转换，否则，单形参构造函数应该为explicit.
class Sales_item {
public:
	explicit Sales_item(const std::string &book = "") : isbn(book), units_sold(0), revenue(0.0) { }
	explicit Sales_item(std::istream &is);
private:
	//...
};

//error: explicit allowed only on constructor declaration in class header
explicit Sales_item::Sales_item(istream& is) {
	is >> *this;
}

string null_book = "9-999-999";
item.same_isbn(null_book); 				//error: string constructor is explicit
item.same_isbn(Sales_item(null_book)); 	//right
```

+ About STL Algorithm
```cpp
lower_bound(nums.begin(), nums.end(), val): returns the iterator pointing to the first element which does not compare less than val;

upper_bound(nums.begin(), nums.end(), val): returns the iterator pointing 
to the first element which compares greater than val;

nth_element(nums.begin(), nums.begin() + v.size() / 2, nums.end()): paritial sorting algorithm that rearranges element such that all of the elements before nth element are less thatn or equal to the elements after the nth element.
```

+ About inline

```C++
//--------------about inline-------------------
//Three points: (1)inline函数必须要在头文件中定义
//				(2)在声明和定义中使用inline关键字均是合法的
//				(3)在类内部定义的成员函数，默认为inline.
class Screen {
public:
	typedef std::string::size_type index;
	//implicitly inline when defined inside the class declaration
	char get() const { return contents[cursor]; }
	//explicitly declared as inline; will be defined outside the class declaration
	inline char get(index ht, index wd) const;
	//inline not specified in class declarration, but can be defined inline later
	index get_cursor() const;
};

//inline declared in the class declaration; no need to repeat on the definition
char Screen::get(index r, index c) const {
	index row = r * width;
	return contents[row + c];
}

inline Screen::index Screen::get_cursor() const {
	return cursor;
}
```

+ About Overload

```C++
//--------------about iostream overload----------------
//Advice:   (1)所做的格式化尽量少；比如不要输出换行符
//			(2)IO操作符必须为非成员函数，一般设置为相关类的友元。（自己思考其中缘由）（非常经典的一个问题）
//general skeleton of the overloaded output operator
class Sales_item {
	friend std::istream& operator>>(std::istream&, Sales_item&);
	friend std::ostream& operator<<(std::ostream&, Sales_item&);
};

ostream& operator<<(ostream& os, const Sales_item &object) {
	//any special logic to prepare the logic
	
	//actual output of member
	os << s.isbn << "\t" << s.units_sold << "\t"

	//return ostream object
	return os;
}

istream& operator>>(istream& in, Sales_item& s) {
	double price;
	in >> s.isbn >> s.units_sold >> price;
	//check that the inputs succeeded 
	if (in) 
		s.revenue = s.units_sold * price;
	else
		s = Sales_item(); 					//input failed: reset object to default state;
	return in;
}

//===============================================================
//注意，为了和内置操作符保持一致，加法返回一个右值，而不是一个引用。

//================================================================
//赋值操作符和复合赋值操作符应返回左操作数的应用(*this).

//================================================================
//(1)下标操作符必须定义为成员函数
//(2)由于下标操作符既可以当做左值，又可以称为右值，所以返回值要是引用。
//(3)需要有const和非const两个版本
class Foo {
public:
	int &operator[] (const size_t);
	const int &operator[] (const size_t) const;
private:
	vector<int> data;
};

int& Foo::operator[] (const size_t index) {
	return data[index];								//no range checking on index
}

const int& Foo::operator[] (const size_t index) {
	return data[index];
}


//================================================================
//函数对象:定义了调用操作符的类

class GT_cls {
public:
	GT_cls(size_t val = 0): bound(val) { }
	bool operator() (const string &s) { return s.size() >= bound; }
private:
	std::string::size_type bound;
};

vector<string>::size_type wc = count_if(words.begin(), words.end(), GT_cls(6));
```


+ About Has Pointer 

```C++
//From C++ Primer page 419

//======================================================//
//!!!  Not Good Way  !!!
//class that has a pointer member that behaves like a plain pointer
class HasPtr {
public:
	HasPrt(int *p, int i): ptr(p), val(i) { }
	int *get_ptr() const { return ptr; }
	int  get_int() const { return val; }

	void set_ptr(int *p) { ptr = p; }
	void set_int(int  i) { val = i; }

	int get_prt_val() const { return *ptr; }
	void set_ptr_val(int val) const { *ptr = val; }
private:
	int *ptr;
	int  val;
};

//Advice: 具有指针成员且使用默认合成复制构造函数的类具有普通指针的所有缺陷，尤其是，类本身无法避免悬垂指针；

//========================================================//
//!!! Smart Pointer !!!
//private class for use by HasPtr only
//!!! Classical Way of Writing Pointer-used Counter Class  !!!
class U_Ptr {
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1) { }
	~U_Ptr() { delete ip; }
};

/* smart point class: takes ownership of the dynamically allocated object to which it is bound
 * User code must dynamically allocate an object to initialize a HasPtr and must not delete that object; 
 * the HasPtr class will delete it
 */
class HasPtr {
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }
	HasPtr(const HasPtr &orig): ptr(orig.ptr), val(orig.val) { ++ptr->use; }
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { if (--ptr->use == 0) delete ptr; }

	int *get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }
	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }
	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int i) { *ptr->ip = i; }

private:
	U_Ptr *ptr;
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	++rhs.ptr->use;
	if (--ptr->use == 0)
		delete ptr;
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}

//此种方法，副本和原对象仍指向同一基础对象，但是此时已经不用担心dangling pointer problem!!!

//Advice: 由上面阐述的问题可知：具有指针成员的对象一般需要定义复制控制成员，如果依赖合成版本，会有很多问题。

//========================================================//
// 定义值型类; //
/* Valuelike behavior even though HasPtr has a pointer member.
 * Each time we copy a HasPtr object, we make a new copy of the underlying int object to which ptr points.
 */
class HasPtr {
public:
	HasPtr(cosnt int &p, int i): ptr(new int(p)), val(i) { }
	HasPtr(const HasPtr &orig): ptr(new int (*orig.ptr)),  val(orig.val) { }
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ptr; }
private:
	int *ptr;
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	*ptr = *rhs.ptr;	//copy the value pointed to
	val = rhs.val;
	return *this;
}
```


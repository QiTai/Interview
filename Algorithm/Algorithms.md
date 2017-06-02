### Algorithms Related to Sort and Search
#### CountSort (refer to 剑指Offer)
```cpp
// NOTICE : this counting sort algo. is different with Intro to Algo. book.
void SortAges(int ages[], int length) {
	if (ages == NULL || length <= 0)
		return;
	const int oldestAge = 99;
	int timesOfAge[oldestAge + 1];

	for (int i = 0; i <= oldestAge; ++i) {
		timesOfAge[i] = 0;
	}

	for (int i = 0; i < length; ++i) {
		int age = ages[i];
		if (age < 0 || age > oldestAge)
			throw new std::exception("age out of range");
		++timesOfAge[age];
	}

	int index = 0;
	for (int i = 0; i <= oldestAge; ++i) {
		for (int j = 0; j < timesOfAge[i]; ++j) {
			ages[index] = i;
			++index;
		}
	}
}
```
#### QuickSort (refer to Introduction to Algorithms)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::for_each;

int partition(vector<int>& num, int p, int r) {
	int x = num[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (num[j] <= x) {
			i = i + 1;
			// exchange num[i] and num[j];
			int tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
		}
	}
	// exchange num[i + 1] and num[r]
	int tmp = num[i + 1];
	num[i + 1] = num[r];
	num[r] = tmp;
	return i + 1;
}

void quickSort(vector<int>& num, int p, int r) {
	if (p < r) {
		int q = partition(num, p, r);
		quickSort(num, p, q - 1);
		quickSort(num, q + 1, r);
	}
}

int main() {
	vector<int> num{ 2, 3, 8, 4, 9, 10, 123, 1, 11 };
	quickSort(num, 0, num.size() - 1);
	for_each(num.begin(), num.end(), [](int i) { cout << i << endl; });
	return 0;
}
```

### Algorithms Related to Bit Manipulation(位操作)
+ 在右移操作中，如果是有符号数，则用数字的**符号位**填补最左边的空白。（这在统计负数“二进制中1的个数”要特别注意）
+ 把一个整数减去1之后再与原来的整数做位与运算，得到的结果相当于将整数的二进制表示中的最右边的一个1变为0。这个规律很多地方都有用到!!!

### Algorithms Related to List(链表)
+ Refer to [List](https://github.com/QiTai/oldblog/blob/gh-pages/blog-src/blog/C/posts/25.mkd)
+ 双指针的方法用的很多！！！
+ fakeHead的技巧用的较多
+ 反转链表 (keep in mind)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	    ListNode* prev = NULL;
	    while (head != NULL) {
	        ListNode* next = head->next;
	        head->next = prev;
	        prev = head;
	        head = next;
	    }
	    return prev;
    }
};
```

### Algorithms Related to Tree(树) & Graph(图)
+ **recursive** algorithm is used mostly!!!

+ **stack, queue, deque** are mostly used as auxilary tool!!!

+ 二叉树中涉及大量的指针操作，每一次使用指针的时候，我们都要问这个指针有没有可能是NULL,如果是NULL该怎么办.(ROBUST)

+ 二叉树种的很多问题其实都可以转化为**层次遍历**来解决,例如 leetcode中如下题目
  + Maximum Depth of Binary Tree

  + Find Bottom Left Tree Value

  + Find Largest Value in Each Tree Row  

  + Diameter of Binary Tree

  + Serialize and Deserialize Binary Tree

  + 以Maximum Depth of Binary Tree为例,大致框架如下

    ```cpp
    class Solution {
    public:
        // no recursion, with one queue
        int maxDepth(TreeNode* root) {
            if (root == NULL)
                return 0;
            queue<TreeNode*> level;
            int depth = 0;
            level.push(root);
            while (!level.empty()) {
                int n = level.size();
                for (int i = 0; i < n; i++) {
                    TreeNode* front = level.front();
                    level.pop();
                    if (front->left) level.push(front->left);
                    if (front->right) level.push(front->right);
                }
                depth++;
            }
            return depth;
        }
    };
    ```

+ 树的（深度优先：前序、中序[Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)、后序[二叉树的非递归遍历](http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html)）、（广度优先：层次遍历）及其非递归方法

```cpp
void preOrder(TreeNode* root) {
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			cout << p->data << " ";
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

void inOrder(TreeNode* root) {
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->right;
		}
	}
}

void postOrder(TreeNode* root) {
	stack<TreeNode*> s;
	TreeNode* pre = NULL;
	TreeNode* cur;
	s.push(root);
	while (!s.empty()) {
		cur = s.top();
		if (cur->left == NULL && cur->right == NULL || (pre != NULL && (pre == cur->left || pre == cur->right))) {
			cout << cur->data << " ";
			s.pop();
			pre = cur;
		} else {
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
	}
}
```

+ 图的深度优先、广度优先搜索及其非递归方法

### Algorithms Related to Array

+ Find Mode in a vector(frequently used), such as leetcode
  +  [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree)   
  +  Most Frequent Subtree Sum
  +  基本思想：先**排序**，再对排序后的数组用以下算法;如果不用排序的话，就要用额外的Hashmap

  ```cpp
  vector<int> findModesInSortedVector(vector<int> nums) {
  	vector<int> res;
  	int max = 0, cur = 0, cnt = 0;
  	for (int i = 0; i < nums.size(); i++) {
  		cnt++;
  		if (nums[i] != cur) {
  			cur = nums[i];
  			cnt = 1;
  		}
  		if (cnt > max) {
  			max = cnt;
  			res.clear();
  			res.push_back(nums[i]);
  		} else if (cnt == max) {
  			res.push_back(nums[i]);
  		}
  	}
  	return res;
  }
  ```

+ Leetcode : 3Sum, 3Sum Closet, 4Sum思路类似(排序+双指针); Two Sum, 4Sum II思路类似(HashMap)

### Algorithms Related to String
#### [KMP](http://blog.csdn.net/v_july_v/article/details/7041827):用于寻找模式串P在文本串S中第一次出现的位置
+ next矩阵算法&KMP算法c++实现

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>

using std::endl;
using std::cout;
using std::string;
using std::vector;

vector<int> getNext(string str) {
	int n = str.size();
	vector<int> next(n + 1, -1);
	int i = 0, j = -1;
	while (i < n) {
		if (j == -1 || str[i] == str[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}

// next优化算法
vector<int> getNextNew(string str) {
	int n = str.size();
	vector<int> next(n + 1, -1);
	int i = 0, j = -1;
	while (i < n) {
		if (j == -1 || str[i] == str[j]) {
			++i;
			++j;
			// 改动之处
			if (str[i] != str[j])
				next[i] = j;
			else
			 	next[i] = next[j];
		}
		else {
			j = next[j];
		}
	}
	return next;
}

int KMPSearch(string str, string pattern) {
	vector<int> next = getNext(pattern);
	//next.pop_back();
	int i = 0, j = 0;
	int strLen = str.size(), patternLen = pattern.size();
	// NOTE: 在while内部不要用str.size(), pattern.size()作比较，这样负数会变成正数作比较
	while (i < strLen && j < patternLen) {
		if (j == -1 || str[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j = pattern.size())
		return i - j;
	else
		-1;
}

int main() {
	string str = "abcdabd";
	vector<int> next = getNext(str);
	for_each(next.begin(), next.end(), [](int a) { cout << a << "\t"; });
	cout << endl;

	string str = "abacababc";
	string pattern = "abab";
	cout << endl;
	cout << KMPSearch(str, pattern) << endl;
}
```

+ repeated substring pattern(leetcode)
+ shortest panlindrome(leetcode)
+ Implement strStr(leetcode)

#### Panlindrome
+ shortest panlindrome(leetcode)
+ Longest Palindromic Substring(leetcode) --- **Manacher's Alg.**
+ Longest Palindromic Subsequences(leetcode) --**Dynamic Programming**

#### string to int (Leetcode)
##### 主要考察点
+ 字符串前的空格
+ 字符+-
+ 溢出
+ 异常字符串(如空字符;只含+-的字符串)
```cpp
// wayI : leetcode
class Solution {
public:
	int myAtoi(string str) {

		size_t i = 0;
		bool minus = false;
		int sum = 0;

        // handle with space character
		for (; i < str.size(); ++i) {
			if (str[i] == ' ')
				continue;
			else
				break;
		}

        // handle with '+' or '-' character
		if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
			minus = str[i] == '-' ? true : false;
			++i;
		}

		for (; i < str.size(); ++i) {
			if (isdigit(str[i])) {
				// handle with overflow
				if (sum > INT_MAX / 10 || sum == INT_MAX / 10 && str[i] - '0' > 7)
					return minus ? INT_MIN : INT_MAX;
				else sum = sum * 10 + (str[i] - '0');
			}
			else break;
		}
		return minus ? -sum : sum;
	}
};
// wayII: 剑指Offer 面试49
enum Status { kValid = 0, kInvalid };
int g_nStatus = kValid;
int StrToInt(const char* str) {
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != NULL && *str != '\0') {
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-') {
			str++;
			minus = true;
		}
		if (*str != '\0') {
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}

long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;
	while (*digit != '\0') {
		if (*digit >= '0' && *digit <= '9') {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)
				|| (minus && num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			digit++;
		}
		else {
			num = 0;
			break;
		}
	}
	if (*digit == '\0') {
		g_nStatus = kValid;
	}
	return num;
}
```

#### string to float (written by me)
```cpp
#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

float myAtof(string str) {

	// negelct all the spaces
	int i = 0;
	for (; i < str.size(); i++) {
		if (str[i] == ' ')
			continue;
		else
			break;
	}

	// '+' or '-' sign handle
	int minus = 1;
	if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
		minus = str[i] == '-' ? -1 : 1;
		++i;
	}

	// integer part
	float integer = 0.0;
	for (; i < str.size(); i++) {
		if (isdigit(str[i])) {
			integer = integer * 10 + str[i] - '0';
		}
		else {
			break;
		}
	}

	// decimal part
	float decimal = 0.0;
	int points = 0;

	// point
	if (i < str.size() && str[i] == '.') {
		i++;
		for (; i < str.size(); i++) {
			if (isdigit(str[i])) {
				decimal = decimal * 10 + str[i] - '0';
				points++;
			}
			else {
				break;
			}
		}
		// followed by exp
		if (i < str.size() && (str[i] == 'e' || str[i] == 'E')) {
			int exp = 0.0;
			i++;
			int expMinus = 1;

			if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
				expMinus = str[i] == '-' ? -1 : 1;
				i++;
			}

			for (; i < str.size(); i++) {
				if (isdigit(str[i])) {
					exp = exp * 10 + str[i] - '0';
				}
				else {
					break;
				}
			}
			return minus * (integer + decimal / pow(10, points)) * pow(10, expMinus * exp);
		}
		// followed by other non-exp and non-digit character
		else {
			return minus * (integer + decimal / pow(10, points));
		}

	}
	// exp
	else if (i < str.size() && (str[i] == 'e' || str[i] == 'E')) {
		int exp = 0.0;
		i++;
		int expMinus = 1;

		if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
			expMinus = str[i] == '-' ? -1 : 1;
			i++;
		}

		for (; i < str.size(); i++) {
			if (isdigit(str[i])) {
				exp = exp * 10 + str[i] - '0';
			}
			else {
				break;
			}
		}
		return minus * (integer * pow(10, expMinus * exp));
	}
	// there are non '.' 'E' 'e' '[0-9]' character, ignore it, only return former integer;
	else {
		return minus * integer;
	}

	// start non-space character is not digit or '+' or '-', then return 0.0;
	// return 0.0;
}

int main() {
	cout << myAtof("    ") << endl;
	cout << myAtof("   12.") << endl;
	cout << myAtof("   1.2") << endl;
	cout << myAtof("-13.24") << endl;
	cout << myAtof("   -15.27e3") << endl;
	cout << myAtof("   -16.29e-3") << endl;
	cout << myAtof("   -41.26e-10.4") << endl;
	cout << myAtof("   -1e-3") << endl;
	cout << myAtof("   +134de-3a") << endl;
	cout << myAtof("   1.3e3a") << endl;
	cout << myAtof("   a") << endl;
	cout << myAtof("   +a") << endl;
	cout << myAtof("   13.25ra") << endl;
	cout << myAtof("   14ra.3") << endl;
	return 0;
}
```

### NQueens
+ 回溯法
+ 用递归思路会清晰很多
+ 位操作+回溯法+递归 是目前最快的方法


### 蓄水池抽样算法
+ [未知链表长度的情况下从中随机取k个数](http://www.cnblogs.com/longdouhzt/archive/2012/02/28/2371480.html)
+ [Leetcode: Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

### C++/Java常见数据结构的常用接口总结(TODO)
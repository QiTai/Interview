#### 面试题27：二叉搜索树与双向链表

```cpp
// 此解法与书不同，此法更好
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL)
            return NULL;
        if (pRootOfTree->left == NULL && pRootOfTree->right == NULL) {
            return pRootOfTree;
        }
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        while (p != NULL && p->right != NULL) {
            p = p->right;
        }
        if (pRootOfTree->left) {
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        TreeNode* right = Convert(pRootOfTree->right);
        if (pRootOfTree->right) {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left == NULL ? pRootOfTree : left;
    }
};
```

#### 面试题32：[从1到n整数中1出现的次数](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```cpp
// WayI : from编程之美(用此法)
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        int highNum = 0;
        int lowNum = 0;
        int curNum = 0;
        int index = 0;
        int count = 0;
        int powNum = 1;
        while (n / powNum) {
            lowNum = n - (n / powNum) * powNum;
            curNum = n / powNum % 10;
            highNum = n / (powNum * 10);
            if (curNum > 1)
                count += (highNum + 1) * powNum;
            else if (curNum == 1)
                count += highNum * powNum + lowNum + 1;
            else
                count += highNum * powNum;
            powNum *= 10;
        }
        return count;
    }
};
```

#### 面试题33:把数组排成最小的数
```cpp

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string str = "";
        std::sort(numbers.begin(), numbers.end(), compare);
        for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
            stringstream ss;
            ss << *it;
            str += ss.str();
        }
        return str;
    }
     
    static bool compare(int num1, int num2) {
        stringstream ss1, ss2;
        ss1 << num1; ss2 << num2;
        string str1 = ss1.str(), str2 = ss2.str();
        string str12 = str1 + str2;
        string str21 = str2 + str1;
        return str12 <= str21 ? 1 : 0;
    }
};
```

#### 面试题34:[丑数](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```cpp
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;

        vector<int> uglyNums;
        uglyNums.push_back(1);

        int min2Indx = 0;
        int min3Indx = 0;
        int min5Indx = 0;
        for (int i = 1; i < index; i++) {
            int minUgly = min(min(2 * uglyNums[min2Indx], 3 * uglyNums[min3Indx]), 5 * uglyNums[min5Indx]);
            uglyNums.push_back(minUgly);
            while (2 * uglyNums[min2Indx] <= minUgly)
                min2Indx++;
            while (3 * uglyNums[min3Indx] <= minUgly)
                min3Indx++;
            while (5 * uglyNums[min5Indx] <= minUgly)
                min5Indx++;
        }
        return uglyNums.back();
    }
};
```

#### 面试题53:正则表达式匹配

```cpp

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == NULL || pattern == NULL)
            return false;
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
         
        // 考虑到存在str为空，但pattern不为空，却仍然匹配的情况,如str = "", pattern = '.*'
 
        if (*(pattern +  1) == '*') {
            if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
                return match(str, pattern + 2) || match(str + 1, pattern) || match(str + 1, pattern + 2);
            } else {
                return match(str, pattern + 2);
            }
        }
        if ((*pattern == '.' && *str != '\0') || *pattern == *str)
            return match(str + 1, pattern + 1);
        return false;
    }
};
```

#### 面试题65：滑动窗口的最大值

```cpp
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        deque<int> maxIdx;
        vector<int> res;
        if (num.size() < size || size <= 0)
            return res;
        for (int i = 0; i < size; i++) {
        	while (!maxIdx.empty() && num[maxIdx.back()] < num[i]) {
            	maxIdx.pop_back();
           	}
           	maxIdx.push_back(i);
        }
        res.push_back(num[maxIdx.front()]);
        for (int i = size; i < num.size(); i++) {
            if (!maxIdx.empty() && i - maxIdx.front() >= size)
                maxIdx.pop_front();
            while (!maxIdx.empty() && num[maxIdx.back()] < num[i]) {
                maxIdx.pop_back();
            }
            maxIdx.push_back(i);
            res.push_back(num[maxIdx.front()]);
        }
        return res;
    }
};
```
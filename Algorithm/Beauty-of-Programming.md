### 1 游戏之乐

#### 1.1 让CPU占有率曲线听指挥

```cpp
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int SAMPLING_COUNT = 200;
const double PI = 3.141592635;
const int TOTAL_AMPLITUDE = 300;

int main() {

	DWORD busySpan[SAMPLING_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double radianIncrement = 2.0 / (double)SAMPLING_COUNT;
	for (int i = 0; i < SAMPLING_COUNT; i++) {
		busySpan[i] = (DWORD)(amplitude + (sin(PI * radian) * amplitude));
		radian += radianIncrement;
		printf("%d\t%d\n", busySpan[i], TOTAL_AMPLITUDE - busySpan[i]);
	}

	DWORD startTime = 0;
	for (int j = 0;; j = (j + 1) % SAMPLING_COUNT) {
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE - busySpan[j]);
	}

	return 0;
}
```

#### 1.2 将帅问题
```cpp
// Way I
#include <stdio.h>

#define HALF_BITS_LENGTH 4   // 存储单元长度的一半
#define FULLMASK 255		 // 11111111
#define LMASK (FULLMASK << HALF_BITS_LENGTH)   // 11110000
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)   // 00001111
#define RSET(b, n) (b = ((LMASK & b) | (n)))   // 将b右边设置为n
#define LSET(b, n) (b = ((RMASK & b) | ((n) << HALF_BITS_LENGTH)))   // 将b左边设置为n
#define RGET(b, n) (RMASK & b) //取b右边值
#define LGET(b, n) ((LMASK & b) >> HALF_BITS_LENGTH) //取b左边值
#define GRIDW 3 //帅移动范围的宽度

int main() {
	unsigned char b;
	for (LSET(b, 1); LGET(b) <= GRIDW * GRIDW; LSEG(b, (LGET(b) + 1)))
		for (RSET(b, 1); RGET(b) <= GRIDW * GRIDW; RSET(b, (RGET(b) + 1)))
			if (LGET(b) % GRIDW != RGET(b) % GRIDW)
				printf("A = %d, B = %d\n", LGET(b), RGET(b));
	return 0;
}

// Way II
#include <stdio.h>

int main() {
	char i = 81;
	while (i--) {
		if (i / 9 % 3 == i % 9 % 3)
			continue;
		printf("A = %d, B = %d\n", i / 9 + 1, i % 9 + 1);
	}

	return 0;
}

// way III
#include <stdio.h>

int main() {
	struct {
		unsigned char a : 4;
		unsigned char b : 4;
	} i;
	for (i.a = 1; i.a <= 9; i.a++) {
		for (i.b = 1; i.b <= 9; i.b++) {
			if (i.a % 3 != i.b % 3) {
				printf("A = %d, B = %d\n", i.a, i.b);
			}
		}
	}

	return 0;
}

```

#### 1.3 一摞烙饼的排序
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using std::endl;
using std::cout;
using std::string;
using std::vector;


// 烙饼排序实现
class CPrefixSorting {
public:
	CPrefixSorting() {
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}
	~CPrefixSorting() {
		if (m_CakeArray != NULL) {
			delete m_CakeArray;
		}
		if (m_SwapArray != NULL) {
			delete m_SwapArray;
		}
		if (m_ReverseCakeArray != NULL) {
			delete m_ReverseCakeArray;
		}
		if (m_ReverseCakeArraySwap != NULL) {
			// got problems here??
			//delete m_ReverseCakeArraySwap;
		}
	}

	//
	// 计算烙饼翻转信息
	// @param
	// pCakeArray  存储烙饼索引数组
	// nCakeCnt     烙饼个数
	//
	void Run(int* pCakeArray, int nCakeCnt) {
		Init(pCakeArray, nCakeCnt);

		m_nSearch = 0;
		Search(0);
	}

	//
	// 输出烙饼具体翻转的次数
	//
	void Output() {
		for (int i = 0; i < m_nMaxSwap; i++) {
			printf("%d ", m_SwapArray[i]);
		}
		printf("\n | Search Time| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
	}

private:
	//
	// 初始化数组信息
	// @param
	// pCakeArray  存储烙饼索引数组
	// nCakeCnt     烙饼个数
	//
	void Init(int* pCakeArray, int nCakeCnt) {
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);

		m_nCakeCnt = nCakeCnt;

		// 初始化烙饼数组
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);

		for (int i = 0; i < m_nCakeCnt; i++) {
			m_CakeArray[i] = pCakeArray[i];
		}

		// 设置最多交换次数信息
		m_nMaxSwap = UpperBound(m_nCakeCnt);

		// 初始化交换结果数组
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray != NULL);

		// 初始化中间交换结果信息
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for (int i = 0; i < m_nCakeCnt; i++) {
			m_ReverseCakeArray[i] = m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}

	//
	// 寻找当前翻转的上界
	//
	int UpperBound(int nCakeCnt) {
		return nCakeCnt * 2;
	}

	//
	// 寻找当前翻转的上界
	//
	int LowerBound(int* pCakeArray, int nCakeCnt) {
		int t, ret = 0;

		// 根据当前数组的排序信息情况判断最少需要交换多少次
		for (int i = 1; i < nCakeCnt; i++) {
			// 判断位置相邻的两个烙饼,是否为尺寸排序上相邻的
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1)) {
			}
			else {
				ret++;
			}
		}
		return ret;
	}

	// 排序主函数
	void Search(int step) {
		int i, nEstimate;

		m_nSearch++;

		// 估算这次搜索所需要的最小交换次数
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);

		if (step + nEstimate > m_nMaxSwap)
			return;

		// 如果已经排好序，即翻转完成，输出结果
		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt)) {
			if (step < m_nMaxSwap) {
				m_nMaxSwap = step;
				for (i = 0; i < m_nMaxSwap; i++) {
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
				}
			}
			return;
		}

		// 递归进行翻转
		for (i = 1; i < m_nCakeCnt; i++) {
			Reverse(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Reverse(0, i);
		}
	}

	bool IsSorted(int* pCakeArray, int nCakeCnt) {
		for (int i = 1; i < nCakeCnt; i++) {
			if (pCakeArray[i - 1] > pCakeArray[i])
				return false;
		}
		return true;
	}

	void Reverse(int nBegin, int nEnd) {
		assert(nEnd > nBegin);
		int i, j, t;

		for (int i = nBegin, j = nEnd; i < j; i++, j--) {
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}

private:
	int* m_CakeArray;				// 烙饼信息数组
	int m_nCakeCnt; 				// 烙饼次数
	int m_nMaxSwap;					// 最多交换次数

	int* m_SwapArray;				// 交换结果数组
	int* m_ReverseCakeArray;		// 当前翻转烙饼信息数组
	int* m_ReverseCakeArraySwap;   	// 当前翻转烙饼交换结果数组
	int m_nSearch;
};

int main() {
	int N = 10;
	int* pCakeArray = new int[N];
	vector<int> arr{ 3, 2, 1, 6, 5, 4, 9, 8, 7, 0 };
	assert(arr.size() == N);
	for (int i = 0; i < N; i++) {
		pCakeArray[i] = arr[i];
	}

	CPrefixSorting pSort;
	pSort.Run(pCakeArray, N);
	pSort.Output();
	delete pCakeArray;
}
```

### 2. 数字之谜--数字中的技巧

#### 2.3 寻找发帖之王
+ 拓展题：寻找一个数组中出现次数超过一半的数

```cpp

#include <vector>
#include <iostream>

int findMaxTimesNum(std::vector<int> nums) {
	int candidate = 0;
	int nTimes = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nTimes == 0) {
			candidate = nums[i];
			nTimes++;
		}
		else {
			if (candidate == nums[i])
				nTimes++;
			else
				nTimes--;
		}
	}
	return candidate;
}

int main() {
	std::vector<int> nums{ 3, 1, 3, 1, 5, 1, 6, 1, 2, 1, 1, 1, 2 };
	std::cout << findMaxTimesNum(nums) << std::endl;
}

```


+ 拓展题: 一个数组中有3个数出现的次数大于总数目的1/4,如何在O(1)空间O(n)时间内找出此三个数？

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

vector<int> find3MaxTimesNum(vector<int> nums) {
	int candidate1 = 0, candidate2 = 0, candidate3 = 0;
	int nTimes1 = 0, nTimes2 = 0, nTimes3 = 0, nTimes4 = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == candidate1) {
			nTimes1++;
		}
		else if (nums[i] == candidate2) {
			nTimes2++;
		}
		else if (nums[i] == candidate3) {
			nTimes3++;
		}
		// The above conditions must be tested first!!!
		else if (nTimes1 == 0) {
			candidate1 = nums[i];
			nTimes1++;
		}
		else if (nTimes2 == 0) {
			candidate2 = nums[i];
			nTimes2++;
		}
		else if (nTimes3 == 0) {
			candidate3 = nums[i];
			nTimes3++;
		}
		else {
			nTimes1--;
			nTimes2--;
			nTimes3--;
		}
	}
	return vector<int> { candidate1, candidate2, candidate3 };
}

int main() {
	vector<int> nums{ 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4 };
	vector<int> res = find3MaxTimesNum(nums);
	for (int a : res) {
		cout << a << "\t";
	}
	cout << endl;
}

```

#### 2.4 1的数目
+ 写f(N)用于返回1到N中出现的"1"的个数？

```cpp
	#include <iostream>
	#include <assert.h>

	using std::cout;
	using std::endl;

	int sum1s(int N) {
		int factor = 1;
		int count = 0;

		int lowerNum = 0;
		int curNum = 0;
		int higherNum = 0;

		while (N / factor != 0) {
			lowerNum = N - (N / factor) * factor;
			curNum = N / factor % 10;
			higherNum = N / (factor * 10);

			switch (curNum) {
			case 0:
				count += higherNum * factor;
				break;
			case 1:
				count += higherNum * factor + lowerNum + 1;
				break;
			default:
				count += (higherNum + 1) * factor;
				break;
			}

			factor*= 10;
		}
		return count;

	}

	int main() {
		assert(sum1s(123) == 57);
		assert(sum1s(12) == 5);
		cout << "ALL TEST PAST" << endl;
	}

```

+ 拓展：将10进制改成2进制，8进制，16进制，又改如何求求解上述问题
	+ 其实很简单，直接将上述算法中涉及的base由10改为对应的base即可

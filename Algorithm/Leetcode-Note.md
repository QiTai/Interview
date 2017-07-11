### Que
+ How to check whether an int number is going to overflow? 
* [Check for Integer Overflow](http://www.geeksforgeeks.org/check-for-integer-overflow/)
* related leetcode
   + 8-String to Integer (atoi)
### Easy to forget

+ 凡是涉及**int运算操作**，一定考虑**overflow**,非常容易忘记！！！
  + 8-String to Integer (atoi)
  + 29-Divide Two Integers
  + 166-Fraction to Recurring Decimal


### Similar Question

#### Same Method

+ Dynamic Programming (**在String类型题目中用的很多**)
  + **凡是求最优解的，一般都是走DP的路线!!!**
  + **凡是求问题的解法的，一般可以考虑DP，从解决小问题开始**
  + 70-Climbing Stairs (easy)(**conventional sub-problem**)
  + 62-Unique Paths (medium)(**conventional sub-problem**)
  + 63-Unique Paths II (medium) (**conventional sub-problem**)
  + 132-Palindrome Partitioning II (Hard) (**minimum cut**)
  + 300-Longest Increasing Subsequence (**longest optimization question**)
  + 139-Word Break(**yes or no question**)
  + 322-Coin Change(**minimum optimization question**)
  + 91-Decode Ways(**conventional sub-problems**)
+ BackTracking
  + **遇到要求所有组合、可能、排列等解集的题目，一般都是用DFS + backtracking来做**
  + 如果单纯用backtracking会TLE，则考虑**剪枝(140,212)**;或者先用**dynamic programming储存一些有用信息(131)**
  + 77-Combination
  + 46-Permutations
  + 78-Subsets
  + 90-Subsets II
  + 17-Letter Combinations of a Phone Number
  + 22-Generate Parentheses
  + 401-Binary Watch
  + 131-Palindrome Partitioning(return all possible,用回溯;利用DP存储有用信息，节省时间)
  + 51-N-Queens(Hard)
  + 52-N-Queens II(Hard)
  + 140-Word Break II(同样是求all possible,用回溯，但是TLE了，还要加上**“剪枝"**的技巧) 
  + 79-Word Search(related to **PATH**, naturally **DFS**)
  + 212-Word Search II(“剪枝”的技巧+**Trie**)


+ Two Pointers

  + 15-3Sum
  + 16-3Sum Closet
  + 18-4Sum
  + 11-Container with Most Water
  + 42-Trapping Rain Water
  + 75-Sort Colors


+ Binary Search
  + 一般看到题目限制O(lg(m+n)),O(lgn)之类，就应想到Binary Search和Divide and Conquer
  + 74-Search a 2D Matrix 
  + 240-Search a 2D Matrix II
  + 162-Find Peak Element--**Binary Search**
  + 4-Median of Two Sorted Arrays--**Excellent Idea**
  + 34-Search for a Range--**Excellent Idea**
  + 315-Count of Smaller Numbers After Self
+ Divide and Conquer
  + 215-Kth Largest Element in an Array
+ Hash & Hash Table
  + 在string和array中要用到**统计出现次数**时常用的手段
  + 49-Group Anagrams
  + 347-Top K Frequent Elements(对于这类的**统计数字**的问题，首先应该考虑用哈希表来做)
  + 1-Two Sum
  + 454-4Sum II
  + 166-Fraction to Recurring Decimal (编程之美上有一道反过来的题目Decimal->Fraction,可以对比)
  + 128-Longest Consecutive Sequence(本来一看到这种longest要想到DP,但是完全无法找到子问题与原问题之间的联系，所以要重新想思路，又看到题目要求O(n),所以“空间换时间”，在空间换时间方法中，最常用的就是Hash相关数据结果**unordered_map或unordered_set**)
+ Heap
  + 当设计要找Top K(包括频繁更换Top 1),都可以考虑用Heap来做,在C++为priority_queue
  + 215-Kth Largest Element in an Array
  + 347-Top K Frequent Element
  + 295-Find Median from Data Stream(剑指Offer也做过，巧妙利用最大堆和最小堆;Leetcode官方还给出了Balanced BST的方法，很妙，同时可以学习multiset这个C++数据结构)
+ Stack(use stack as tool)
  + 455-Add Two Numbers II
  + 150-Evaluate Reverse Polish Notation (I'm quite familiar with this term, **overflow is not the focus of this problem**)
+ Binary Search Tree
  + 315-Count of Smaller Numbers After Self
+ Depth-first-Search & Recursion
  + 设计到在矩阵中寻找满足某条件之类的题目（涉及到形成”路径“），肯定是DFS及BackTracking之类的技巧，可能有的时候要加上“剪枝和DP"来节省时间
  + 329-Longest Increasing Path in a Matrix(**DFS+DP剪枝**,Longest就应该联想到DP)
  + 124-Binary Tree Maximum Path Sum(when no direct solution comes to mind, **recursion** is always the best one for tree-related problems)
  + 129-Sum Root to Leaf Numbers(easy question using recursion while keeping track of the value)
+ Breadth-first-Search
  + 127-Word Ladder(**表面考String，实质考察图的两点的最短路径[refer](http://bangbingsyb.blogspot.com/2014/11/leetcode-word-ladder-i-ii.html)**  ,这里必须用BFS,用DFS会TLE)
  + 126-Word LadderII(BFS + 剪枝)
  + 130-Surrounded Regions(用递归DFS会栈溢出,用迭代DFS或BFS即可)
+ Sort 
  - 56-Merge Intervals
  - 47-Insert Interval
  - 324-Wiggle Sort II
  - 174-Largest Number(**Special Sort Trick**, same with Offer)
+ Topological Sort & Graph
  - 207-Course Schedule
  - 210-Course Schedule II
+ Reservoir Sampling
  - 382-Linked List Random Node
  - [未知链表长度的情况下从中随机取k个数](http://www.cnblogs.com/longdouhzt/archive/2012/02/28/2371480.html)
+ Greedy
  - 55-Jump Game (**From Dynamic Programming to Greedy**)
  - 134-Gas Station
+ Find Rules(找规律题,这种题就是在面试中去寻找规律)
  + 54-Spiral Matrix
  + 59-Spiral Matrix II
  + 48-Rotate Image


#### Same Trick

+ swap number in an array
  + 题目一般要求O(n) time + O(1) space(正因为O(1) space,所以要修改原数组)
  + 41-First Missing Positive
  + 448-Find All Numbers Disappeared in an Array(have other ways)
  + 442-Find All Duplicates in an Array(quite similar to 448)


#### Same Topic

+ Palindromic
  + 214-shortest palindrome--**Special String Tricks+KMP**
  + 5-Longest Palindromic Substring-- **Manacher's Alg. && Dyanamic Programming**
  + 512-Longest Palindromic Subsequences--**Dynamic Programming**
  + 131-Palindrome Partitioning--**keywords: return all possible | so use Backtracking, with DP to help save time**
  + 132-Palindrome Partitioning II--**Dynamic Programming**


+ In-Place Change Matrix

  + 48-Rotate Image -- **Find Rules**
  + 289-Game of Life--**Use different numbers to represent the states**
  + 73-Set Matrix Zeroes--**use the first row and col to store the states**
+ 419-Battleships in a Board vs. 200-Number of Islands
  - 419(Extra rules, horizontal and vertical, easy to solve)
  - 200(DFS to solve)
+ Sum
  + 15-3Sum
  + 16-3Sum Closet
  + 18-4Sum以上思路类似(**排序+双指针**)
  + 1-Two Sum
  + 454-4Sum II以上思路类似(**HashMap**;doesn't use sort, because **return indices**)
+ Interval
  + 56-Merge Intervals
  + 47-Insert Interval
+ List
  + 2-Add Two Numbers(比较简单的list题目，最后注意要考虑carry)
  + 455-Add Two Numbers II
+ Maximum in Binary Tree
  + 124-Binary Tree Maximum Path Sum
  + 编程之美3.8-二叉树中节点的最大距离
+ Find Missing or Duplicate Numbers
  + 41-Find Missing Positive(swap trick)
  + 287-Find the Duplicate Number(binary search)
  + 448-Find All Numbers Disappeared in an Array(swap trick)
  + 442-Find All Duplicates in an Array(quite similar to 448, swap trick)
  + 268-Missing Number(special condition : easy, bit manipulation)


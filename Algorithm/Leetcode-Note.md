### Que
+ How to check whether an int number is going to overflow? 
* [Check for Integer Overflow](http://www.geeksforgeeks.org/check-for-integer-overflow/)
* related leetcode
   + 8-String to Integer (atoi)

### Similar Question

#### Same Method

+ Dynamic Programming (**在String类型题目中用的很多**)
  + **凡是求最优解的，一般都是走DP的路线!!!**
  + 70-Climbing Stairs (easy)(**conventional sub-problem**)
  + 62-Unique Paths (medium)(**conventional sub-problem**)
  + 63-Unique Paths II (medium) (**conventional sub-problem**)
  + 132-Palindrome Partitioning II (Hard) (**minimum cut**)
  + 300-Longest Increasing Subsequence (**longest optimization question**)
  + 139-Word Break(**yes or no question**)
  + 322-Coin Change(**minimum optimization question**)
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

  + 74-Search a 2D Matrix 
  + 240-Search a 2D Matrix II
  + 162-Find Peak Element--**Binary Search**
+ Divide and Conquer
  + 215-Kth Largest Element in an Array
+ Hash & Hash Table
  + 在string和array中要用到**统计出现次数**时常用的手段
  + 49-Group Anagrams
  + 347-Top K Frequent Elements(对于这类的**统计数字**的问题，首先应该考虑用哈希表来做)
  + 1-Two Sum
  + 454-4Sum II
+ Topological Sort & Graph
  + 207-Course Schedule
  + 210-Course Schedule II
+ Reservoir Sampling
  + 382-Linked List Random Node
  + [未知链表长度的情况下从中随机取k个数](http://www.cnblogs.com/longdouhzt/archive/2012/02/28/2371480.html)
+ Greedy
  + 55-Jump Game (**From Dynamic Programming to Greedy**)
  + 134-Gas Station
+ Sort & Interval
  + 56-Merge Intervals
  + 47-Insert Interval
  + 324-Wiggle Sort II
+ Heap
  + 当设计要找Top K(包括频繁更换Top 1),都可以考虑用Heap来做,在C++为priority_queue
  + 215-Kth Largest Element in an Array
  + 347-Top K Frequent Element


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


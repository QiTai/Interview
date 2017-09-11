### Easy to forget

+ 凡是涉及**int运算操作**，一定考虑**overflow**,非常容易忘记！！！
  + 8-String to Integer (atoi)
  + 29-Divide Two Integers
  + 166-Fraction to Recurring Decimal
  + 7-Reverse Integer



### Similar Question

#### Same Method

+ Dynamic Programming (**在String类型题目中用的很多**)
  + **凡是求最优解的，一般都是走DP的路线!!!**
  + **凡是求问题的解法的，一般可以考虑DP，从解决小问题开始**
  + **对于字符串的问题，稍微难点的十有八九都是用DP**
  + 70-Climbing Stairs (easy)(**conventional sub-problem**)
  + 62-Unique Paths (medium)(**conventional sub-problem**)
  + 63-Unique Paths II (medium) (**conventional sub-problem**)
  + 132-Palindrome Partitioning II (Hard) (**minimum cut**)
  + 300-Longest Increasing Subsequence (**longest optimization question**)
  + 5-Longest Palindromic Substring
  + 139-Word Break(**yes or no question**)
  + 322-Coin Change(**minimum optimization question**)
  + 91-Decode Ways(**conventional sub-problems**)
  + 10-Regular Expression Matching(string类题目，而且状态不是很好判断，且用recursion可以解决的用DP省时间)
  + 44-Wildcard Matching(string类题目，用recursion会超时，就想到用DP)
  + 198-House Robber
  + 213-House Robber II
  + 123-Best time to buy and sell stock III
  + 188-Best time to buy and sell stock IV
  + 72-Edit Distance
  + 115-Distinct Subsequences
  + 53-Maximum Subarray
  + 152-Maximum Product Subarray
  + 192-Dungeon Game
  + Counting Bits
  + Combination Sum IV
  + Longest Common Subsequence(from Coding_Interview_in_Java_v3 194)
  + Longest Common Substring(from Coding_Interview_in_Java_v3 195)
  + 646-Maximum Length of Pair Chain
  + 560-Subarray Sum Equals K
  + 523-Continuous Subarray Sum
  + 120-Triangle
  + 264-Ugly Number II(Microsoft Skype Interview Question)
  + 464-Can I Win(用到bit manipulation的技巧来区分不同状态)
  + 486-Predict the Winner

+ BackTracking
  + **遇到要求所有组合、可能、排列等解集的题目，一般都是用DFS + backtracking来做**
  + 如果单纯用backtracking会TLE，则考虑**剪枝(140,212)**;或者先用**dynamic programming储存一些有用信息(131)**
  + 77-Combination
  + 46-Permutations
  + 47-Permutations II
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
  + 93-restore IP Addresses


+ Two Pointers
  + 167-Two Sum II - Input array is sorted
  + 15-3Sum
  + 16-3Sum Closet
  + 18-4Sum
  + 11-Container with Most Water
  + 42-Trapping Rain Water
  + 75-Sort Colors
  + 3-Longest Substring Without Repeating Characters
  + Longest Substring with At Most Two Distinct Characters

  + 125-Valid Palindrome(easy)
  + 234-Palindrome Linked List(with extra tricks: reverse list)
  + 9-Palindrome Number

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
  + 23-Merge K Sorted Lists

+ Hash & Hash Table
  + 在string和array中要用到**统计出现次数**时常用的手段
  + 49-Group Anagrams
  + 347-Top K Frequent Elements(对于这类的**统计数字**的问题，首先应该考虑用哈希表来做)
  + 1-Two Sum
  + 454-4Sum II
  + 166-Fraction to Recurring Decimal (编程之美上有一道反过来的题目Decimal->Fraction,可以对比)
  + 128-Longest Consecutive Sequence(本来一看到这种longest要想到DP,但是完全无法找到子问题与原问题之间的联系，所以要重新想思路，又看到题目要求O(n),所以“空间换时间”，在空间换时间方法中，最常用的就是Hash相关数据结果**unordered_map或unordered_set**)
  + 149-Max Points on a Line(在原本O(n^3)的基础上用Hash Table稍微改进到O(n^2),所以像这种Hard题目就是在原本思想上一点点改进)
  + 138-Copy List with Random Pointers(HashTable is the basic though, more beautiful trick is to modify original structure)
  + 133-Clone Graph
  + [Find longest subarray whose sum is divisible by K](https://jdhao.github.io/2017/09/01/longest-subarray-modulo-K/)


+ Heap
  + 当设计要找Top K(包括频繁更换Top 1),都可以考虑用Heap来做,在C++为priority_queue
  + 215-Kth Largest Element in an Array
  + 347-Top K Frequent Elements
  + 23-Merge K Sorted Lists(use heap)
  + 295-Find Median from Data Stream(剑指Offer也做过，巧妙利用最大堆和最小堆;Leetcode官方还给出了Balanced BST的方法，很妙，同时可以学习multiset这个C++数据结构)

+ Stack(use stack as tool)
  + 455-Add Two Numbers II
  + 150-Evaluate Reverse Polish Notation (I'm quite familiar with this term, **overflow is not the focus of this problem**)
  + 像Parentheses这种问题基本可以考虑用Stack
  + 20-Valid Parentheses
  + 32-Longest Valid Parentheses(当然此题是最优化题，也可以用DP，但是不如用stack来的直观)

+ Binary Search Tree
  + 315-Count of Smaller Numbers After Self

+ Depth-first-Search & Recursion
  + 设计到在矩阵中寻找满足某条件之类的题目（涉及到形成”路径“），肯定是DFS及BackTracking之类的技巧，可能有的时候要加上“剪枝和DP"来节省时间
  + 329-Longest Increasing Path in a Matrix(**DFS+DP剪枝**,Longest就应该联想到DP)
  + 124-Binary Tree Maximum Path Sum(when no direct solution comes to mind, **recursion** is always the best one for tree-related problems)
  + 129-Sum Root to Leaf Numbers(easy question using recursion while keeping track of the value)
  + 337-House Robber III(with special trick)
  + 638-Shopping Offers（像这样要遍历所有情况才能知道最优解的问题，DP或DFS才是正解）
  + 301-Remove Invalid Parentheses(所有情况的，DFS上，但是需要一些预处理)
  + 332-Reconstruct Itineray

+ Breadth-first-Search
  + 127-Word Ladder(**表面考String，实质考察图的两点的最短路径[refer](http://bangbingsyb.blogspot.com/2014/11/leetcode-word-ladder-i-ii.html)**  ,这里必须用BFS,用DFS会TLE)
  + 126-Word LadderII(BFS + 剪枝,这道题确实难)
  + 130-Surrounded Regions(用递归DFS会栈溢出,用迭代DFS或BFS即可)
  + 301-Remove Invalid Parentheses

+ Sort
  - 类似这种Interval和pair的题目，先sort技巧是经常用到的
  - 56-Merge Intervals
  - 47-Insert Interval
  - 324-Wiggle Sort II
  - 174-Largest Number(**Special Sort Trick**, same with Offer)
  - 646-Maximum Length of Pair Chain
  - 630-Course Schedule III

  * Bucket
  - 164-Maximum Gap

+ Topological Sort & Graph
  - 207-Course Schedule
  - 210-Course Schedule II

+ Reservoir Sampling
  - 382-Linked List Random Node
  - [未知链表长度的情况下从中随机取k个数](http://www.cnblogs.com/longdouhzt/archive/2012/02/28/2371480.html)

+ Bit Manipulation
  - Normally, the problem needs O(n) time, O(1) space
  - Single Number
  - Single Number II
  - Single Number III
  - Number of 1 Bits(Most beatiful way : n &= n - 1)
  - Repeated DNA Sequences(good)

+ Greedy
  - 55-Jump Game (**From Dynamic Programming to Greedy**)
  - 45-Jump GameII
  - 134-Gas Station
  - 646-Maximum Length of Pair Chain
  - 630-Course Schedule III(像这种pair的数据，一般都要根据某一个分量sort，再进行处理)

+ Find Rules(找规律题,这种题就是在面试中去寻找规律)
  + 54-Spiral Matrix
  + 59-Spiral Matrix II
  + 48-Rotate Image
  + 218-The Skyline Problem(Hard)

+ Math
  + 60-Permutation Sequences(use math rather than backtracking to speed up)

+ Binary Indexed Tree
  - 307-Range Sum Query - Mutable

+ Segment Tree
  - 307-Range Sum Query - Mutable

+ Trie
  - 208. Implement Trie (Prefix Tree)
  - 211-Add and Search Word - Data structure design

#### Same Trick

+ swap number in an array
  + 题目一般要求O(n) time + O(1) space(正因为O(1) space,所以要修改原数组)
  + 41-First Missing Positive
  + 448-Find All Numbers Disappeared in an Array(have other ways)
  + 442-Find All Duplicates in an Array(quite similar to 448)

+ Two-round reverse
  + 题目要求in-place
  + 189-Rotate Array
  + 186-Reverse Words in a String II

+ Use Map to store the sub-array sum or module
  + 560-Subarray Sum Equals K
  + 523-Continuous Subarray Sum(遇到除法问题，我们肯定不能忘了除数为0的情况等处理)

#### Same Topic

+ Minmax
  + 486-Predict the Winner
  + 464-Can I Win
  + 375-Guess Number Higher or Lower II   

+ Palindromic
  + 214-shortest palindrome
    + brute force(reverse string and compare the largest common substring) can be accepted! O(n^2) O(n), remember this solution
    + two pointers is better solution! O(n^2) O(1), use this method
    + Special String Tricks+KMP: just understand it, won't use it in real interview!
  + 5-Longest Palindromic Substring
    + Dyanamic Programming->optimization problem's first thought
    + Two Pointers->better solution
    + Manacher Alg->just understand, not possible on interview
  + 512-Longest Palindromic Subsequences--**Dynamic Programming**
  + 647-Palindromic Substrings
    + Two Pointers->better solution
    + **Dynamic Programming**
  + 131-Palindrome Partitioning--**keywords: return all possible | so use Backtracking, with DP to help save time**
  + 132-Palindrome Partitioning II--**Dynamic Programming**

  + 125-Valid Palindrome(easy)
  + 234-Palindrome Linked List(medium)(Linked list is a little bit tougher, without straight access to last part of the list, we have to use **reverse the list**)
  + 9-Palindrome Number


+ In-Place Change Matrix
  + 48-Rotate Image -- **Find Rules**
  + 289-Game of Life--**Use different numbers to represent the states**
  + 73-Set Matrix Zeroes--**use the first row and col to store the states**

+ 419-Battleships in a Board vs. 200-Number of Islands
  - 419(Extra rules, horizontal and vertical, easy to solve)
  - 200(DFS to solve)

+ Sum
  + 1-Two Sum
  + 167-Two Sum II - Input array is sorted
  + 170-Two Sum III - Data Structure Design
  + 653-Two Sum IV - Input is a BST (recursion always comes first!)
  + 15-3Sum
  + 16-3Sum Closet
  + 18-4Sum 以上思路类似(**排序+双指针**)
  + 454-4Sum II 以上思路类似(**HashMap**;doesn't use sort)

+ Range Sum
  + Range Sum Query - ImMutable   
  + Range Sum Query - Mutable   
  + Range Sum Query 2D - Immutable   

+ Interval
  + 56-Merge Intervals
  + 47-Insert Interval

+ List
  + reverse list是一个经常用的技巧,主要用于解决不能直接访问最后一个元素的问题
  + 双指针的方法用的很多！！！
  + fakeHead的技巧用的较多
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

+ Reverse Words in a String
  + 151-Reverse Words in a String(single iteration and careful handle with the spaces, just normal ways)
  + 186-Reverse Words in a String II(in-place, use spacial trick here, two-round reverse)
  + 557-Reverse Words in a String III(easy, special condition, just normal iteration to check is OK)

+ String Matching
  + 44-Wildcard Matching
  + 10-Regular Expression Matching

+ String->Number
  + String to Integer (atoi)
  + Valid Number (hard)
  + String to Float (Atof)->Algorithm.md

+ String & Array to perform mathematical operation
  + One by one operation, don't forget to handle the last carry!
  + 66-Plus One
  + 67-Add Binary
  + 415-Add Strings
  + 43-Multiply Strings (trick for storing the one by one multiplication)
  + 2-Add Two Numbers
  + 445-Add Two Numbers II (use stack as helper)

  + 371-Sum of Two Integers (Pure Bit Manipulation)

### Review Done

#### Top Interview Questions
+ 238-Product of Array Except Self(Special Trick: forward & backward iteration)
+ 347-Top K Frequent Elements
+ 94-Binary Tree Inorder Traversal(Classical Question: Binary Tree Traversal)
+ 384-Shuffle An Array(Trick: random swap)
+ Sum类型题目,见上面的总结
+ 163-Missing Ranges(easy)
+ 161-One Edit Distance

+ 3-Longest Substring Without Repeating Characters
+ Longest Substring with At Most Two Distinct Characters


+ 22-Generate Parentheses
+ 20-Valid Parentheses

+ 125-Valid Palindrome(easy)
+ 234-Palindrome Linked List
+ 9-Palindrome Number

+ 5-Implement strstr()

+ Reverse Words in a String
+ Reverse Words in a String II(in place)

+ String to Integer (atoi) - 4 special cases should be thought of!
+ valid number

+ Balanced Binary Tree - Recursion with first check child to avoid repeated calling!
+ Binary Tree Maximum Path Sum - Recursion with 0 to simplify max
+ Minimum Depth of Binary Tree - Recursion | Queue
+ **Convert Sorted List to Balanced Search Tree** - **Bottom Up Recursion**,**Recursion with State** (Excellent)

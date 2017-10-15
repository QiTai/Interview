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
  + 639-Decode Ways II(同Decode Ways差不多,只不过情况更复杂)
  + 10-Regular Expression Matching(string类题目，而且状态不是很好判断，且用recursion可以解决的用DP省时间)
  + 44-Wildcard Matching(string类题目，用recursion会超时，就想到用DP)
  + 198-House Robber
  + 213-House Robber II
  + 123-Best time to buy and sell stock III
  + 188-Best time to buy and sell stock IV
  + 72-Edit Distance(string范围内典型的DP问题)
  + 115-Distinct Subsequences(string范围内典型的DP问题)
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
  + 64-Minimum Path Sum
  + 221-Maximal Square
  + 85-Maximal Rectangle(除了标准法DP之外，可以将问题转换为Largest Rectangle in Histogram)
  + 343-Integer Break(还可以从找规律的角度解答这个问题,refer to Grandyang)
  + 304-Range Sum Query 2D-Immutable
  + 96-Unique Binary Search Trees(其本质是卡塔兰数,数量同Generate Parentheses一样)
  + LintCode-Coins in a Line(参考leetcode_50)
  + 97-Interleaving String(leetcode-cpp)
  + 87-Scramble String(leetcode-cpp,第一次碰到要用三维的dp矩阵,这道题还是很有难度的)
  + 416-Partition Equal Subset Sum(我的思路是借鉴背包问题的动归)

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
  + 140-Word Break II(同样是求all possible,用回溯，但是TLE了，还要加上**剪枝**的技巧;记住DP也可以作为剪枝的辅助手段,参考leetcode-cpp解法)
  + 79-Word Search(related to **PATH**, naturally **DFS**)
  + 212-Word Search II(“剪枝”的技巧+**Trie**)
  + 93-restore IP Addresses
  + 113-Path Sum II(求所有情形,可以用backtracking,但由于这是二叉树,所以也可以用层次遍历的方式完成)
  + 95-Unique Binary Search Trees II


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
  + Minimum Size Subarray Sum(涉及这种连续的子数组，就要考虑two Pointers的储存)
  + 5-Implement strstr()(very precise code, need to be remembered!)

  + 125-Valid Palindrome(easy)
  + 88-Merge Sorted Array(easy)
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
  + Find Minimum in Rotated Sorted Array
  + Find Minimum in Rotated Sorted Array II
  + Search in Rotated Sorted Array
  + Search in Rotated Sorted Array II

+ Divide and Conquer
  + 215-Kth Largest Element in an Array
  + 23-Merge K Sorted Lists

+ Hash & Hash Table
  + 在string和array中要用到**统计出现次数**时常用的手段,问题的关键就变为了如何来构造key
  + 49-Group Anagrams
  + 249-Group Shifted Strings
  + 347-Top K Frequent Elements(对于这类的**统计数字**的问题，首先应该考虑用哈希表来做)
  + 1-Two Sum
  + 454-4Sum II
  + 166-Fraction to Recurring Decimal (编程之美上有一道反过来的题目Decimal->Fraction,可以对比)
  + 128-Longest Consecutive Sequence(本来一看到这种longest要想到DP,但是完全无法找到子问题与原问题之间的联系，所以要重新想思路，又看到题目要求O(n),所以“空间换时间”，在空间换时间方法中，最常用的就是Hash相关数据结果**unordered_map或unordered_set**)
  + 149-Max Points on a Line(在原本O(n^3)的基础上用Hash Table稍微改进到O(n^2),所以像这种Hard题目就是在原本思想上一点点改进)
  + 138-Copy List with Random Pointers(HashTable is the basic thought, more beautiful trick is to modify original structure)
  + 133-Clone Graph
  + 用两个HashTable对照
    + Substring with Concatenation of All Words(由于存在字典所有单词长度相同，所以存在一种更快捷的遍历方式,参考Grandyang)
    + Minimum Window Substring
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
  + Min Stack(设计题-考虑用双栈,增加一个minStack,追踪min值的变化)
  + 像Parentheses这种问题基本可以考虑用Stack
  + 20-Valid Parentheses
  + 32-Longest Valid Parentheses(当然此题是最优化题，也可以用DP，但是不如用stack来的直观)
  + 84-Largest Rectangle in Histogram

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
  + 407-Trapping Rain Water II(可以结合Trapping Rain Water一起考虑)

+ Sort
  - 类似这种Interval和pair的题目，先sort技巧是经常用到的
  - 56-Merge Intervals
  - 47-Insert Interval(Hard, because some tricky rules exists here)
  - 324-Wiggle Sort II
  - 174-Largest Number(**Special Sort Trick**,考虑一些特殊输入, same with Offer)
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
  - 134-Gas Station (find special rules)
  - 646-Maximum Length of Pair Chain
  - 630-Course Schedule III(像这种pair的数据，一般都要根据某一个分量sort，再进行处理)
  - 135-Candy

+ Find Rules(找规律题,这种题就是在面试中去寻找规律)
  + 54-Spiral Matrix
  + 59-Spiral Matrix II
  + 48-Rotate Image
  + 218-The Skyline Problem(Hard)

+ Math
  + 60-Permutation Sequences(use math rather than backtracking to speed up)
  + 12-Integer to Roman
  + 13-Roman to Integer

+ Binary Indexed Tree
  - 307-Range Sum Query - Mutable

+ Segment Tree
  - 307-Range Sum Query - Mutable

+ Trie
  - 208. Implement Trie (Prefix Tree)
  - 211-Add and Search Word - Data structure design

+ Design
  + 146-LRU Cache(list function: splice, push_front)
  + 460-LFU Cache(very Complex data structure)
  + 225-Implement Stack Using Queues
  + 232-Implement Queue Using Stacks

#### Same Trick

+ Moore Voting
  + Majority Element
  + Majority Element II

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

+ Range Sum Query
  + 303-Range Sum Query - Immutable
  + 307-Range Sum Query - Mutable
  + 304-Range Sum Query 2D - Immutable

+ Rotated Sorted Array
  + Find Minimum in Rotated Sorted Array
  + Find Minimum in Rotated Sorted Array II
  + Search in Rotated Sorted Array
  + Search in Rotated Sorted Array II

+ Minmax
  + 486-Predict the Winner
  + 464-Can I Win
  + 375-Guess Number Higher or Lower II   
  + 294-Flip Game II

+ Palindromic
  + 214-shortest palindrome
    + brute force(reverse string and compare the largest common substring) can be accepted! O(n^2) O(n), remember this solution
    + Grandyang 2nd way(very concise, use this method)
    + two pointers is better solution! O(n^2) O(1), use this method (refer to submission 179ms)
    + two pointers & reverse (refer to hint in leetcode website)
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

+ 419-Battleships in a Board vs. 200-Number of Islands vs. 305 Number of Islands II
  - 419(Extra rules, horizontal and vertical, easy to solve)
  - 200(DFS to solve)
  - 305(Very good solution Grandyang)

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
  + 143-Reorder List
  + 104-Odd Even Linked List
  + 86-Partition List
  + 24-Swap Nodes in Pair(参考leetcode_50解法)
  + 92-Reverse Linked List II
  + 19-Remove Nth Node From End of the List(像这种要求一次遍历的题目用快慢指针技巧)
  + 234-Palindrome Linked List(快慢指针，翻转／利用Stack)

+ Binary Tree
  + 144-Binary Tree Preorder Traversal(借助stack，最简单)
  + 94-Binary Tree Inorder Traversal(借助stack,但是比Preorder复杂)
  + 145-Binary Tree Postorder Traversal(借助stack,但是逻辑最烦)
  + 125-Binary Tree Level Order Traversal(借助queue,但是注意首先获得每一层的大小)
  + 107-Binary Tree Level Order Traversal II(借助queue,只是加入res的顺序和I不太一样)
  + 14-Binary Tree Vertical Order Traversal(借助queue,用递归来求Vertical Order)
  + 226-Invert Binary Tree(传统递归方法,或者借助queue)
  + 114-Flatten Binary Tree to Linked List
  + 106-Construct Binary Tree from Inorder and Postorder Traversal(典型递归解决)
  + 105-Construct Binary Tree from Preorder and Inorder Traversal(典型递归解决)
  + 111-Minimum Depth of Binary Tree(递归或者queue)
  + 104-Maximum Depth of Binary Tree(递归或者queue)
  + 124-Binary Tree Maximum Path Sum(Hard,递归)
  + 110-Balanced Binary Tree(递归,当树左右子树高度不同时,用max来求)
  + 101-Symmetric Tree(递归,或者queue)
  + 199-Binary Tree Right Side View(层次遍历取出每一层的最后一个节点)
  + 236-Lowest Common Ancestor of a Binary Tree
  + 331-Verify Preorder Serialization of a Binary Tree(想到用stack来做是最自然的想法,但是Grandyang提供了很简洁的思路;此题还要注意如何在C++中实现split)
  + 116-Populating Next Right Pointers in Each Node(最自然会想到层次遍历，然后做连接操作;不满足O(1),用上下两层指针来操作!!!)
  + 117-Populating Next Right Pointers in Each Node II(层次遍历同116没区别;用上下两层指针就有区别了，这里需要额外的判断及保存下层开始位置)
  + 129-Sum Root to Leaf Numbers(DFS迭代的基本思想)
  + 222-Count Complete Tree Nodes
  + 
  
  

+ Binary Search Tree
  + 230-Kth Smallest Element in BST
  + 98-Validate Binary Search Tree
  + 137-Convert Sorted Array to Binary Search Tree(中位数+递归)
  + 109-Convert Sorted List to Binary Search Tree(最简单的想法:先找到中间节点，再递归;更漂亮的解法是用bottom-up解法,参考leetcode_50)
  + 173-Binary Search Tree Iterator(中序遍历的非递归形式)
  + 235-Lowest Common Ancestor of a Binary Search Tree
  

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

+ Caculator
  + 用的方法都类似,从stack的角度考虑
  + 227-Basic Calculator II
  + 224-Basic Calculator

### Review Done

+ Increasing Triplet Subsequence

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

+ Reverse Words in a String
+ Reverse Words in a String II(in place)

+ String to Integer (atoi) - 4 special cases should be thought of!
+ valid number

+ Balanced Binary Tree - Recursion with first check child to avoid repeated calling!
+ Binary Tree Maximum Path Sum - Recursion with 0 to simplify max
+ Minimum Depth of Binary Tree - Recursion | Queue
+ **Convert Sorted List to Balanced Search Tree** - **Bottom Up Recursion**,**Recursion with State** (Excellent)

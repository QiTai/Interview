### Que
+ How to check whether an int number is going to overflow? 
* [Check for Integer Overflow](http://www.geeksforgeeks.org/check-for-integer-overflow/)
* related leetcode
   + 8. String to Integer (atoi)

### Similar Question

#### Same Method

+ Dynamic Programming (**在String类型题目中用的很多**)
  + **凡是求最优解的，一般都是走DP的路线!!!**
  + 70-Climbing Stairs (easy)
  + 62-Unique Paths (medium)
  + 63-Unique Paths II (medium)
  + 132-Palindrome Partitioning II (Hard)
  + 300-Longest Increasing Subsequence
  + 139-Word Break
+ BackTracking
  + **遇到要求所有组合、可能、排列等解集的题目，一般都是用DFS + backtracking来做**
  + 77-Combination
  + 46-Permutations
  + 78-Subsets
  + 90-Subsets II
  + 17-Letter Combinations of a Phone Number
  + 22-Generate Parentheses
  + 401-Binary Watch
  + 131-Palindrome Partitioning
  + 51-N-Queens(Hard)
  + 52-N-Queens II(Hard)
  + 140-Word Break II(同样是求all possible,用回溯，但是TLE了，还要加上**“剪枝"**的技巧) 


+ Two Pointers

  + 3Sum, 3Sum Closet, 4Sum思路类似(排序+双指针); Two Sum, 4Sum II思路类似(HashMap)
  + 11-Container with Most Water
  + 42-Trapping Rain Water
  + [75-Sort Colors](https://leetcode.com/problems/sort-colors)   
  + 3Sum, 3Sum Closet, 4Sum思路类似(排序+双指针); Two Sum, 4Sum II思路类似(HashMap)


+ Binary Search & Divide and Conquer

  + 74-Search a 2D Matrix 
  + 240-Search a 2D Matrix II

    + 162-Find Peak Element--**Binary Search**
+ Hash
  - 49-Group Anagrams
+ Topological Sort & Graph
  + 207-Course Schedule
  + 210-Course Schedule II
+ Reservoir Sampling
+ Greedy
  + 55-Jump Game **From Dynamic Programming to Greedy**
+ Sort & Interval
  + Merge Intervals
  + Insert Interval


#### Same Topic

+ Palindromic
  + shortest panlindrome (leetcode)
  + Longest Palindromic Substring (leetcode) -- **Manacher's Alg. && Dyanamic Programming**
  + Longest Palindromic Subsequences(leetcode) --**Dynamic Programming**
  + 131-Palindrome Partitioning
  + 132-Palindrome Partitioning II (Hard)


+ In-Place Change Matrix

  + 48-Rotate Image -- **Find Rules**
  + 289-Game of Life--**Use different numbers to represent the states**
  + 73-Set Matrix Zeroes--**use the first row and col to store the states**
+ 419-Battleships in a Board vs. 200-Number of Islands
  - 419(Extra rules, horizontal and vertical, easy to solve)
  - 200(DFS to solve)



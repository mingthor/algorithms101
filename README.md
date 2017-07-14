# Algorithms 101
## [Disjoint Set / Union Find](https://www.topcoder.com/community/data-science/data-science-tutorials/disjoint-set-data-structures/)
* [LC 547 Friend Circles](https://leetcode.com/problems/friend-circles/#/description)
* [128 Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/#/description)

## [Binary Indexed Trees](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/)
* [LC 303 Range Sum Query-Immutable](https://leetcode.com/problems/range-sum-query-immutable/#/description)
* [LC 307 Range Sum Query](https://leetcode.com/problems/range-sum-query-mutable/#/description)
* [LC 315 Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/#/description)
* [LC 493 Reverse Pairs](https://leetcode.com/problems/reverse-pairs/#/description)
  
## [KMP String Searching](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-string-searching-algorithms/)
* [LC 28 Implement strstr()](https://leetcode.com/problems/implement-strstr/#/description)
* [LC 214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/#/description)
  
## [Trie](https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/)
* [LC 208 Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/#/description)
* [LC 211 Add and Search Word - Data structure design](https://leetcode.com/problems/add-and-search-word-data-structure-design/#/description)
* [LC 336 Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/#/description)

## [Greedy](https://www.topcoder.com/community/data-science/data-science-tutorials/greedy-is-good/)
* [LC 630 Course Schedule II](https://leetcode.com/problems/course-schedule-iii/#/description)
* [LC 621 Task Scheduler](https://leetcode.com/problems/task-scheduler/#/description)
* [LC 452 Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/#/description)

## Graph
* [Representation](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-1/)
* [Searching](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-2/)
* [Finding the Best Path](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-3/)

## [Dynamic Programming](https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/)
* [LC 639 Decode Ways II](https://leetcode.com/problems/decode-ways-ii/#/description)

## [Line Sweep Algorithms](https://www.topcoder.com/community/data-science/data-science-tutorials/line-sweep-algorithms/)
* [LC 218 Skyline Problem](https://leetcode.com/problems/the-skyline-problem/#/description)
* [56 Merge Intervals](https://leetcode.com/problems/merge-intervals/#/description). Follow up: 2D intervals。
* [57 Insert Interval](https://leetcode.com/problems/insert-interval/#/description)

## [Prime Numbers & Factorization](https://www.topcoder.com/community/data-science/data-science-tutorials/prime-numbers-factorization-and-euler-function/)

## [Binary Search]()
* [LC 33 Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/#/description)
* [LC 69 Sqrt(x)](https://leetcode.com/problems/sqrtx/#/description)

## Algorithm Inteview Questions
* [LC 401 Binary Watch](https://leetcode.com/problems/binary-watch/#/description)
* [LC 204 Count Primes](https://leetcode.com/problems/count-primes/#/description)
* [LC 50 Pow(x, n)](https://leetcode.com/problems/powx-n/#/description)

* Graph
  * Given a list of nodes with id and parent_id, find direct child nodes and find all descendents of a node. Note about cycles in graph.
    ```C++
    struct node {
      int value;
      node* parent;
    }
    vector<node*> getChildren(node* n) {}
    vector<node*> getDescendents(node* n) {}
    ```
* LC 346 Moving Average from Data Stream, Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window. Follow up, multithreading?
  For example,
  ```java
  MovingAverage m = new MovingAverage(3);
  m.next(1) = 1
  m.next(10) = (1 + 10) / 2
  m.next(3) = (1 + 10 + 3) / 3
  m.next(5) = (10 + 3 + 5) / 3
  ```
  ```C++
  class MovingAverage {
  public:
      MovingAverage(int size) {}
      double next(int val) {}
  };
  ```
* Given a dictionary d and a misspelled word w, return all corrections for word w. A misspelled word has only one character different than its correction with same length. 
  ```C++
  vector<string> findCorrections(vector<string> dict, string w) {}
  ```
* [LC 72 Edit Distance](https://leetcode.com/problems/edit-distance/#/description)
* LC 161 One Edit Distance, Given two strings S and T, determine if they are both one edit distance apart.
* Given an array of unsorted numbers, find whether it can be equally divided into groups of 5 contigous integers. For example, {1,2,3} return false, {1,2,3,4,5,2,3,4,5,6} return true;
  ```C++
  bool divideFiveContigous(vector<int> nums) {}
  ```
* [LC 394. Decode String](https://leetcode.com/problems/decode-string/#/description)
* LC 471 Encode String with shortest length, Given a non-empty string, encode the string such that its encoded length is the shortest. The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
* LC buy sell stocks
* [LC 15 3Sum](https://leetcode.com/problems/3sum/#/description)
* [LC 16 3Sum Closest](https://leetcode.com/problems/3sum-closest/#/description)
* Given a sorted array of integers. Return their square in sorted order.
* LC 346 Moving Average from Data Stream
* [415 Add Strings](https://leetcode.com/problems/add-strings/#/description) Follow up: how to parallelize it?
* Given two integers a and b, swap the digits in a to make the result greater than b. Follow up: return the smallest.
* 设计查询系统(最大值，最小值，最新加入值)
	```C++
	class System { 
		int getMax(); 
		int getMin(); 
		int getRecent(); 
		void add(long time, int price);
		void update(long time, int price); 
		void remove(long time); 
	} 
	```
	例子如下
	add(1,4) max:4, min:4, recent:4
	add(4,7) max:7, min:4, recent:7 
	add(2,5) max:7, min:4, recent:7
	etc.. 
* Tree
  * [LC 104 Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description)
* Line Sweep:

  * given k sorted array has n posts, find the shortest interval contains at least 1 post from each array ?
  * 给一个区间的2d array,每一row表示一个接受方,给一个整数,求所有包含这个整数的接
受方
  * 253 meeting room II,252 meting room,detect if 2 range overlaps
  * 554 Brick wall,follow up,墙很扁,高度小长度宽,怎么优化?
* Math:
  * 273 integer to English, variation 加逗号和and × 7
  * 67 Add binary, follow up: 支持不同的base × 6,
  * 415 Add Strings
  * 311 Sparse Matrix Multiplication × 3
  * 给无重复prime number数组,返回相乘的结果集无重复 × 2
  * basic calculator I II,224, 227
  * 50 pow (x, n)
  * 29 divide 2 integer,follow up,求余数 * 2
  * 12,13,roman <---> int
  * fibonacci数列%10,找规律
    
# Resources
[Google phone interviews](https://github.com/jeromejj/GooglePhoneScreenBible/blob/master/GooglePhoneScreenBible.md)

[Hackererth Algorithms](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/)

[Topcoder Data Science Tutorials](https://www.topcoder.com/community/data-science/data-science-tutorials/)



commonly used algorithms and excercises coming soon!

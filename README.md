# Algorithms 101

# 面经
## Algorithm Inteview Questions
* [LC 401 Binary Watch](https://leetcode.com/problems/binary-watch/#/description)
* [LC 204 Count Primes](https://leetcode.com/problems/count-primes/#/description)
* Binary Index Trees and Segment Trees
  * [LC 303 Range Sum Query-Immutable](https://leetcode.com/problems/range-sum-query-immutable/#/description)
  * [LC 307 Range Sum Query](https://leetcode.com/problems/range-sum-query-mutable/#/description)
* [LC 218 Skyline Problem](https://leetcode.com/problems/the-skyline-problem/#/description)
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
* KMP
  * [LC 28 Implement strstr()](https://leetcode.com/problems/implement-strstr/#/description)
    
# Resources
[Google phone interviews](https://github.com/jeromejj/GooglePhoneScreenBible/blob/master/GooglePhoneScreenBible.md)

[Hackererth Algorithms](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/)

[Topcoder Data Science Tutorials](https://www.topcoder.com/community/data-science/data-science-tutorials/)



commonly used algorithms and excercises coming soon!

//
//  main.cpp
//  364. Nested List Weight Sum II
//
//  Created by Giriraj Saigal on 08/12/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 
 */
  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
 
class Solution {
public:
    int findMaxDepth(NestedInteger nestedInteger, int currDepth) {
        if(nestedInteger.isInteger()) {
            return currDepth;
        }
        
        vector<NestedInteger> list = nestedInteger.getList();
        
        int temp = 0;
        for(NestedInteger nI : list) {
            temp = max(findMaxDepth(nI, currDepth+1), temp);
        }
        
        return temp;
    }
    
    int solve(vector<NestedInteger>& nestedList, int maxDepth, int currDepth) {
        if(nestedList.size() == 0)
            return 0;
        
        int temp = 0;
        for(NestedInteger ni : nestedList) {
            if(ni.isInteger()) {
                temp += (maxDepth - currDepth + 1) * ni.getInteger();
            }else{
                temp += solve(ni.getList(), maxDepth, currDepth+1);
            }
        }
        
        return temp;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        
        int maxDepth = 0;
        for(NestedInteger nI : nestedList)
            maxDepth = max(findMaxDepth(nI, 1),maxDepth);
        
        return solve(nestedList, maxDepth, 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

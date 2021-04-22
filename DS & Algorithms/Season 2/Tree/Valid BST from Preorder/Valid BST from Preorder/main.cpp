//
//  main.cpp
//  Valid BST from Preorder
//
//  Created by Giriraj Saigal on 19/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;
  
    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;
  
    // Traverse given array
    for (int i=0; i<n; i++)
    {
        int t = pre[i];
        // If we find a node who is on right side
        // and smaller than root, return false
        if (t < root)
            return false;
  
        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<t)
        {
            root = s.top();
            s.pop();
        }
  
        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(t);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int pre[] = {17,10,5,9,8,7,6,20};
    int n = sizeof(pre)/sizeof(pre[0]);
    canRepresentBST(pre, n);
    return 0;
}

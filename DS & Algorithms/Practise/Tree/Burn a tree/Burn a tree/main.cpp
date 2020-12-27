//
//  main.cpp
//  Burn a tree
//
//  Created by Giriraj Saigal on 27/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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


 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

int height(TreeNode* A, int B, bool &found, int h, int &ans, int &level)
{
    if(A == NULL){
        return 0;
    }
    
    if(A->val == B) {
        level = h;
        found = true;
        return 1;
    }
    
    bool l = false;
    bool r = false;
    
    int lh = height(A->left, B, l, h+1, ans, level);
    int rh = height(A->right, B, r, h+1, ans, level);
    
    if(l) {
        ans = max(level - h + rh, ans);
    }else if(r){
        ans = max(level - h + lh, ans);
    }
    
    found = l || r;

    return lh > rh ? lh + 1 : rh + 1;
}

int solve(TreeNode* A, int B) {
    int ans = 0;
    int actualLevel;
    bool found = false;
    
    if(A->val == B)
        return 1;
        
    height(A, B, found, 0, ans, actualLevel);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

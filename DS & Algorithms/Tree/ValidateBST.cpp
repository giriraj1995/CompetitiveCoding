//
//  main.cpp
//  Validate a BST TRee
//
//  Created by Giriraj Saigal on 03/06/21.
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


//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

bool solve(TreeNode* p, long min, long max) {
        
        if(p == NULL)
            return true;
        
        long ele = p->val;
        
        if(ele > min && ele < max){
            bool x = solve(p->left, min, p->val);
            bool y = solve(p->right, p->val, max);
            return x & y;
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long min = (long)INT_MIN-1;
        long max = (long)INT_MAX+1;
        return solve(root,min,max);
    }

int main(int argc, const char * argv[]) {
`   
    return 0;
}

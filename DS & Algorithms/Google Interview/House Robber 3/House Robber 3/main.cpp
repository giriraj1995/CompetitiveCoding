//
//  main.cpp
//  House Robber 3
//
//  Created by Giriraj Saigal on 28/09/21.
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


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

int solve(TreeNode* p, bool take, map<pair<TreeNode*,bool>, int> &dp) {
        if(p == NULL)
            return dp[{p,take}] = 0;
        
        if(dp.find({p,take}) != dp.end())
            return dp[{p,take}];
        
        if(take) {
            int x = p->val+solve(p->left,false,dp)+solve(p->right,false,dp);
            int y = solve(p->left,true,dp)+solve(p->right,true,dp);
            return dp[{p,take}] = max(x,y);
        }else{
            int x = solve(p->left,true,dp)+solve(p->right,true,dp);
            return dp[{p,take}] = x;
        }
        
    }
    
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>, int> dp;
        return solve(root, true, dp);
    }

int main(int argc, const char * argv[]) {
    vector<int> x;
    x = {1,2,3,4};
    vector<int> y;
    y.push_back;
    return 0;
}

//
//  main.cpp
//  Level Order Search
//
//  Created by Giriraj Saigal on 02/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


//  Definition for binary tree

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
vector<vector<int> > levelOrder(TreeNode* A) {
    
    queue<pair<TreeNode*, int>> q;
    map<int, vector<int> > mp;
    
    vector<vector<int>> ans;
    
    if(A == NULL){
        return ans;
    }
    
    q.push({A, 0});
    
    while(q.size() > 0) {
        pair<TreeNode*, int> p = q.front();
        TreeNode* t = p.first;
        q.pop();
        int k = p.second;
        mp[k].push_back(t->val);
        
        if(t->left) {
            q.push({t->left, k+1});
        }
        
        if(t->right) {
            q.push({t->right, k+1});
        }
    }
    
    for(auto m : mp) {
        ans.push_back(m.second);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    TreeNode* A = new TreeNode(3);
    A->left = new TreeNode(9);
    A->right = new TreeNode(20);
    A->right->left = new TreeNode(15);
    A->right->right = new TreeNode(7);
    levelOrder(A);
    return 0;
}

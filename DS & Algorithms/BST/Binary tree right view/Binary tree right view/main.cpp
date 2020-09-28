//
//  main.cpp
//  Binary tree right view
//
//  Created by Giriraj Saigal on 28/09/20.
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

 // Definition for binary tree
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

vector<int> solve(TreeNode* A) {
    map<TreeNode*, int> mp;
    map<int, vector<int>> u;
    mp[A] = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        
        TreeNode* temp = q.front();
        int k = mp[temp];
        u[k].push_back(temp->val);
        q.pop();
        
        if(temp->left){
            q.push(temp->left);
            mp[temp->left] = k + 1;
        }
        
        if(temp->right){
            q.push(temp->right);
            mp[temp->right] = k + 1;
        }
    }
    
    vector<int> ans;
    
    for(auto j : u){
        vector<int> r = j.second;
        ans.push_back(r[r.size()-1]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

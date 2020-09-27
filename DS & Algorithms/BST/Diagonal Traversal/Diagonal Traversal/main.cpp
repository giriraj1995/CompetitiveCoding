//
//  main.cpp
//  Diagonal Traversal
//
//  Created by Giriraj Saigal on 27/09/20.
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
 
vector<int> solve(TreeNode* A) {
    
    // queue<TreeNode*> q;
    // q.push(A);
    // unordered_map<TreeNode*, int> mp;
    // vector<int> ans;
    // map<int, vector<int>> u;

    // mp[A] = 0;
    
    // while(!q.empty()){
        
    //     TreeNode* temp = q.front();
    //     q.pop();
    //     int k = mp[temp];
    //     u[k].push_back(temp->val);
        
    //     if(temp->left){
    //         q.push(temp->left);
    //         mp[temp->left] = k + 1;
    //     }

    //     if(temp->right){
    //         q.push(temp->right);
    //         mp[temp->right] = k;
    //     }

    // }
    
    unordered_map<TreeNode*, int> mp;
    vector<int> ans;
    map<int, vector<int>> u;
    stack<TreeNode*> s;
    TreeNode* temp = A;
    mp[temp] = 0;
    
    while(temp || !s.empty()){
        
        if(temp){
            s.push(temp);
            int k = mp[temp];
            u[k].push_back(temp->val);
            if(temp->left){
                mp[temp->left] = k + 1;
            }
            temp = temp->left;
        }else{
            temp = s.top();
            s.pop();
            int k = mp[temp];
            if(temp->right){
                mp[temp->right] = k;
            }
            temp = temp->right;
        }
    }
    
    for(auto h : u){
        vector<int> x = h.second;
        
        for(int e : x){
            ans.push_back(e);
        }
        
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(29);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(28);
    root->left->right = new TreeNode(28);
    root->right->left = new TreeNode(29);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(4);
    
    
    vector<int> x = solve(root);
    for(int i : x){
        cout<<i<<" ";
    }
    
    cout<<endl;
    return 0;
}

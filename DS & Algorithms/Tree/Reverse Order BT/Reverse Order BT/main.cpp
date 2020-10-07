//
//  main.cpp
//  Reverse Order BT
//
//  Created by Giriraj Saigal on 07/10/20.
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
    
    queue<TreeNode*> q;
    
    vector<int> ans;
    if(!A){
        return ans;
    }
    
    q.push(A);
    
    while(q.size() > 0){
        
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        
        if(temp->right){
            q.push(temp->right);
        }
        
        if(temp->left){
            q.push(temp->left);
        }
        
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

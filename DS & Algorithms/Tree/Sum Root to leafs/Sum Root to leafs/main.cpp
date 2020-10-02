//
//  main.cpp
//  Sum Root to leafs
//
//  Created by Giriraj Saigal on 02/10/20.
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
 
 
void check(TreeNode* A, vector<int> paths, vector<int> &ans){
    
    if(A==NULL){
        return;
    }
        
    int t = paths[0];
    paths[0] = 10*t + A->val;
    
    if(A->left == NULL && A->right == NULL){
        ans.push_back(paths[0]);
        return;
    }
    
    check(A->left, paths, ans);
    check(A->right, paths, ans);
    
}
int sumNumbers(TreeNode* A) {
    
    vector<int> ans;
    vector<int> paths(1, 0);
    check(A, paths, ans);
    
    long long int sum = 0;
    
    for(auto i : ans){
        sum += i;
    }
    
    return sum % 1003;
    
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<sumNumbers(root)<<endl;
    return 0;
}

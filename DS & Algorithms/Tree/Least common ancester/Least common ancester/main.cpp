//
//  main.cpp
//  Least common ancester
//
//  Created by Giriraj Saigal on 04/10/20.
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


void preorder(TreeNode* root, vector<int> current, vector<int>& answer, int key)
{
    if(root == NULL) return;
    current.push_back(root->val);
    if(root->val == key)
    {
        for(auto& c : current)
            answer.push_back(c);
        return;
    }
    preorder(root->left, current, answer, key);
    preorder(root->right, current, answer, key);
    
}
int lca(TreeNode* A, int B, int C)
{
    vector<int> path_B, path_C, current;
    preorder(A, current, path_B, B);
    preorder(A, current, path_C, C);
    int answer = -1;
    for(int i = 0, j = 0; i<path_B.size() && j<path_C.size(); i++, j++)
    {
        if(path_B[i] == path_C[j])
            answer = path_B[i];
    }
    return answer;
}

void preorder1(TreeNode* A, int B, vector<int> &path){
    
    if(A == NULL)
        return;
        
    path.push_back(A->val);
    if(A->val == B){
        return;
    }
    preorder1(A->left, B, path);
    preorder1(A->right, B, path);
}

int lca1(TreeNode* A, int B, int C) {
    
    int ans = -1;
    vector<int> x;
    vector<int> y;
    int i,j;
    
    preorder1(A, B, x);
    preorder1(A, C, y);
    
    for(i = 0, j = 0 ; i < x.size() && j < y.size() ; i++, j++){
        if(x[i] == y[j])
            ans = x[i];
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

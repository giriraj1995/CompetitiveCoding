//
//  main.cpp
//  CreateTree from Post and Inorder
//
//  Created by Giriraj Saigal on 06/10/20.
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
 
 
TreeNode* solve(vector<int> A, vector<int> B){
    
    if(B.size() == 0 || A.size() == 0){
        return NULL;
    }
    
    int x;
    int i;
    int p;
    for(i = B.size()-1; i >= 0; i--){
        x = B[i];
        for(p = 0; p < A.size(); p++){
            if(A[p] == x){
                break;
            }
        }
        if(A[p] == x)
            break;
    }
    
    TreeNode* temp = new TreeNode(x);
    vector<int> BN(B.begin(), B.begin() +i);
    vector<int> l(A.begin(), A.begin() + p);
    vector<int> r(A.begin() + p + 1, A.end());
    
    temp->left = solve(l, BN);
    temp->right = solve(r, BN);
    
    return temp;
    
}
TreeNode* buildTree(vector<int> A, vector<int> B) {
    
    return solve(A, B);
}

TreeNode* buildTree1(vector<int> A, vector<int> B) {
    
    if(A.size() == 0 || B.size() == 0)
        return NULL;
        
    int x = B[B.size() - 1];
    
    TreeNode* temp = new TreeNode(x);
    
    int index = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == x)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
        return NULL;
        
    vector<int> left(A.begin(), A.begin()+index);
    vector<int> right(A.begin() + index + 1, A.end());
    
    vector<int> left1(B.begin(), B.begin() + index);
    vector<int> right1(B.begin() + index, B.end()-1);
    
    temp->left = buildTree1(left, left1);
    temp->right = buildTree1(right, right1);
    
    return temp;
}



int main(int argc, const char * argv[]) {
    TreeNode* node = buildTree1({1,3,2,4,6,5,7}, {1,2,3,6,7,5,4});
    return 0;
}

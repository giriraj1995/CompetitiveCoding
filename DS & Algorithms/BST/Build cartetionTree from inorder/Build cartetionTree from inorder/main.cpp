//
//  main.cpp
//  Build cartetionTree from inorder
//
//  Created by Giriraj Saigal on 05/10/20.
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
 
 
TreeNode* solve(vector<int> A, int i ,int j){
    
    TreeNode* temp = NULL;
    
    if(i <= j){
        
        int ans = INT_MIN;
        int p;
        
        for(int k = i; k <= j ; k++){
            if(ans < A[k]){
                p = k;
                ans = A[k];
            }
        }
        
        temp = new TreeNode(A[p]);
        
        temp->left = solve(A, i, p-1);
        temp->right = solve(A, p+1, j);
        
    }
    
    return temp;

}
TreeNode* buildTree(vector<int> &A) {
    
    return solve(A, 0, A.size()-1);
    
}

int main(int argc, const char * argv[]) {
    vector<int> A= {1,8,4,9,3,7,10,-4,-1,-7};
    TreeNode* node = solve(A, 0, A.size()-1);
    return 0;
}

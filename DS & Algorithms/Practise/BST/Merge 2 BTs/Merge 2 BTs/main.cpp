//
//  main.cpp
//  Merge 2 BTs
//
//  Created by Giriraj Saigal on 13/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>

struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 
TreeNode* make(TreeNode* A, TreeNode* B) {
    
    if(A == NULL && B == NULL) {
        return NULL;
    }
    
    int x = 0, y = 0;
    
    if(A != NULL) {
        x = A->val;
    }
    
    if(B != NULL) {
        y = B->val;
    }
    
    TreeNode* node = new TreeNode(x+y);
    
    if(A == NULL && B != NULL) {
        node->left = make(NULL, B->left);
        node->right = make(NULL, B->right);
    }else if(A != NULL && B == NULL) {
        node->right = make(A->right, NULL);
        node->left = make(A->left, NULL);
    }else{
        node->left = make(A->left, B->left);
        node->right = make(A->right, B->right);
    }
    
    return node;
}
TreeNode* solve(TreeNode* A, TreeNode* B) {
    return make(A, B);
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

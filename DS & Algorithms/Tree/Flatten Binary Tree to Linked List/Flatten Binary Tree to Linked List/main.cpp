//
//  main.cpp
//  Flatten Binary Tree to Linked List
//
//  Created by Giriraj Saigal on 13/06/21.
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


// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

TreeNode* returnRigthmost(TreeNode* A) {
    if(A == NULL)
        return NULL;
        
    while(A->right != NULL){
        A = A->right;
    }
    
    return A;
}

TreeNode* solve(TreeNode* A) {
    if(A == NULL)
        return NULL;
    
    TreeNode* temp = returnRigthmost(A->left);
    TreeNode* ri = A->right;
    
    if(temp != NULL) {
        temp->right = ri;
        A->right = A->left;
    }
    
    A->left = NULL;
    A->right = solve(A->right);
    
    return A;
}

TreeNode* flatten(TreeNode* A) {
    return solve(A);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

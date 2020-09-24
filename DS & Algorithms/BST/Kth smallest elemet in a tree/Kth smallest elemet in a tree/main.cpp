//
//  main.cpp
//  Kth smallest elemet in a tree
//
//  Created by Giriraj Saigal on 24/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

//Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
int kthsmallest(TreeNode* A, int B) {
    
    stack<TreeNode*> s;
    TreeNode* temp = A;
    int k = 1;
    
    while(!s.empty() || temp != NULL){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }else{
            temp = s.top();
            
            s.pop();
            
            if(k == B){
                return temp->val;
            }
            k++;
            temp = temp->right;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

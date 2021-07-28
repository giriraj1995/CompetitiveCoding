//
//  main.cpp
//  2 Sum BST
//
//  Created by Giriraj Saigal on 24/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//


#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
int t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> s;
    TreeNode* t = A;
    unordered_map<int, bool> u;
    
    while(t != NULL || !s.empty()){
        
        if(t != NULL){
            if(u.find(B - t->val) != u.end()){
                return 1;
            }else{
                u[t->val] = true;
            }
            
            s.push(t);
            t = t->left;
        }else{
            
            t = s.top();
            s.pop();
            t = t->right;
            
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

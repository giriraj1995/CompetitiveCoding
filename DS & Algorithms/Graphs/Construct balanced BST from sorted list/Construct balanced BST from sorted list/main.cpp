//
//  main.cpp
//  Construct balanced BST from sorted list
//
//  Created by Giriraj Saigal on 12/12/20.
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
 

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

TreeNode* constructTreeFromArray(ListNode* A) {
    
    if(!A)
        return NULL;
        
    if(!A->next)
        return new TreeNode(A->val);
        
    ListNode* slow = A;
    ListNode* fast = A->next;
    
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* mid = slow->next;
    slow->next = NULL;
    
    TreeNode* root = new TreeNode(mid->val);
    root->left = constructTreeFromArray(A);
    root->right = constructTreeFromArray(mid->next);
    return root;
    
    // if(i > j)
    //     return NULL;
    
    // int mid = i + (j-i)/2;
    // TreeNode* root = new TreeNode(arr[mid]);
    // root->left = constructTreeFromArray(arr, i, mid-1);
    // root->right = constructTreeFromArray(arr, mid+1, j);
    // return root;
}
TreeNode* sortedListToBST(ListNode* A) {
    // vector<int> arr;
    
    // while(A) {
    //     arr.push_back(A->val);
    //     A = A->next;
    // }
    
    // if(arr.size() == 0)
    //     return NULL;
        
    return constructTreeFromArray(A);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

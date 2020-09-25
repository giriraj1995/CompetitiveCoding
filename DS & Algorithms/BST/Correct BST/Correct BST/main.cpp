//
//  main.cpp
//  Correct BST
//
//  Created by Giriraj Saigal on 25/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 
int count(TreeNode* A){
    
    if(A == NULL)
        return 0;
        
    int l = count(A->left);
    int r = count(A->right);
    
    return l + r + 1;
}
vector<int> recoverTree(TreeNode* A) {
    
    vector<int> ans(2,-1);
    TreeNode* temp = A;
    stack<TreeNode*> s;
    int i = 0;
    vector<int> arr(count(A));
    while(s.size() > 0 || temp != NULL){
        
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }else{
            temp = s.top();
            s.pop();
            arr[i] = temp->val;
            i++;
            temp = temp->right;
        }
    }
    
    
    int flag = 0;
    int c;
    for(i = 0; i < arr.size()-1; i++){
        
        if(arr[i] > arr[i+1]){
            if(flag == 0){
                ans[1] = arr[i];
                c = i;
                flag = 1;
            }
            else if(flag == 1){
                ans[0] = arr[i+1];
            }
        }
    }
    
    if(ans[0] == -1 && flag == 1){
        ans[0] = arr[c+1];
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    TreeNode* t = new TreeNode(76);
    t->left = new TreeNode(77);
    recoverTree(t);
    return 0;
}

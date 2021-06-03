//
//  main.cpp
//  Burn a TRee
//
//  Created by Giriraj Saigal on 03/06/21.
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


//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

queue<pair<TreeNode*,int>> q;
map<int, vector<int>> ans;

int find(TreeNode* A, int B,int level) {
    if(A == NULL)
        return 0;
        
    if(A->val == B) {
        ans[0].push_back(A->val);
        level = 1;
        if(A->left)
            q.push({A->left,1});
        
        if(A->right)
            q.push({A->right,1});
            
        return 1;
    }
    
    int a = find(A->left, B,level);
    
    if(a == 1) {
        while(q.size() > 0) {
            int t = q.front().second;
            TreeNode* temp = q.front().first;
            q.pop();
            
            ans[t].push_back(temp->val);
            
            if(temp->left)
                q.push({temp->left,t+1});
            
            if(temp->right)
                q.push({temp->right, t+1});
        }
        
        ans[level].push_back(A->val);
        level++;
        
        if(A->right)
            q.push({A->right,level});
            
        return 1;
    }
    
    int b = find(A->right, B,level);
    
    if(b == 1) {
        while(q.size() > 0) {
            int t = q.front().second;
            TreeNode* temp = q.front().first;
            q.pop();
            
            ans[t].push_back(temp->val);
            
            if(temp->left)
                q.push({temp->left,t+1});
            
            if(temp->right)
                q.push({temp->right, t+1});
        }
        
        ans[level].push_back(A->val);
        level++;
        
        if(A->left)
            q.push({A->left,level});
            
        return 1;
    }
    
    return 0;
}

int solve(TreeNode* A, int B) {
    while(q.size() > 0)
        q.pop();
    
    int level = 0;
    int x = find(A,B,level);
    
    while(q.size() > 0) {
        int level = q.front().second;
        TreeNode* temp = q.front().first;
        q.pop();
        
        ans[level].push_back(temp->val);
        
        if(temp->left)
            q.push({temp->left,level+1});
        
        if(temp->right)
            q.push({temp->right, level+1});
    }
    
    return ans.size();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

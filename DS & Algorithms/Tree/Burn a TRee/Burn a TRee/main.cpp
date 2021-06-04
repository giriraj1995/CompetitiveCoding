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
 
TreeNode* createTree(vector<int> x) {
    if(x.size() == 0)
        return NULL;

    TreeNode* root = new TreeNode(x[0]);
    
    queue<TreeNode* > q;
    q.push(root);
    
    for(int i = 1; i < x.size(); i = i + 2) {
        TreeNode* r = q.front();
        q.pop();
        int l = x[i];
        
        int ri = -1;
        if(i+1 < x.size())
            ri = x[i+1];
        
        if(l != -1){
            r->left = new TreeNode(l);
            q.push(r->left);
        }
        
        if(ri != -1){
            r->right = new TreeNode(ri);
            q.push(r->right);
        }
    }
    
    return root;
}

queue<pair<TreeNode*,int>> q;
map<int, vector<int>> ans;

int find(TreeNode* A, int B,int &level) {
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
    
    return ans.size()-1;
}


int main(int argc, const char * argv[]) {
    TreeNode* g = createTree({1 ,2 ,8 ,-1 ,-1 ,4 ,-1 ,-1 ,-1  });
    cout<<solve(g,2)<<endl;
    return 0;
}

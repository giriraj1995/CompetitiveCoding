//
//  main.cpp
//  SerializeDeserilzieBT
//
//  Created by Giriraj Saigal on 04/10/21.
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
/**
Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void solve(TreeNode* root, string &ans) {
    if(root == NULL)
    {
        ans += "X ";
        return;
    }
    
    ans += to_string(root->val) + " ";
    solve(root->left, ans);
    solve(root->right,ans);
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL)
        return "";
    
    string ans = "";
    solve(root, ans);
    
    return ans;
}

TreeNode* solverev(TreeNode* p, queue<int> &q) {
    int x = q.front();
    q.pop();
    
    if(x == INT_MIN)
        return NULL;
    
    p = new TreeNode(x);
    p->left = solverev(p->left, q);
    p->right = solverev(p->right, q);
    
    return p;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size() == 0)
        return NULL;
    
    queue<int> q;
    string x = "";
    for(int i = 0; i < data.size(); i++) {
        if(data[i] == ' ') {
            if(x == "X")
                q.push(INT_MIN);
            else
                q.push(stoi(x));
            x = "";
        }else{
            x += data[i];
        }
    }
    
    TreeNode* root = NULL;
    return solverev(root, q);
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, const char * argv[]) {
    TreeNode* x = new TreeNode(1);
    x->right = new TreeNode(2);
    x->right->left = new TreeNode(3);
    x->right->right = new TreeNode(4);
    
    string g = serialize(x);
    TreeNode* temp = deserialize(g);
    return 0;
}

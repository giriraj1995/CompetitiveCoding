//
//  main.cpp
//  450. Delete Node in a BST
//
//  Created by Giriraj Saigal on 22/11/21.
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rightMost(TreeNode* p) {
        if(p == NULL)
            return p;
        
        while(p->right != NULL)
            p = p->right;
        
        return p;
    }
    
    TreeNode* solve(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;

        if(root->val == key) {
            if(root->left == NULL && root->right == NULL)
                return NULL;
            
            if(root->right == NULL)
                return root->left;
            
            if(root->left == NULL)
                return root->right;
                        
            TreeNode* x = rightMost(root->left);
            
            if(x == NULL)
                return root->right;
            
            TreeNode* y = new TreeNode(x->val);
            y->right = root->right;
            y->left = solve(root->left, x->val);
            
            return y;
        }else{
            root->left = solve(root->left, key);
            root->right = solve(root->right, key);
            return root;
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root, key);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

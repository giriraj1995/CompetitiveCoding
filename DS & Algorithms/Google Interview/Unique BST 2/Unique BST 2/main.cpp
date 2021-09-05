//
//  main.cpp
//  Unique BST 2
//
//  Created by Giriraj Saigal on 05/09/21.
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
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
                                                
vector<TreeNode*> solve(int p, int q) {
        if(p > q)
            return {};
        
        if(p == q){
            return {new TreeNode(p)};
        }
        
        vector<TreeNode*> ans;
        for(int k = p; k <= q; k++) {
            vector<TreeNode*> left = solve(p,k-1);
            vector<TreeNode*> right = solve(k+1,q);
                        
            if(left.size() == 0) {
                for(int i = 0; i < right.size(); i++){
                    TreeNode* root = new TreeNode(k);
                    root->right = right[i];
                    ans.push_back(root);
                }
            }else if(right.size() == 0){
                for(int i = 0; i < left.size(); i++){
                    TreeNode* root = new TreeNode(k);
                    root->left = left[i];
                    ans.push_back(root);
                }
            }else{
                for(int i = 0; i < left.size(); i++) {
                    for(int j = 0; j < right.size(); j++) {
                        TreeNode* root = new TreeNode(k);
                        root->left = left[i];
                        root->right = right[j];
                        ans.push_back(root);
                    }
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }

int main(int argc, const char * argv[]) {
    vector<TreeNode*> x = generateTrees(6);
    return 0;
}

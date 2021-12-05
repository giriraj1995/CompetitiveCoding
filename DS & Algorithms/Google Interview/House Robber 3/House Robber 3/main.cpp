//
//  main.cpp
//  House Robber 3
//
//  Created by Giriraj Saigal on 05/12/21.
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
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    map<pair<TreeNode*, bool>, int> dp;
    int rob(TreeNode* root, bool canRob) {
        if(root == NULL)
            return 0;
        
        pair<TreeNode*, bool> key = {root, canRob};
        
        if(dp.count(key))
            return dp[key];
        
        if(canRob == true) {
            int leftF = rob(root->left, false);
            int rightF = rob(root->right, false);
            
            int leftT = rob(root->left, true);
            int rightT = rob(root->right, true);
            
            int x = root->val + leftF + rightF;
            int y = leftT + rightT;
            
            return dp[key] = max(x,y);
        }else{
            int leftT = rob(root->left, true);
            int rightT = rob(root->right, true);
            
            return dp[key] = leftT + rightT;
        }
    }
    
    int rob(TreeNode* root) {
        dp.clear();
        return rob(root, true);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

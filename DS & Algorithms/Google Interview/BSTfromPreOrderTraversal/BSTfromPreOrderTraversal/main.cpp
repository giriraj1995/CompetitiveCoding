//
//  main.cpp
//  BSTfromPreOrderTraversal
//
//  Created by Giriraj Saigal on 13/10/21.
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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

TreeNode* bstFromPreorder(vector<int> preorder) {
        int n = preorder.size();
        
        if(n == 0)
            return NULL;
        
        TreeNode* x = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(x);
        
        for(int i = 1; i < n; i++) {
            if(preorder[i] < s.top()->val) {
                TreeNode* temp = s.top();
                temp->left = new TreeNode(preorder[i]);
                s.push(temp->left);
            }else{
                TreeNode* prev = NULL;
                while(s.size() > 0 && preorder[i] > s.top()->val) {
                    prev = s.top();
                    s.pop();
                }
                prev->right = new TreeNode(preorder[i]);
                s.push(prev->right);
            }
        }
        
        return x;
    }

int main(int argc, const char * argv[]) {
    bstFromPreorder({8,5,1,7,10,12});
    return 0;
}

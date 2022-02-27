//
//  main.cpp
//  662. Maximum Width of Binary Tree
//
//  Created by Giriraj Saigal on 27/02/22.
//

#include <iostream>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long ans = 0;
        
        while(q.size() > 0) {
            int s = q.size();
            long long low = q.front().second;
            long long mn = 0, mx = 0;
            for(int i = 0; i < s; i++) {
                pair<TreeNode*,long long> p = q.front();
                TreeNode* x = p.first;
                long long cur_index = p.second - low + 1;
                q.pop();
                
                if(mn == 0) {
                    mn = cur_index;
                }
                
                if(i == s-1) {
                    mx = cur_index;
                }
                
                
                if(x->left) {
                    q.push({x->left,cur_index*2});
                }
                
                if(x->right){
                    q.push({x->right,cur_index*2+1});
                }
            }
            
            ans = max(ans, mx - mn + 1);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << widthOfBinaryTree(NULL) << endl;
    return 0;
}

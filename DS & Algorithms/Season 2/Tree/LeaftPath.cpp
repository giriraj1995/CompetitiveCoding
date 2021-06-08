#include <iostream>

 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

void solve(long long sum,TreeNode* A, int B, bool &ans) {
    if(A == NULL)
        return;
    
    if(ans == true)
        return;
        
    if(A->left == NULL && A->right == NULL) {
        if(sum + (long long)A->val == B){
            ans = true;
        }
        return;
    }
    
    solve(sum + A->val, A->left, B, ans);
    solve(sum + A->val, A->right, B, ans);
}

int hasPathSum(TreeNode* A, int B) {
    bool ans = false;
    solve(0,A,B,ans);
    return ans;
}

int main(){
    return 0;
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;
int solve(TreeNode* A) {
    if(A == NULL)
        return 0;
    
    int ele = A->val;
    int a = solve(A->left);
    int b = solve(A->right);
    
    ans = max(ans, ele);
    ans = max(ans, a+ele);
    ans = max(ans, b+ele);
    ans = max(ans, a+b+ele);
    
    return max(a+ele, b+ele);
}

int Solution::maxPathSum(TreeNode* A) {
    if(A == NULL)
        return -1;
    
    ans = INT_MIN;
    solve(A);
    
    return ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* solve(ListNode* A) {
    if(A == NULL)
        return NULL;
        
    ListNode* slow = A;
    ListNode* fast = A->next;
    ListNode* prev = NULL;
    
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(prev == NULL) {
        TreeNode* p = new TreeNode(slow->val);
        p->left = NULL;
        p->right = solve(slow->next);
        return p;
    }
    
    TreeNode* p = new TreeNode(slow->val);
    prev->next = NULL;
    p->left = solve(A);
    p->right = solve(slow->next);
    
    return p;    
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    return solve(A);
}

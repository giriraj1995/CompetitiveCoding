/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* ans = NULL;
        ListNode* ans1 = NULL;
        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                if(ans == NULL){
                    ans = left;
                    ans1 = ans;
                }else{
                    ans->next = left;
                    ans = ans->next;
                }
                
                left = left->next;
            }else{
                if(ans == NULL){
                    ans = right;
                    ans1 = ans;
                }else{
                    ans->next = right;
                    ans = ans->next;
                }
                
                right = right->next;
            }
        }
        
        if(left != NULL)
            ans->next = left;
        
        if(right != NULL)
            ans->next = right;
        
        return ans1;
    }
    
    ListNode* solve(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(prev == NULL)
            return head;
        
        prev->next = NULL;
        ListNode* left = solve(head);
        ListNode* right = solve(slow);
        
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return head;
        
        return solve(head);
    }
};

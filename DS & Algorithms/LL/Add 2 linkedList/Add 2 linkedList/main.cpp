//
//  main.cpp
//  Add 2 linkedList
//
//  Created by Giriraj Saigal on 05/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0;
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    
    while(A && B) {
        p->next = new ListNode((carry+A->val+B->val)%10);
        carry = (carry+A->val+B->val)/10;
        A=A->next;
        B=B->next;
        p=p->next;
    }
    
    while(A) {
        p->next = new ListNode((carry+A->val)%10);
        carry = (carry+A->val)/10;
        A=A->next;
        p=p->next;
    }
    
    while(B) {
        p->next = new ListNode((carry+B->val)%10);
        carry = (carry+B->val)/10;
        B=B->next;
        p=p->next;
    }
    
    if(carry != 0) {
        p->next = new ListNode(carry);
    }
    
    return head->next;
}


int main(int argc, const char * argv[]) {
    ListNode* h = new ListNode(9);
    h->next = new ListNode(9);
    h->next->next = new ListNode(1);
    
    ListNode* h2 = new ListNode(1);
    
    addTwoNumbers(h, h2);
    return 0;
}

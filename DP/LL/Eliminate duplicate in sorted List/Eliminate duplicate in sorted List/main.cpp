//
//  main.cpp
//  Eliminate duplicate in sorted List
//
//  Created by Giriraj Saigal on 02/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>

//  Definition for singly-linked list.
struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* deleteDuplicates(ListNode* A) {
    
    if(A == NULL)
        return A;
        
    int val = A->val;
    
    A->next = deleteDuplicates(A->next);
    
    if(A->next != NULL){
        if(A->next->val == val)
            return A->next;
    }
    
    return A;
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(1);
    a->next->next = new ListNode(2);
    a->next->next->next = new ListNode(2);
    a->next->next->next->next = new ListNode(3);

    a = deleteDuplicates(a);
    return 0;
}

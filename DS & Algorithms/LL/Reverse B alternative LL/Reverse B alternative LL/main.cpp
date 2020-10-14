//
//  main.cpp
//  Reverse B alternative LL
//
//  Created by Giriraj Saigal on 14/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
using namespace std;

// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* insertLL(ListNode* head, int x){
    
    if(head == NULL){
        return new ListNode(x);
    }
    
    ListNode* p = head;
    
    while(p->next){
        p = p->next;
    }
    
    p->next = new ListNode(x);
    
    return head;
}
 
ListNode* reverseLL(ListNode* A, int B, bool x){
    
    if(A == NULL)
        return NULL;
    
    if(x == false){
        
        ListNode* temp = A;
        int i = 0;
        while(++i < B){
            if(temp == NULL){
                return A;
            }else{
                temp = temp->next;
            }
        }
        
        if(temp == NULL)
            return A;
        
        temp->next = reverseLL(temp->next, B, !x);
        return A;
    }else{
        
        ListNode* curr = A;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        int i = 0;
        while(i < B){
            if(curr == NULL){
                return prev;
            }else{
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            i++;
        }
        
        A->next = curr;
        A->next = reverseLL(A->next, B, !x);
        return prev;
    }
    
}
ListNode* solve(ListNode* A, int B) {
    
    bool reverse = true;
    return reverseLL(A, B, reverse);
    
}

int main(int argc, const char * argv[]) {
    ListNode* head = NULL;
    head = insertLL(head, 3);
    head = insertLL(head, 4);
    head = insertLL(head, 7);
    head = insertLL(head, 5);
    head = insertLL(head, 6);
    head = insertLL(head, 6);
    head = insertLL(head, 15);
    head = insertLL(head, 61);
    head = insertLL(head, 16);

    head = solve(head, 3);
    return 0;
}

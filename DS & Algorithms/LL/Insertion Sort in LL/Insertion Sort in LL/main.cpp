//
//  main.cpp
//  Insertion Sort in LL
//
//  Created by Giriraj Saigal on 06/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

ListNode* solve(ListNode *p, ListNode *ins) {
    ListNode *head = p;
    
    if(p->val > ins->val) {
        ins->next = p;
        return ins;
    }
    
    ListNode* prev;
    while(p != NULL && p->val < ins->val){
        prev = p;
        p = p->next;
    }
    
    if(p == NULL) {
        prev->next = new ListNode(ins->val);
        return head;
    }
    
    ListNode* temp = new ListNode(ins->val);
    prev->next = temp;
    temp->next = p;
    
    return head;
    
}
ListNode* insertionSortList(ListNode* A) {
    ListNode *head = new ListNode(INT_MIN);
    while(A) {
        head = solve(head, A);
        A = A->next;
    }
    return head->next;
}


int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(5);
    head->next = new ListNode(9);
    head->next->next = new ListNode(7);
    
    insertionSortList(head);
    return 0;
}

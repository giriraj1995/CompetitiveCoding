//
//  main.cpp
//  Reorder
//
//  Created by Giriraj Saigal on 06/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* reverse(ListNode *A){
    
    ListNode* c = A;
    ListNode* n = NULL;
    ListNode* p = NULL;
    
    while(c != NULL){
        n = c->next;
        c->next = p;
        
        p = c;
        c = n;
    }
    
    return p;
}

int getLength(ListNode * A){
    if(A == NULL)
        return 0;
    else
        return 1 + getLength(A->next);
}

ListNode* reorderList(ListNode* A) {
    
    int n = getLength(A);
    int k;
    
    if(n & 1){
        k = (n + 1)/2;
    }else{
        k = n/2;
    }
    
    ListNode* head1 = A;
    
    vector<int> p;
    
    while(head1){
        p.push_back(head1->val);
        head1 = head1->next;
    }
    
    vector<int> q;

    
    ListNode* head2 = reverse(A);
    
    while(head2){
        q.push_back(head2->val);
        head2 = head2->next;
    }
    
    ListNode* newHead = new ListNode(-1);
    ListNode* temp = newHead;
    int i = 0;
    
    while(k--){
        
        if(k == 0 && q[i] == p[i]){
            temp->next = new ListNode(q[i]);
            break;
        }
        
        temp->next = new ListNode(p[i]);
        temp = temp->next;
        temp->next = new ListNode(q[i]);
        temp = temp->next;
        
        i++;
    }
    
    return newHead->next;
}


int main(int argc, const char * argv[]) {
    ListNode* x = new ListNode(1);
    x->next = new ListNode(2);
    x->next->next = new ListNode(3);
    x->next->next->next = new ListNode(4);
    x->next->next->next->next = new ListNode(5);

    x = reorderList(x);

    return 0;
}

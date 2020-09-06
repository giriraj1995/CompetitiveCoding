//
//  main.cpp
//  Reverse k list
//
//  Created by Giriraj Saigal on 04/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* reverseBtoC(ListNode* A, int a, int b){
    
    ListNode* p = NULL;
    ListNode *q = NULL;
    ListNode *r = NULL;
    
    q = A;
    int k = a;
    
    while(--k){
        p = q;
        q = q->next;
    }
    
    k = b;
    r = A;
    
    while(k--){
        r = r->next;
    }
    
    ListNode* qn = NULL;
    ListNode* qp = r;
    
    while(q != r){
        qn=q->next;
        
        q->next=qp;
        
        qp = q;
        q = qn;
    }
    
    p->next = qp;
    
    return A;
}

ListNode* reverseBetween(ListNode* A, int B, int C) {

    return reverseBtoC(A,B,C);
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);

    a = reverseBetween(a,2,4);
    
    return 0;
}




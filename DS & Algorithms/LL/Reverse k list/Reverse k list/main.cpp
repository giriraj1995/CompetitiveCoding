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
ListNode* reverseList(ListNode* A, int B) {
    
    if(A == NULL)
        return A;
        
    int k = B;
    ListNode* t = A;
    
    while(k){
      t = t->next;
      k--;
    }
    
    t = reverseList(t,B);
    
    ListNode* cur= A;
    ListNode* n = NULL;
    ListNode* p = t;
    
    k = B;
    
    while(k){
        
        n = cur->next;
        
        cur->next = p;
        
        p = cur;
        cur = n;
        k--;
    }
    
    return p;
    
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(6);
    a->next = new ListNode(10);
    a->next->next = new ListNode(0);
    a->next->next->next = new ListNode(3);
    a->next->next->next->next = new ListNode(4);
    a->next->next->next->next->next = new ListNode(8);

    a = reverseList(a,3);
    
    return 0;
}

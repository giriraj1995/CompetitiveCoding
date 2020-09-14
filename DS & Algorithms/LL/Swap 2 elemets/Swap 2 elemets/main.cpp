//
//  main.cpp
//  IsPalindrom
//
//  Created by Giriraj Saigal on 03/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* swapPairs(ListNode* A) {

    if(A == NULL || A->next == NULL){
        return A;
    }
    
    A->next->next = swapPairs(A->next->next);
    
    ListNode* cur = A;
    ListNode* t = A->next;
    
    cur->next = t->next;
    t->next = cur;
    
    return A = t;
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a = swapPairs(a);
    return 0;
}


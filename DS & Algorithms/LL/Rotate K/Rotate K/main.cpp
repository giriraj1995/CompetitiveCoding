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
int getLenght(ListNode* a){
    
    if(a == NULL)
        return 0;
        
    return getLenght(a->next) + 1;
    
}

ListNode* rotate(ListNode* A, int B){
    
    int k = B;
    
    ListNode* head = A;
    ListNode* cur;
    ListNode* n = A;

    while(k){
        cur = n;
        n = n->next;
        k--;
    }
    
    ListNode* temp = n;
    
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head;
    cur->next = NULL;
    
    return n;
}

ListNode* rotateRight(ListNode* A, int B) {
    int n = getLenght(A);
    
    if(B % n == 0)
        return A;
        
    B = B % n;
    
    return rotate(A,B);
    
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next = new ListNode(6);

    a = rotateRight(a,5);
    
    return 0;
}


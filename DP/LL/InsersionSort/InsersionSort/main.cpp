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

ListNode* insert(ListNode* x, int val){
    
    if(x == NULL){
        ListNode* temp = new ListNode(val);
        return temp;
    }
        
    if(val <= x->val){
        ListNode* temp = new ListNode(val);
        temp->next = x;
        return temp;
    }
    
    x->next = insert(x->next, val);
    
    return x;
}

ListNode* insertionSortList(ListNode* A) {
    
    int n = getLenght(A);
    
    if(n == 1 || n == 0)
        return A;
        
    ListNode* list= NULL;
    
    while(A != NULL){
        list = insert(list, A->val);
        A = A->next;
    }
    
    return list;
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(4);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(9);
    a->next->next->next->next = new ListNode(1);
    a->next->next->next->next->next = new ListNode(0);

    a = insertionSortList(a);
    
    return 0;
}



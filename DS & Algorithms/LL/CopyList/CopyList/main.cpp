//
//  main.cpp
//  CopyList
//
//  Created by Giriraj Saigal on 18/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

 // Definition for singly-linked list.
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
RandomListNode* copyRandomList(RandomListNode* A) {
    
    if(A == NULL)
        return NULL;
    
    RandomListNode* temp = A;
    RandomListNode* forward;
    
    while(temp != NULL){
        forward = temp->next;
        RandomListNode* t = new RandomListNode(temp->label);
        t->next = forward;
        temp->next = t;
        
        temp = forward;
    }
    
    temp = A;
    
    while(temp){
        
        if(temp->random == NULL){
            temp->next->random = NULL;
        }else{
            temp->next->random = temp->random->next;
        }
        
        temp = temp->next->next;
    }
    
    temp = A;
    RandomListNode* copy = temp->next;
    RandomListNode* temp1 = copy;

    while(temp != NULL && temp1->next != NULL){
        temp->next = temp->next->next;
        temp1->next = temp1->next->next;
        temp = temp->next;
        temp1 = temp1->next;
    }
    
    temp1->next = NULL;
    temp->next = NULL;
    
    return copy;
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

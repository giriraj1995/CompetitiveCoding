//
//  main.cpp
//  Sort Binary LL
//
//  Created by Giriraj Saigal on 10/04/21.
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

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int countZ(ListNode* h) {
    int x = 0;
    while(h) {
        if(h->val == 0)
            x++;
        
        h = h->next;
    }
    return x;
}
ListNode* solve(ListNode* head) {
    if(head == NULL)
        return NULL;
    
    ListNode* tail = head;
    
    while(tail->next != NULL) {
        tail = tail->next;
    }
    
    ListNode* p = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int z = countZ(head);
    
    while(p && z) {
        next = p->next;
        
        if(p->val == 1) {
            if(prev == NULL) {
                tail->next = p;
                tail = p;
                p->next = NULL;
                head = next;
                p = next;
                continue;
            }else{
                prev->next = next;
                tail->next = p;
                tail = p;
                tail->next = NULL;
                p = next;
            }
        }else{
            z--;
            prev = p;
            p = next;
        }
    }
    
    return head;
}

ListNode* create(vector<int> x) {
    ListNode* head = new ListNode(-2);
    ListNode* p = head;
    
    for(int i : x) {
        p->next = new ListNode(i);
        p = p->next;
    }
    
    return head->next;
    
}

int main(int argc, const char * argv[]) {
    solve(create({0,1,1,1,0,0,0,0,1,1}));
    return 0;
}

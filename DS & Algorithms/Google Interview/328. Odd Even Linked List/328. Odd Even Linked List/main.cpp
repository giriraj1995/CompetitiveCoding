//
//  main.cpp
//  328. Odd Even Linked List
//
//  Created by Giriraj Saigal on 04/11/21.
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

/**
 * Definition for singly-linked list. **/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
ListNode* lastEve;
ListNode* findLastOdd(ListNode* p) {
        if(p == NULL)
            return NULL;
        
        if(p->next == NULL || p->next->next == NULL){
            if(p->next != NULL)
                lastEve = p->next;
            return p;
        }
        
        return findLastOdd(p->next->next);
    }
    
    void attachtoEnd(ListNode* till, ListNode* lasttoattach, ListNode* p, bool now) {
        if(p == NULL || p == till)
            return;
        
        if(now) {
            lasttoattach->next = new ListNode(p->val);
            lasttoattach = lasttoattach->next;
        }
        
        attachtoEnd(till, lasttoattach, p->next, !now);
    }
    
    void skipEven(ListNode* p, ListNode* till) {
        if(p == till)
            return;
        
        p->next = p->next->next;
        skipEven(p->next, till);
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        lastEve = NULL;
        ListNode* last = findLastOdd(head);
        
        if(last == head)
            return head;
        
        attachtoEnd(last, last, head, false);
        
        skipEven(head, last);
        
        if(lastEve != NULL){
            
            while(last->next != NULL)
                last = last->next;
            
            last->next = lastEve;
        }
        
        return head;
    }

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
    ListNode* ans = oddEvenList(head);
    return 0;
}

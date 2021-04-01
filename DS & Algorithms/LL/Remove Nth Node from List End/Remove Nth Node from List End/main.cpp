//
//  main.cpp
//  Remove Nth Node from List End
//
//  Created by Giriraj Saigal on 29/03/21.
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
 
 
ListNode* solve(ListNode* p, int x, int &t) {
    if(p == NULL)
        return NULL;
    
    if(p->next == NULL) {
        if(t == x) {
            t++;
            return NULL;
        }else{
            t++;
            return p;
        }
    }
    
    p->next = solve(p->next, x, t);
    
    if(x == t) {
        return p->next;
    }
    
    t++;
    return p;
    
}
ListNode* removeNthFromEnd(ListNode* A, int B) {
    int x = B;
    int t = 1;
    
    ListNode* p = solve(A,x,t);
    
    if(x > t) {
        return p->next;
    }
    
    return p;
}


int main(int argc, const char * argv[]) {
    //1 -> 2 -> 3 -> 4 -> 5
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    
    removeNthFromEnd(h,1);
    return 0;
}

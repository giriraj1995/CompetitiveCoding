//
//  main.cpp
//  Reverse Alternate
//
//  Created by Giriraj Saigal on 12/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


ListNode* solve(ListNode* A) {
    

    stack<int> s;
    queue<int> q;
    
    ListNode* x = A;
    bool turn = true;
    
    while(x) {
        
        if(turn) {
            q.push(x->val);
        }else{
            s.push(x->val);
        }
        
        turn = !turn;
        x = x->next;
    }
    
    ListNode* head = new ListNode(10);
    ListNode* y = head;

    while(q.size() > 0 && s.size() > 0) {
        
        y->next = new ListNode(q.front());
        q.pop();
        
        y = y->next;
        
        y->next = new ListNode(s.top());
        s.pop();
        
        y = y->next;

    }
    
    while(q.size() > 0){
        y->next = new ListNode(q.front());
        q.pop();
    }
    
    while(s.size() > 0) {
        y->next = new ListNode(s.top());
        s.pop();
    }
    
    
    return head->next;
}



int main(int argc, const char * argv[]) {
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    
    A = solve(A);
    return 0;
}

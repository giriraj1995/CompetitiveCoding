//
//  main.cpp
//  Even Reverse
//
//  Created by Giriraj Saigal on 13/04/21.
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

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* solve(ListNode* A) {
    vector<int> odd;
    vector<int> even;

    bool x = true;
    
    while(A) {
        if(x)
            odd.push_back(A->val);
        else
            even.push_back(A->val);
        
        x = !x;
        A = A->next;
    }
    
    ListNode* head = new ListNode(-1);
    ListNode* p = head;

    int i = 0;
    int j = even.size()-1;
    bool o = true;
    
    while(1) {
        
        if(o) {
            if(i >= odd.size()) {
                break;
            }
            p->next = new ListNode(odd[i++]);
        } else {
            if(j < 0) {
                break;
            }
            p->next = new ListNode(even[j--]);
        }
        
        o = !o;
        p = p->next;
    }
    
    return head->next;
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
    ListNode* x = create({1,2,3,4});
    solve(x);
    return 0;
}

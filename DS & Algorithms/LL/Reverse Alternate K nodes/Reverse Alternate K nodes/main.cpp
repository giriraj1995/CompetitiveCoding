//
//  main.cpp
//  Reverse Alternate K nodes
//
//  Created by Giriraj Saigal on 09/04/21.
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

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* revAl(ListNode* A, int B, bool now) {
    if(!A) {
        return A;
    }
    ListNode* head = A;
    
    if(!now) {
        int x = B;
        while(A && --x) {
            A = A->next;
        }
        if(A == NULL || A->next == NULL) {
            return head;
        }else{
            A->next = revAl(A->next, B, !now);
            return head;
        }
    }else{
        ListNode* curr = A;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        int x = B;
        
        while(x-- && curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        
        head->next = revAl(nex, B, !now);
        return prev;
    }
    
}
ListNode* solve(ListNode* A, int B) {
    bool now = true;
    return revAl(A,B,now);
}

ListNode* create(vector<int> x) {
    ListNode* head = new ListNode(-1);
    ListNode* p = head;

    for(int i : x) {
        p->next = new ListNode(i);
        p = p->next;
    }
    
    return head->next;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1,2,3,4,5,6,7,8,9};
    revAl(create(x), 3, true);
    return 0;
}

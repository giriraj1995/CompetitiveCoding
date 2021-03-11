//
//  main.cpp
//  19. Remove Nth Node From End of List
//
//  Created by Giriraj Saigal on 11/03/21.
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
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* count(ListNode* p, int &c, int n) {
    if(p == NULL) {
        c = c+1;
        return p;
    }
    
    p->next = count(p->next, c, n);
    
    if(c == n) {
        c = c + 1;
        return p->next;
    }
    
    c = c+1;
    
    return p;
    
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int c = 0;
    return count(head, c, n);
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    head = removeNthFromEnd(head, 2);
    return 0;
}

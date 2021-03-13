//
//  main.cpp
//  23. Merge k Sorted Lists
//
//  Created by Giriraj Saigal on 13/03/21.
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

int count(ListNode* x, int c) {
    if(x == NULL)
        return c;
    else
        return count(x->next, c+1);
}

ListNode* merge(ListNode* x, ListNode* y) {
    ListNode* head = new ListNode(-1);
    ListNode* temp = head;
    
    while(x != NULL && y != NULL) {
        if(x->val < y->val) {
            temp->next = new ListNode(x->val);
            x = x->next;
        }else{
            temp->next = new ListNode(y->val);
            y = y->next;
        }
        
        temp = temp->next;
    }
    
    while(x != NULL) {
        temp->next = new ListNode(x->val);
        x = x->next;
        temp = temp->next;
    }
    
    while(y != NULL) {
        temp->next = new ListNode(y->val);
        y = y->next;
        temp = temp->next;
    }
    
    return head->next;
}

ListNode* mergeKLists(vector<ListNode*> lists) {
    int n = (int)lists.size();
    
    if(n == 0) {
        return NULL;
    }
    
    if(n == 1) {
        return lists[0];
    }
    
    vector<pair<int,ListNode*>> si;
    
    for(int i = 0; i < n; i++)
        si.push_back({count(lists[i], 0), lists[i]});
    
    sort(si.begin(), si.end());
    
    ListNode* prev = si[0].second;
    
    for(int i = 1; i < n; i++) {
        prev = merge(prev, si[i].second);
    }
    
    return prev;
}

int main(int argc, const char * argv[]) {
    ListNode* fir = new ListNode(1);
    fir->next = new ListNode(4);
    fir->next->next = new ListNode(5);
    
    ListNode* sec = new ListNode(1);
    sec->next = new ListNode(3);
    sec->next->next = new ListNode(4);
    
    ListNode* thi = new ListNode(2);
    thi->next = new ListNode(6);

    mergeKLists({fir, sec, thi});
    return 0;
}

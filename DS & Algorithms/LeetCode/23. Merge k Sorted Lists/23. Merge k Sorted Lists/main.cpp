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
        temp->next = x;
        break;
    }

    while(y != NULL) {
        temp->next = y;
        break;
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

    priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>,                        greater<pair<int,ListNode*>>> si;

    for(int i = 0; i < n; i++)
        si.push({count(lists[i], 0), lists[i]});

    int i = 0;
    ListNode* head = NULL;
    
    while(si.size() > 0) {
        if(i == 0) {
            pair<int,ListNode*> x = si.top();
            si.pop();
            pair<int,ListNode*> y = si.top();
            si.pop();
            head = merge(x.second,y.second);
            i++;
        }else{
            pair<int,ListNode*> x = si.top();
            si.pop();
            head = merge(head, x.second);
        }
    }

    return head;
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

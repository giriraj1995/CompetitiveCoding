//
//  main.cpp
//  25. Reverse Nodes in k-Group
//
//  Created by Giriraj Saigal on 22/03/21.
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


class Solution {
public:
    ListNode* reverse(ListNode* p, int k) {
        if(p == NULL)
            return NULL;
        
        int i = 0;
        ListNode* temp = p;
        for(; i < k; i++)
        {
            if(temp == NULL) {
                break;
            }
            
            temp = temp->next;
        }
        
        ListNode* prev = NULL;
        
        if(i == k) {
            prev = reverse(temp, k);
        }else{
            prev = NULL;
        }
        
        int t = k;
        ListNode* curr = p;
        ListNode* next = NULL;
        
        while(t-- && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* createList(vector<int> x) {
        ListNode* head = new ListNode(x[0]);
        ListNode* temp = head;
        for(int i = 1; i < x.size(); i++){
            temp->next = new ListNode(x[i]);
            temp = temp->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k);
    }
};

int main(int argc, const char * argv[]) {
    Solution* s = new Solution();
    ListNode* x = s->createList({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    x =s->reverseKGroup(x,7);
    return 0;
}

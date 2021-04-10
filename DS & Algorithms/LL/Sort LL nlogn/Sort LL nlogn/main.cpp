//
//  main.cpp
//  Sort LL nlogn
//
//  Created by Giriraj Saigal on 08/04/21.
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

ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* ans1 = new ListNode(-1);
    ListNode* ans = ans1;

    while(left && right) {
        if(left->val < right->val) {
            ans->next = new ListNode(left->val);
            left = left->next;
        }else{
            ans->next = new ListNode(right->val);
            right = right->next;
        }
        
        ans = ans->next;
    }
        
    if(left) {
        ans->next = left;
    }
    
    if(right) {
        ans->next = right;
    }
    
    return ans1->next;
}

ListNode* sort(ListNode* A) {
    
    if(A == NULL || A->next == NULL) {
        return A;
    }
    
    ListNode* slow = A;
    ListNode* fast = A->next;
    ListNode* prev = NULL;
    
    while(fast) {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
        
        if(fast) {
            fast = fast->next;
        }
    }
    
    prev->next = NULL;
    ListNode* left = sort(A);
    ListNode* right = sort(slow);
    
    return merge(left, right);
}

ListNode* sortList(ListNode* A) {
    return sort(A);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

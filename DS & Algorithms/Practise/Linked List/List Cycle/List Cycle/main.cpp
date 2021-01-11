//
//  main.cpp
//  List Cycle
//
//  Created by Giriraj Saigal on 10/01/21.
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
 
ListNode* detectCycle(ListNode* A) {
    if(A == NULL)
        return NULL;
        
    ListNode* slow = A;
    ListNode* fast = A->next;

    while(fast != slow && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        
        if(fast != NULL) {
            fast = fast->next;
        }else{
            return NULL;
        }
    }

    slow = A;
    
    while(slow->next) {
        fast = slow->next;
        slow->next = NULL;
        slow = fast;
    }
    
    return slow;

}


int main(int argc, const char * argv[]) {
    map<char, int> mp;
    return 0;
}

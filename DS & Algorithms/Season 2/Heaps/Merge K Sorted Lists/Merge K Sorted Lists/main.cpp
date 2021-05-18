//
//  main.cpp
//  Merge K Sorted Lists
//
//  Created by Giriraj Saigal on 18/05/21.
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
 
ListNode* mergeKLists(vector<ListNode*> &A) {
    map<int,int> mp;
    
    for(int k = 0; k < A.size(); k++) {
        while(A[k] != NULL) {
            mp[A[k]->val]++;
            A[k] = A[k]->next;
        }
    }
    
    ListNode *head = new ListNode(-1);
    ListNode *temp = head;
    
    for(auto i : mp) {
        int t = 0;
        while(t < i.second) {
            temp->next = new ListNode(i.first);
            t++;
        }
    }
    
    return head->next;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

//
//  main.cpp
//  Merge K Sorted List
//
//  Created by Giriraj Saigal on 22/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* mergeKLists(vector<ListNode*> &A) {
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(ListNode *x : A){
        
        while(x != NULL){
            minHeap.push(x->val);
            x = x->next;
        }
        
    }
    
    if(minHeap.size() == 0)
        return NULL;
        
    ListNode* temp = new ListNode(-1);
    ListNode* t = temp;
    while(minHeap.size() > 0){
        
        t->next = new ListNode(minHeap.top());
        minHeap.pop();
        t = t->next;
        
    }
    
    return temp->next;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

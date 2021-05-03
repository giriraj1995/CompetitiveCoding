//
//  main.cpp
//  Copy List
//
//  Created by Giriraj Saigal on 03/05/21.
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
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A;
    RandomListNode* next = NULL;
    
    while(curr) {
        RandomListNode* temp = new RandomListNode(curr->label);
        next = curr->next;
        curr->next = temp;
        temp->next = next;
        curr = next;
    }
    
    curr = A;
    
    while(curr) {
        if(curr->random)
            curr->next->random = curr->random->next;
        
        curr = curr->next->next;
    }
    
    curr = A;
    RandomListNode* head = new RandomListNode(-1);
    RandomListNode* temp = head;
    while(curr) {
        temp->next = curr->next;
        
        curr = curr->next->next;
        temp = temp->next;
    }
    
    return head->next;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

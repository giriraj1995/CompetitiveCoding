//
//  main.cpp
//  Rotate LL
//
//  Created by Giriraj Saigal on 31/03/21.
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
int count(ListNode* A) {
    int c = 0;
    while(A) {
        A = A->next;
        c++;
    }
    return c;
}

ListNode* rotateRight(ListNode* A, int B) {
    int c = count(A);
    int n = c - B;
    
    ListNode* head = A;
    ListNode* prev = NULL;
    while(n--) {
        prev = A;
        A = A->next;
    }
    
    prev->next = NULL;
    ListNode* head1 = A;
    while(A->next != NULL) {
        A = A->next;
    }
    
    A->next = head;
    
    return head1;
}


int main(int argc, const char * argv[]) {
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    rotateRight(h,2);
    return 0;
}

//
//  main.cpp
//  Palindrome List
//
//  Created by Giriraj Saigal on 16/03/21.
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
 
 
ListNode* find(ListNode* A, ListNode** start, ListNode** end, int &ans) {
    
    if(A->next == NULL) {
        end = &A;
        return A;
    }
    
    (*end) = find(A->next, start, end, ans);
    
    if(ans == 1) {
        return A;
    }else if(ans == 0) {
        return A;
    }else if(*start == *end){
        ans = 1;
        return A;
    }else if((int)(*end)->val != (int)(*start)->val) {
        ans = 0;
        return A;
    }else{
        (*start) = (*start)->next;
    }
    
    return A;
    
}
int lPalin(ListNode* A) {
    
    if(A == NULL) {
        return 1;
    }
    
    ListNode* start = A;
    ListNode* end = NULL;
    int ans = -1;
    find(A, &start, &end, ans);
    return ans == -1 ? 1 : ans;
}


int main(int argc, const char * argv[]) {
    ListNode* x = new ListNode(3);
    x->next =new ListNode(3);
    
    lPalin(x);
    return 0;
}

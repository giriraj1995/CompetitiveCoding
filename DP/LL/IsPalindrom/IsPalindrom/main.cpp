//
//  main.cpp
//  IsPalindrom
//
//  Created by Giriraj Saigal on 03/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 
void traverse(ListNode* A, vector<int> &x){
    if(A == NULL)
        return;
        
    x.push_back(A->val);
    traverse(A->next, x);
    
}

int isPalindrom(vector<int> x){
    
    int i = 0;
    int j = x.size()-1;
    while(i < j){
        
        if(x[i] != x[j])
            return 0;
            
        i++;
        j--;
    }
    
    return 1;
}
 
int lPalin(ListNode* A) {
    
    vector<int> x;
    
    traverse(A, x);
    
    return isPalindrom(x);
}


int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    lPalin(a);
    
    
    return 0;
}

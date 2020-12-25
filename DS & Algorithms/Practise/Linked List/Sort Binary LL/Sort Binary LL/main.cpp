//
//  main.cpp
//  Sort Binary LL
//
//  Created by Giriraj Saigal on 25/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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
 
 
void count(ListNode* A, int &z, int &o) {
    
    if(A == NULL)
        return;
    
    if(A->val == 1){
        o++;
    }else{
        z++;
    }
    
    count(A->next, z, o);
}

void fix(ListNode* A, int &z, int &o) {
    if(A == NULL)
        return;
        
    if(z != 0) {
        A->val = 0;
        z--;
    }else{
        A->val = 1;
        o--;
    }
    fix(A->next, z, o);
}

ListNode* solve(ListNode* A) {
    int z = 0;
    int o = 0;
    
    count(A, z, o);
    fix(A, z, o);
    
    return A;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

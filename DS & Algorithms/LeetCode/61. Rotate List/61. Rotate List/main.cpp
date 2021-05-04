//
//  main.cpp
//  61. Rotate List
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


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
ListNode* create(vector<int> a) {
    ListNode* x = new ListNode(-1);
    ListNode* temp = x;
    for(int i : a){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return x->next;
}

    int count(ListNode* h) {
        int x = 0;
        while(h){
            x++;
            h = h->next;
        }
        return x;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;
        
        if(k == 0)
            return head;
        
        int c = count(head);
        k = k % c;
        
        if(k == 0)
            return head;
        
        int br = c - k;
        ListNode* curr = head;
        
        while(curr && --br)
        {
            curr = curr->next;
        }
        
        ListNode* ans = curr->next;
        ListNode* curr2 = curr->next;
        curr->next = NULL;
        
        while(curr2->next != NULL)
            curr2 = curr2->next;
        
        curr2->next = head;
        
        return ans;
    }
int main(int argc, const char * argv[]) {
    rotateRight(create({}),0);
    return 0;
}

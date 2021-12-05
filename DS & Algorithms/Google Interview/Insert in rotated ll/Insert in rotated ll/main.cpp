//
//  main.cpp
//  Insert in rotated ll
//
//  Created by Giriraj Saigal on 06/12/21.
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

/*
// Definition for a Node.
 */
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        Node* temp = new Node(insertVal);
        
        if(head == NULL){
            temp->next = temp;
            return temp;
        }
        
        Node* curr = head;
        bool crossedOne = false;
        bool crossedTwice = false;
        
        while(curr->val <= curr->next->val) {
            curr = curr->next;
            if(curr->next == head && crossedOne == false) {
                crossedOne = true;
            }else if(curr->next == head && crossedOne == true && crossedTwice == false){
                crossedTwice = true;
            }else if(curr->next == head && crossedOne == true && crossedTwice == true){
                temp->next = curr->next;
                curr->next = temp;
                return head;
            }
        }
        
        Node* low = curr->next;
        Node* high = curr;
        
        high->next = NULL;
        
        if(insertVal < low->val) {
            temp->next = low;
            high->next = temp;
            return head;
        }
        
        Node* x = low;
        while(x->next != NULL && insertVal > x->next->val) {
            x = x->next;
        }
        
        if(x->next == NULL) {
            x->next = temp;
            temp->next = low;
            return head;
        }
        
        temp->next = x->next;
        x->next = temp;
        high->next = low;
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

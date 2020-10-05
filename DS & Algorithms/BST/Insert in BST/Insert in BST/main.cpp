//
//  main.cpp
//  Insert in BST
//
//  Created by Giriraj Saigal on 04/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
    Node(int data){
        left = NULL;
        this->data = data;
        right = NULL;
    }
}*root;

Node* insert(Node*p ,int val){
    
    if(p == NULL){
        p = new Node(val);
        return p;
    }
    
    if(val < p->data){
        p->left = insert(p->left, val);
    }else{
        p->right = insert(p->right, val);
    }
    
    return p;
}

int main(int argc, const char * argv[]) {
    
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 25);
    insert(root, 23);
    insert(root, 5);
    insert(root, 7);
    insert(root, 1);


    return 0;
}

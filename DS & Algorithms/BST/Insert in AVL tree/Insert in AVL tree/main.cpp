//
//  main.cpp
//  Insert in AVL tree
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
    int height;
    Node* right;
    Node(int data){
        left = NULL;
        this->data = data;
        height = 1;
        right = NULL;
    }
}*root;

int NodeHeight(Node* p){
    
    if(p == NULL)
        return 0;
    
    int hl = 0,hr = 0;
    
    if(p->left){
        hl = p->left->height;
    }
    
    if(p->right){
        hr = p->right->height;
    }
    
    return hl > hr ? hl+1 : hr+1;
    
}

int BalanceFactor(Node* p){
    
    int hl = 0,hr = 0;
    
    if(p->left){
        hl = p->left->height;
    }
    
    if(p->right){
        hr = p->right->height;
    }
    
    return abs(hl-hr);
}

Node* LLRotation(Node* p){
    
    Node* pl = p->left;
    Node* pll = pl->left;
    
    p->left = pl->right;
    pl->right = p;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    pll->height = NodeHeight(pll);
    
    if(p == root)
        root = pl;
    
    return pl;
    
}

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
    
    p->height = NodeHeight(p);
    
    if(BalanceFactor(p) == 2){
        return LLRotation(p);
    }
    
    return p;
}

int main(int argc, const char * argv[]) {
    
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 1);


    return 0;
}


//
//  main.cpp
//  Max sum of path
//
//  Created by Giriraj Saigal on 10/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    }*root;

int max(int i, int j){return i>j?i:j;}

Node* insert_BST(int x, Node* p)
{
    if(p == NULL){
        p = new Node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    
    if(x < p->data) {
        p->left = insert_BST(x, p->left);
    } else if(x > p->data) {
        p->right = insert_BST(x, p->right);
    }
    
    return p;
}

void print_inorder(Node* p){
    if(p == NULL){
        return;
    } else {
        print_inorder(p->left);
        cout<<p->data<<"\t";
        print_inorder(p->right);
    }
}

int max_sum_leaf(Node *p, int &res){
    
    int temp;
    
    if(p == NULL)
        return 0;
    

    
    int l = max_sum_leaf(p->left, res);
    int r = max_sum_leaf(p->right, res);
    
    
    if(p->left && p->right){
        res = max(res,l+r+p->data);
        temp = max(l,r) + p->data;
        return temp;
    }
    
    if(!p->left && !p->right)
        return p->data;
    
    return !p->left ? r+p->data : l+p->data;
}

int main(int argc, const char * argv[]) {
    
    int res = INT_MIN;
    
    root = new Node;
    root->data = 10;
    root->left = NULL;
    root->right = NULL;
    
    insert_BST(-5, root);
    insert_BST(20, root);
    insert_BST(-4, root);
    insert_BST(-10, root->right);
    insert_BST(40, root);
    insert_BST(2, root);
    insert_BST(-40, root);
    insert_BST(9, root);
    insert_BST(1, root);
    insert_BST(9, root);
    insert_BST(50, root);
    insert_BST(31, root);
    
    max_sum_leaf(root, res);
    cout<<"Max Sum: "<<res<<endl;
    return 0;
}


//
//  main.cpp
//  Height of BinaryTree
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    Node* node;
    Queue* next;
}*first;

void enqueue(Node *p){
    
    Queue *x = new Queue;
    x->node = p;
    x->next = first;
    
    first = x;
    
}

Node* dequeue(){
    Node* x = NULL;
    
    if(first == NULL)
        return NULL;
    
    Queue* temp = first;
    Queue* prev = temp;
    
    while(temp->next){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == prev){
        x = first->node;
        first = NULL;
        return x;
    }
    
    prev->next = NULL;
    x = temp->node;
    delete temp;
    
    return x;
}

int isEmpty(){
    if(first == NULL)
        return 1;
    return 0;
}

Node* createBinaryTree(Node * p){
    
    first = NULL;
    enqueue(p);
    
    while(!isEmpty()){
        Node *x = dequeue();
        int d;
        
        cout<<"Enter left child of "<<x->data<<":";
        cin>>d;
        
        if(d != -1){
            Node* n = new Node;
            n->data = d;
            n->left = n->right = NULL;
            x->left = n;
            enqueue(n);
        }
        
        cout<<"Enter right child of "<<x->data<<":";
        cin>>d;
        
        if(d != -1){
            Node* n = new Node;
            n->data = d;
            n->left = n->right = NULL;
            x->right = n;
            enqueue(n);
        }
    }
    
    return p;
}

int heightofTree(Node *p){
    if(p == NULL)
        return 0;
    int l = heightofTree(p->left);
    int h = heightofTree(p->right);
    
    return l>h?l+1:h+1;
}

int main(int argc, const char * argv[]) {
    
    Node* root = new Node;
    int x;
    cout<<"Enter root Element :";
    cin>>x;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    root = createBinaryTree(root);
    
    cout<<heightofTree(root)<<endl;
    
    return 0;
}


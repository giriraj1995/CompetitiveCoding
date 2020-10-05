//
//  main.cpp
//  Balanced AVL tree
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

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

int NodeHeight(node* p){
    
    
    int hl = -1;
    int hr = -1;
    
    if(p->left)
        hl = p->left->ht;
    
    if(p->right)
        hr = p->right->ht;
    
    return hl > hr ? hl + 1 : hr + 1;
    
}

int BalanceFactor(node * p){
    
    int hl = -1;
    int hr = -1;
    
    if(p->left)
        hl = p->left->ht;
    
    if(p->right)
        hr = p->right->ht;
    
    return hl - hr;
}

node * LLRotation(node * p){
    
    node* pl = p->left;
    node* pll = pl->left;
    
    p->left = pl->right;
    pl->right = p;
    
    p->ht = NodeHeight(p);
    pl->ht = NodeHeight(pl);
    pll->ht = NodeHeight(pll);
        
    return pl;
    
}

node * LRRotation(node * p){
    
    node* pl = p->left;
    node* plr = pl->right;
    
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    
    p->ht = NodeHeight(p);
    pl->ht = NodeHeight(pl);
    plr->ht = NodeHeight(plr);
        
    return plr;
    
}

node * RRRotation(node * p){
    
    node* pr = p->right;
    node* prr = pr->right;
    
    p->right = pr->left;
    pr->left = p;
    
    p->ht = NodeHeight(p);
    pr->ht = NodeHeight(pr);
    prr->ht = NodeHeight(prr);
    
    return pr;
    
}

node * RLRotation(node * p){
    
    node* pr = p->right;
    node* prl = pr->right;
    
    pr->left = prl->right;
    p->right = prl->left;
    
    prl->left = p;
    prl->right = pr;
    
    p->ht = NodeHeight(p);
    pr->ht = NodeHeight(pr);
    prl->ht = NodeHeight(prl);
    
    return prl;
    
}



node * insert(node * root,int val)
{
    if(root == NULL){
        root = new node();
        root->val = val;
        root->ht = 0;
        root->left = root->right = NULL;
        return root;
    }
    
   if(val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    
    root->ht = NodeHeight(root);
    
    if(BalanceFactor(root) == 2 || BalanceFactor(root) == -2){
        if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1){
            return LLRotation(root);
        }else if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1){
            return LRRotation(root);
        }else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1){
            return RRRotation(root);
        }else
            return RLRotation(root);
    }
    return root;
}

int main(int argc, const char * argv[]) {
    node* root;
    
    root = insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);

    
    return 0;
}

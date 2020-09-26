//
//  main.cpp
//  IsBalancedTree
//
//  Created by Giriraj Saigal on 26/09/20.
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
    int val;
    Node* left;
    Node* right;
};

int height(Node* p){
    if(p == NULL){
        return 0;
    }
    int l,r;
    return (l = height(p->left)) >  (r = height(p->right)) ? l+1 : r+1;
}

int isBalanced(Node* p){
    
    if(p == NULL)
        return 1;
    
    int l =height(p->left);
    int r =height(p->right);
    
    if(abs(l-r) > 1){
        return 0;
    }else{
        return isBalanced(p->left) * isBalanced(p->right);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

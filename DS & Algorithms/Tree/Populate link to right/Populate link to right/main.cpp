//
//  main.cpp
//  Populate link to right
//
//  Created by Giriraj Saigal on 29/09/20.
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

//  Definition for binary tree with next pointer.
struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
void connect(TreeLinkNode* A) {
    
    map<TreeLinkNode*, int> mp;
    map<int, vector<TreeLinkNode*>> u;
    mp[A] = 0;
    queue<TreeLinkNode*> q;
    q.push(A);
    
    while(q.size() > 0){
        TreeLinkNode* temp = q.front();
        q.pop();
        int k = mp[temp];
        
        u[k].push_back(temp);
        
        if(temp->left){
            q.push(temp->left);
            mp[temp->left] = k+1;
        }
        
        if(temp->right){
            q.push(temp->right);
            mp[temp->right] = k+1;
        }
    }
    
    for(auto i : u){
        vector<TreeLinkNode*> h = i.second;
        for(int y = 0; y < h.size()-1; y++){
            h[y]->next = h[y+1];
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

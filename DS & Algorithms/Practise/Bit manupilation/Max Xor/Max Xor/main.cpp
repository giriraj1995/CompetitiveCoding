//
//  main.cpp
//  Max Xor
//
//  Created by Giriraj Saigal on 26/12/20.
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

struct TrieNode {
    struct TrieNode* left, *right;
};

void insert(int n, TrieNode *node) {
    for(int i = 31; i >= 0; i--) {
        int k = (n>>i)&1;
        if(k == 0) {
            if(node->left == NULL)
            {
                node->left = new TrieNode();
                node = node->left;
            }
            else
            {
                node = node->left;
            }
        }else{
            if(node->right == NULL)
            {
                node->right = new TrieNode();
                node = node->right;
            }
            else
            {
                node = node->right;
            }
        }
    }
}

int solve(int n, TrieNode* node) {
    int cur_xor = 0;
    for(int i = 31; i >=0; i--) {
        int k = (n>>i)&1;
        if(k == 0) {
            if(node->right != NULL) {
                cur_xor += pow(2, i);
                node = node->right;
            }else{
                node = node->left;
            }
        }else{
            if(node->left != NULL) {
                cur_xor += pow(2, i);
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
    return cur_xor;
}
// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> q) {
    
    TrieNode* node = new TrieNode();
    vector<int> ans;
    
    for(int i : arr) {
        insert(i,node);
    }
    
    for(int i : q) {
        ans.push_back(solve(i, node));
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    maxXor({5,1,7,4,3}, {2,0});
    return 0;
}

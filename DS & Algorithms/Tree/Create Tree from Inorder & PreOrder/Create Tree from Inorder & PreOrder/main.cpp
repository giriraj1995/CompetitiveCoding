//
//  main.cpp
//  Create Tree from Inorder & PreOrder
//
//  Created by Giriraj Saigal on 06/10/20.
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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> A, vector<int> B) {
    
    if(A.size() == 0 || B.size() == 0)
        return NULL;
        
    int x = B[0];
    
    int index = -1;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == x){
            
            index = i;
            break;
            
        }
        
    }
    
    if(index == -1)
        return NULL;
        
    TreeNode* temp = new TreeNode(x);
    
    vector<int> left(A.begin(), A.begin() + index);
    vector<int> right(A.begin() + index + 1, A.end());
    
    vector<int> left1(B.begin() + 1, B.begin() + index + 1);
    vector<int> right1(B.begin() + index +1, B.end());
    
    temp->right = buildTree(right, right1);
    temp->left = buildTree(left, left1);
    
    return temp;
}

int main(int argc, const char * argv[]) {
    TreeNode* node = buildTree({1, 2, 3 },{2, 1, 3 });
    return 0;
}

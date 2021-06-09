//
//  main.cpp
//  Min Depth of Binary Tree
//
//  Created by Giriraj Saigal on 09/06/21.
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


 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int solve(TreeNode* A) {
    if(A == NULL)
        return -1;
    
    if(A->left == NULL && A->right == NULL) {
        return 1;
    }
    
    int lef = solve(A->left);
    int rig = solve(A->right);
    
    if(lef == -1 && rig == -1)
        return -1;
    
    if(lef != -1 && rig != -1)
        return 1+min(lef,rig);
    
    if(rig != -1)
        return rig+1;
        
    if(lef != -1)
        return lef+1;
    
    return -1;
}
int minDepth(TreeNode* A) {
    return solve(A);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

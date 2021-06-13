//
//  main.cpp
//  Least Common Ancestor
//
//  Created by Giriraj Saigal on 12/06/21.
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
//Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
bool find(TreeNode* A, int B, vector<int> &ans) {
    if(A == NULL)
        return false;
    
    ans.push_back(A->val);
    
    if(A->val == B)
        return true;
    else if(find(A->left, B, ans) || find(A->right, B, ans)) {
        return true;
    }
    
    ans.pop_back();
    return false;
}

int lca(TreeNode* A, int B, int C) {
    vector<int> v1;
    vector<int> v2;
    
    if(!find(A,B,v1) || !find(A,C,v2)) {
        return -1;
    }
    
    int i = 0;
    int j = 0;
    
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] != v2[j])
            break;
        
        i++;
        j++;
    }
    
    return v1[i-1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  Create Tree from pre and inorder
//
//  Created by Giriraj Saigal on 06/06/21.
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
 
TreeNode* create(vector<int> &A, vector<int> &B, int i, int j) {
    if(A.size() == 0)
        return NULL;
    
    if(i > j)
        return NULL;
    
    int p = -1;
    int q = -1;
    bool br = false;
    for(p = 0; p < A.size(); p++) {
        int x = A[p];
        br = false;
        for(q = i; q <= j; q++) {
            if(B[q] == x){
                br = true;
                break;
            }
        }
        if(br)
            break;
    }
    
    if(!br)
        return NULL;
    
    TreeNode* f = new TreeNode(A[p]);
    A.erase(A.begin());
    f->left = create(A,B,0,q-1);
    f->right = create(A,B,q+1,j);
    
    return f;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    return create(A,B,0,B.size()-1);
}


int main(int argc, const char * argv[]) {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 2, 4, 1, 5};
    buildTree(a,b);
    return 0;
}

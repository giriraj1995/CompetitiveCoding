//
//  main.cpp
//  Kth Smallest Element In Tree
//
//  Created by Giriraj Saigal on 13/05/21.
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

//  Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int kthsmallest(TreeNode* A, int B) {
    stack<TreeNode*> s;
    TreeNode* temp = A;
    int t = B;
    
    while(s.size() > 0 || temp != NULL) {
        if(temp) {
            s.push(temp);
            temp = temp->left;
        }else{
            temp = s.top();
            s.pop();
            t--;
            if(t == 0)
                return temp->val;
            temp = temp->right;
        }
    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

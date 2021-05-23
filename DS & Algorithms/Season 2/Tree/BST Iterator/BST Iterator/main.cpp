//
//  main.cpp
//  BST Iterator
//
//  Created by Giriraj Saigal on 22/05/21.
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
 

vector<int> vec;
int x = 0;
class BSTIterator{
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* temp = root;
        
        while(s.size() > 0 || temp != NULL) {
            if(temp != NULL) {
                vec.push_back(temp->val);
                s.push(temp);
                temp = temp->left;
            }else{
                temp = s.top();
                s.pop();
                temp = temp->right;
            }
        }
        
        sort(vec.begin(), vec.end());
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(x >= (int)vec.size())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        int t = vec[x];
        x++;
        return t;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
TreeNode* create(vector<int> x, TreeNode* p, int ind) {
    if(ind >= x.size() || x[ind] == -1)
        return NULL;
    
    if(p == NULL) {
        p = new TreeNode(x[ind]);
    }
    
    p->left = create(x, p->left, ind*2);
    p->right = create(x, p->right, ind*2+1);
    
    return p;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = NULL;
    root = create({0, 4,2,9,1,3,8,11,-1,-1,-1,-1,7,-1,10,12,5,-1,-1,-1,-1,13,-1,6,-1,-1,-1,-1}, root, 1);
    BSTIterator *i = new BSTIterator(root);
    while (i->hasNext()) cout << i->next()<<endl;
    return 0;
}

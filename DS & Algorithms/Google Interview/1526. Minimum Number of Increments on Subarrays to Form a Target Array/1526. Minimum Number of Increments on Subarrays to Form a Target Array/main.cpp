//
//  main.cpp
//  1526. Minimum Number of Increments on Subarrays to Form a Target Array
//
//  Created by Giriraj Saigal on 19/10/21.
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

struct TreeNode{
        int no;
        int l,r;
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    
TreeNode* createTree(int n, int left, int right, vector<int> target) {
        
        TreeNode* root = new TreeNode();
        root->no = n;
        root->l = left;
        root->r = right;
        
        if(left == right){
            root->value = left;
            return root;
        }
        
        int m = left + (right-left)/2;
        TreeNode* x = createTree(n*2+1, left, m, target);
        TreeNode* y = createTree(n*2+2, m+1, right, target);
        
        if(target[x->value] < target[y->value]) {
            root->value = x->value;
        }else{
            root->value = y->value;
        }
        
        root->left = x;
        root->right = y;
        
        return root;
    }
    
int findIdx(TreeNode* root, int left, int right, vector<int>& target) {
    if(left <= root->l && root->r <= right) {
        return root->value;
    }else if(root->r < left || right < root->l){
        return -1;
    }
    
    int x = findIdx(root->left, left, right, target);
    int y = findIdx(root->right, left, right, target);
        
    if(x == -1 && y == -1)
        return -1;
    else if(x == -1)
        return y;
    else if(y == -1)
        return x;
    
    return target[x] < target[y] ? x : y;
}

int ans;
    void solve(int l, int r, int add, TreeNode* root, vector<int>& target) {
        if(l > r)
            return;
        
        int minInd = findIdx(root, l, r, target);
        ans += target[minInd] - add;
        add += target[minInd] - add;
        
        solve(l, minInd-1, add, root, target);
        solve(minInd+1, r, add, root, target);
    }

int minNumberOperations(vector<int>& target) {
    ans = 0;
    TreeNode* root = createTree(0,0,target.size()-1,target);
    solve(0,target.size()-1,0,root,target);
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> t = {3,1,5,4,2};
    vector<int> k = {0,1};
    
    cout << minNumberOperations(t);
    return 0;
}

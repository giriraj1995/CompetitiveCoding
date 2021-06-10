#include<iostream>
using namespace std;

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
void solve(TreeNode* A, int B,long long sum,vector<vector<int>> &ans,vector<int> inp) {
    if(A == NULL)
        return;
        
    inp.push_back(A->val);
    
    if(A->left == NULL && A->right == NULL) {
        if(sum + A->val == B) {
            ans.push_back(inp);
        }
        
        return;
    }
    
    solve(A->left,B,sum+A->val,ans,inp);
    solve(A->right,B,sum+A->val,ans,inp);
}

vector<vector<int> > pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    solve(A,B,0,ans,{});
    return ans;
}

int main() {
	return 0;
}


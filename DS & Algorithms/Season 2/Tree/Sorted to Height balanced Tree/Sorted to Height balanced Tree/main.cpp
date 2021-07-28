//
//  main.cpp
//  Sorted to Height balanced Tree
//
//  Created by Giriraj Saigal on 26/07/21.
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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

TreeNode* solve(vector<int> &nums, int i, int j) {
    if(i == j)
        return new TreeNode(nums[i], NULL, NULL);
    
    if(i > j)
        return NULL;
    
    int m = i+(j-i)/2;
    
    TreeNode* p = new TreeNode(nums[m]);
    p->left = solve(nums, i, m-1);
    p->right = solve(nums, m+1, j);
    
    return p;
}

TreeNode* sortedArrayToBST(vector<int> nums) {
    return solve(nums, 0, (int)nums.size()-1);
}

int main(int argc, const char * argv[]) {
    sortedArrayToBST({-10,-3,0,5,9});
    return 0;
}

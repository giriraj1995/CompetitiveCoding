/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(vector<int> &vec, TreeNode* p) {
        if(p == NULL)
            return;
        
        stack<TreeNode*> s;
        TreeNode* tmp = p;
        
        while(s.size() > 0 || tmp != NULL) {
            if(tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            }else{
                tmp = s.top();
                s.pop();
                vec.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        
    }
    
    
    vector<int> merge(vector<int> v1, vector<int> v2) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] < v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }else{
                ans.push_back(v2[j]);
                j++;
            }    
        }
        
        while(i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }
        
         while(j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }
        
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> x1;
        vector<int> x2;
        inorder(x1, root1);
        inorder(x2, root2);
        
        return merge(x1, x2);
    }
};
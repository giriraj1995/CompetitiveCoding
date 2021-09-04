    vector<TreeNode*> solve(int p, int q) {
        if(p > q)
            return {};
        
        if(p == q){
            return {new TreeNode(p)};
        }
        
        vector<TreeNode*> ans;
        for(int k = p; k <= q; k++) {
            TreeNode* root = new TreeNode(k);
            vector<TreeNode*> left = solve(p,k-1);
            vector<TreeNode*> right = solve(k+1,q);
                        
            if(left.size() == 0) {
                for(int i = 0; i < right.size(); i++){
                    root->right = right[i];
                    ans.push_back(root);
                }
            }else if(right.size() == 0){
                for(int i = 0; i < left.size(); i++){
                    root->left = left[i];
                    ans.push_back(root);
                }
            }else{
                for(int i = 0; i < left.size(); i++) {
                    for(int j = 0; j < right.size(); j++) {
                        root->left = left[i];
                        root->right = right[j];
                        ans.push_back(root);
                    }
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }

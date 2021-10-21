struct TreeNode{
        int no;
        int l,r;
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    
    TreeNode* createTree(int n, int left, int right, vector<int>& target) {
        
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
        if(left >= root->l && root->r <= right) {
            return root->value;
        }
        
        int x = findIdx(root->left, left, right, target);
        int y = findIdx(root->right, left, right, target);
        
        return target[x] < target[y] ? x : y;
    }

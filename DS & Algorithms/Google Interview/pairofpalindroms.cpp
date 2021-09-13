class Solution {
public:
    struct TrieNode{
        vector<TrieNode*> c;
        int index;
        set<int> s;
        TrieNode() : index(-1) {
            for(int i = 0; i < 26; i++)
                c.push_back(NULL);
            s.clear();
        }
    };
    
    bool palin(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void insert(TrieNode* root, int ind, string s) {
        
        for(int i = s.size()-1; i >= 0; i--) {
            if(i == 0 || palin(s, 0, i)) {
                root->s.insert(ind);
            }
            
            char c = s[i];
            if(root->c[c-'a'] == NULL) {
                root->c[c-'a'] = new TrieNode();
            }
            
            root = root->c[c-'a'];
        }
        
        root->index = ind;
        root->s.insert(ind);
    }
    vector<vector<int>> ans;
    void search(TrieNode* root, int ind, string s) {
        for(int i = 0; i < s.size(); i++) {
            if(root->index >= 0 && root->index != ind && palin(s, i, s.size()-1)) {
                ans.push_back({ind, root->index});
            }
            
            char c = s[i];
            if(root->c[c-'a'] == NULL)
                return;
            
            root = root->c[c-'a'];
        }
        
        for(int x : root->s) {
            if(x != ind) {
                ans.push_back({ind,x});
            }
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < words.size(); i++) {
            insert(root, i, words[i]);
        }
        
        for(int i = 0; i < words.size(); i++) {
            search(root, i, words[i]);
        }
        
        return ans;
    }
};

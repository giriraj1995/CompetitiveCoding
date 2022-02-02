class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        
        vector<int> alphas = vector<int>(26, 0);
        
        for(char c : p) {
            alphas[c-'a']++;
        }
        
        int i = 0;
        int j = 0;
        
        vector<int> ans;
        while(j < s.size()) {
            alphas[s[j]-'a']--;
            
            if(alphas[s[j]-'a'] >= 0) {
                n--;
            }
            else{
                while(alphas[s[j]-'a'] < 0) {
                    alphas[s[i]-'a']++;
                    
                    if(alphas[s[i]-'a'] > 0)
                        n++;
                    
                    i++;
                }
            }
            
            j++;
            if(n == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};

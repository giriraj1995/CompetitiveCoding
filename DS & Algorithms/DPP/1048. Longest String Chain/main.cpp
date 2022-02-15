class Solution {
public:
    
    bool isPre(string p, string t) {
        if(t.size()-1 != p.size())
            return false;
        
        if(t.substr(1).compare(p) == 0)
            return true;
        
        if(t.substr(0, t.size()-1).compare(p) == 0)
            return true;
        
        for(int i = 1; i < t.size()-1; i++) {
            if((t.substr(0,i) + t.substr(i+1)).compare(p) == 0)
                return true;
        }
        return false;
    }
    
    static bool cmp(string x, string y) {
        return x.size() < y.size() ? true : false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        int ans = 1;
        sort(words.begin(), words.end(), cmp);
        
        for(int i = 0; i < n; i++) {
            string x = words[i];
            mp[x] = 1;
            
            for(int t = 0; t < x.size(); t++) {
                string y = x.substr(0,t) + x.substr(t+1);
                if(mp.count(y)) {
                    mp[x] = max(mp[x], mp[y]+1);
                    ans = max(ans, mp[x]);
                }
            }
        }
        
        return ans;
    }
};

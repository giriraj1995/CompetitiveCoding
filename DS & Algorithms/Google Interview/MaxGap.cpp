class Solution {
public:
    int maximumGap(vector<int>& x) {
        int n = x.size();
        if(n < 2)
            return 0;
        
        vector<int> y(n, INT_MAX);
        set<int> s;
        int i;
        int ans = 0;

        for(i = 0; i < n; i++) {
            s.erase(x[i]);
            auto k = s.lower_bound(x[i]);
            if(k != s.end()) {
                y[i] = min(y[i], *k - x[i]);
            }
            s.insert(x[i]);
        }
        
        s.clear();
        for(i = n-1; i >= 0; i--) {
            s.erase(x[i]);
            auto k = s.lower_bound(x[i]);
            if(k != s.end()) {
                y[i] = min(y[i], *k - x[i]);
                ans = max(y[i], ans);
            }
            s.insert(x[i]);
        }
        
        return ans;
    }
};

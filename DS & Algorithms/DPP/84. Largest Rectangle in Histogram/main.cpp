class Solution {
public:
    vector<int> left(vector<int> x) {
        stack<int> s;
        vector<int> ans;
        for(int i = 0; i < x.size(); i++) {
            if(s.size() == 0) {
                ans.push_back(-1);
            }else if(x[s.top()] < x[i]){
                ans.push_back(s.top());
            }else{
                while(s.size() > 0 && x[s.top()] >= x[i]) {
                    s.pop();
                }
                
                if(s.size() == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> right(vector<int> x) {
        stack<int> s;
        vector<int> ans;
        for(int i = x.size()-1; i >= 0; i--) {
            if(s.size() == 0) {
                ans.push_back(x.size());
            }else if(x[s.top()] < x[i]){
                ans.push_back(s.top());
            }else{
                while(s.size() > 0 && x[s.top()] >= x[i]) {
                    s.pop();
                }
                
                if(s.size() == 0)
                    ans.push_back(x.size());
                else
                    ans.push_back(s.top());
            }
            
            s.push(i);
        }
        
    reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& h) {
        vector<int> l = left(h);
        vector<int> r = right(h);
        
        long long ans = 0;
        
        for(int i = 0; i < h.size(); i++) {
            ans = max(ans, (long long)((r[i] - l[i] - 1) * h[i]));
        }
        
        return ans;
    }
};

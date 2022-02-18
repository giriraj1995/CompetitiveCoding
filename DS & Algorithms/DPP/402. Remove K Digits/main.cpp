class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";
        
        stack<char> s;
        int i = 0;
        while(i < num.size()) {
            while(k > 0 && s.size() > 0 && num[i] < s.top()) {
                s.pop();
                k--;
            }
            s.push(num[i++]);
        }
        
        string ans = "";
        while(s.size() > 0) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        while(k > 0) {
            ans.pop_back();
            k--;
        }
        
        while(ans.size() > 0 && ans[0] == '0')
            ans.erase(ans.begin());
        
        return ans.compare("") == 0 ? "0" : ans;
    }
};

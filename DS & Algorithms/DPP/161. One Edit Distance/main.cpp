class Solution {
public:
//     vector<vector<int>> dp;
//     int solve(string s, string t, int n, int m) {
//         if(n == 0 || m == 0) {
//             return dp[n][m] = n+m;
//         }
       
//         if(dp[n][m] != -1)
//             return dp[n][m];
        
//         if (s[n-1] == t[m-1]) {
//             return dp[n][m] = solve(s,t,n-1,m-1);
//         } else {
//             int x = 1+solve(s,t,n-1,m);
//             int y = 1+solve(s,t,n,m-1);
//             int z = 1+solve(s,t,n-1,m-1);
//             return dp[n][m] = min(min(x,y),z);
//         }
//     }
    
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(s.compare(t) == 0)
            return false;
        
        // dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        // if(solve(s,t,n,m) == 1)
        //     return true;
        
        if(n == 0 || m == 0) {
            return abs(n-m) == 1;
        }
        
        if(abs(n-m) > 1)
            return false;
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                if(s.substr(i+1).compare(t.substr(j)) == 0 || s.substr(i).compare(t.substr(j+1)) == 0 || s.substr(i+1).compare(t.substr(j+1)) == 0)
                    return true;
                
                return false;
            }
        }
        
        if(i != n || j != m) {
            return abs(n-m) == 1;
        }
        
        return false;
    }
};

    vector<long long> dp;
    int cat(long long n) {
        dp = vector<long long>(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            int x = i-1;
            dp[i] = ((2*(2*(x)+1))/(x+2)) * dp[x];
        }
        
        return dp[n];
    }
    
    int numTrees(int n) {
        return cat(n);
    }

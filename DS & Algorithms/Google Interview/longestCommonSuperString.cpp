    vector<vector<int>> dp;
    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        string x = "";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]){
                    x += text1[i-1];
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int s= dp[text1.size()][text2.size()];
        
        if(text1.substr(0,s).compare(x) == 0)
            return text1.substr(s);
        
        return text1.substr(0,s);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1.size() > str2.size())
            return shortestCommonSupersequence(str2,str1);
        string x = longestCommonSubsequence(str1,str2);
        
        int n = str1.size();
        int m = str2.size();
        
        string ans1 = x+str2;
        string ans2 = str2+x;
        
        if(longestCommonSubsequence(str1,ans1).size() == 0)
            return ans1;
        
        return ans2;
    }

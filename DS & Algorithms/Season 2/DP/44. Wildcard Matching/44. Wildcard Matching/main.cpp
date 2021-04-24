//
//  main.cpp
//  44. Wildcard Matching
//
//  Created by Giriraj Saigal on 23/04/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

bool solve(string s, string p, vector<vector<int>> &dp) {
    int i = s.size();
    int j = p.size();
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(i == 0 && j == 0)
        return dp[i][j] = true;
    
    if(j == 0)
        return dp[i][j] = false;
    
    if(i == 0){
        for(char c : p) {
            if(c != '*')
                return dp[i][j] = false;
        }
        return dp[i][j] = true;
    }
    
    if(s[i-1] == p[j-1] || p[j-1] == '?') {
        return dp[i][j] = solve(s.substr(0,(int)s.size()-1),p.substr(0,(int)p.size()-1),dp);
    }else if(p[j-1] == '*') {
        bool x = solve(s.substr(0,(int)s.size()-1),p,dp);
        bool y = solve(s,p.substr(0,(int)p.size()-1),dp);
        bool z = solve(s.substr(0,(int)s.size()-1),p.substr(0,(int)p.size()-1),dp);
        return dp[i][j] = x || y || z;
    }else
        return dp[i][j] = false;
}

bool solve(string s, string p) {
    int n = (int)s.size();
    int m = (int)p.size();
    
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    
    dp[0][0] = true;
    
    for(int i = 1; i <= n; i++)
        dp[i][0] = false;
    
    bool isnotStar = false;
    for(int j = 1; j <= m; j++) {
        if(p[j-1] != '*')
            isnotStar = true;
        
        if(!isnotStar)
            dp[0][j] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
}

bool isMatch(string s, string p) {
    return solve(s, p);
}

int main(int argc, const char * argv[]) {
    cout<<isMatch("adceb","*a*b")<<endl;
    return 0;
}

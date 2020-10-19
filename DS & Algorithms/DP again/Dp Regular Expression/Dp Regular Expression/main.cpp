//
//  main.cpp
//  Dp Regular Expression
//
//  Created by Giriraj Saigal on 19/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

bool solve(string a, string b, int n, int m){
    
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    
    dp[0][0] = true;
    
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = false;
    }
    
    for(int j = 1; j <= m; j++)
    {
        if(b[j-1] == '*')
            dp[0][j] = dp[0][j-1];
        else
            dp[0][j] = false;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            if(a[i-1] == b[j-1] || b[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(b[j-1] == '*'){
                dp[i][j] = dp[i-1][j-1] | dp[i][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
    
    
}

int isMatch(const string A, const string B)
{
    return solve(A, B, A.size(), B.size());
}

int main(int argc, const char * argv[]) {
    isMatch("cab", "c*a*b");
    return 0;
}

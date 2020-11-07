//
//  main.cpp
//  Evaluate Expression to true
//
//  Created by Giriraj Saigal on 07/11/20.
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

int solve(int i, int j, int want, string A, vector<vector<vector<int>>> &dp){
    
    if(i == j) {
        if(A[i] == 'T') {
            dp[i][j][1] = 1;
            dp[i][j][0] = 0;
        }else{
            dp[i][j][1] = 0;
            dp[i][j][0] = 1;
        }
        return dp[i][j][want];
    }
    
    if(i > j)
        return 0;
    
    if(dp[i][j][want] != -1)
        return dp[i][j][want];
    
    int ways = 0;
    int mod = 1003;
    
    for(int k = i + 1; k < j; k = k + 2) {
        
        int leftTrue;
        
        if(dp[i][k-1][1] != -1)
            leftTrue = dp[i][k-1][1];
        else
            leftTrue = dp[i][k-1][1] = solve(i, k - 1, 1, A, dp) % mod;
            
        int rightTrue;
        
        if(dp[k+1][j][1] != -1)
            rightTrue = dp[k+1][j][1];
        else
            rightTrue = dp[k+1][j][1] = solve(k+1, j, 1, A, dp) % mod;
            
        int leftfalse;
        
        if(dp[i][k-1][0] != -1)
            leftfalse = dp[i][k-1][0];
        else
            leftfalse = dp[i][k-1][0] = solve(i, k - 1, 0, A, dp) % mod;
            
        int rightfalse;
        
        if(dp[k+1][j][0] != -1)
            rightfalse = dp[k+1][j][0];
        else
            rightfalse = dp[k+1][j][0] = solve(k+1, j, 0, A, dp) % mod;
        
        if(want == 1) {
            if(A[k] == '&') {
                ways = (ways%mod + (leftTrue * rightTrue)%mod)%mod;
            }else if(A[k] == '|'){
                ways = (ways%mod + (leftTrue * rightTrue)%mod)%mod;
                ways = (ways%mod + (leftfalse * rightTrue)%mod)%mod;
                ways = (ways%mod + (leftTrue * rightfalse)%mod)%mod;
            }else{
                ways = (ways%mod + (leftTrue * rightfalse)%mod)%mod;
                ways = (ways%mod + (leftfalse * rightTrue)%mod)%mod;
            }
        }else{
            if(A[k] == '&') {
                ways = (ways%mod + (leftTrue * rightfalse)%mod)%mod;
                ways = (ways%mod + (leftfalse * rightTrue)%mod)%mod;
                ways = (ways%mod + (leftfalse * rightfalse)%mod)%mod;
            }else if(A[k] == '|'){
                ways = (ways%mod + (leftfalse * rightfalse)%mod)%mod;
            }else{
                ways = (ways%mod + (leftTrue * rightTrue)%mod)%mod;
                ways = (ways%mod + (leftfalse * rightfalse)%mod)%mod;
            }
        }
    }
    
    return dp[i][j][want] = ways;
}


int main(int argc, const char * argv[]) {
    string exp = "T^T^T^F|F&F^F|T";
    int n = exp.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
    cout<<solve(0, exp.size()-1, true, exp, dp);
    return 0;
}

//
//  main.cpp
//  Min Sum Path in triangle
//
//  Created by Giriraj Saigal on 11/11/20.
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
int calls = 0;

int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int> > &A) {
    calls++;
    if (i == A.size()-1)
        return A[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int t = A[i][j];
    
    int ans = INT_MAX;
    
    ans = min(ans, solve(i+1, j, dp, A));
    ans = min(ans, solve(i+1, j+1, dp, A));
    
    dp[i][j] = ans + t;
    
    return dp[i][j];
}

int minimumTotal(vector<vector<int> > &A)
{
    int dp[A.size()];
    int n = A.size() - 1;
    for(int i=0;i<A[n].size();i++)
        dp[i] = A[n][i];
    
    for(int i=A.size()-2;i>=0;i--)
    {
        for(int j=0;j<A[i].size();j++)
        {
            dp[j] = A[i][j] + min(dp[j],dp[j+1]);
        }
    }
    // int mn = INT_MAX;
    // for(int i=0;i<A[n].size();i++)
    //     mn = min(mn,dp[i]);
        
    return dp[0];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x = {
        
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
        
    };
//    int n = x.size();
//    vector<vector<int>> dp(n+1, vector<int>(n+1 ,-1));
    
    minimumTotal(x);
    return 0;
}

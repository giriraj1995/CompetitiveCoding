//
//  main.cpp
//  Buy stocks
//
//  Created by Giriraj Saigal on 09/11/20.
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

int solve(int i, vector<int> A, int t, int s, vector<vector<vector<int>>> &dp) {

    if(dp[i][t][s] != -1)
        return dp[i][t][s];

    if(t == 2)
        return dp[i][t][s] = 0;

    if(i == A.size())
        return dp[i][t][s] = 0;

    int ans = 0;

    if(s == 1) {
        int sell;
        //sell
        if(dp[i+1][t+1][s-1] != -1)
            sell = dp[i+1][t+1][s-1];
        else
            sell = dp[i+1][t+1][s-1] = solve(i+1, A,t+1,s-1,dp);

        ans = max(ans, sell);
    }else{
        int buy;

        if(dp[i+1][t][s+1] != -1)
            buy = dp[i+1][t][s+1];
        else
            buy = dp[i+1][t][s+1] = solve(i+1, A,t,s+1,dp);

        ans = max(ans, buy);
    }

    int noth;

    if(dp[i+1][t][s] != -1)
        noth = dp[i+1][t][s];
    else
        noth = dp[i+1][t][s] = solve(i+1, A,t,s,dp);

    ans = max(ans, noth);

    return dp[i][t][s] = ans;

}

int maxProfit(const vector<int> &A) {

    int n = A.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, -1)));

    return solve(0, A, 0, 0, dp);
}

int maxProfit_Fast(const vector<int> &a)
{
    vector<int> A = a;
    int max_tran = 2 , no_of_days = A.size();
    
    if(no_of_days <= 1)
        return 0;
        
    vector<vector<int>> dp(max_tran + 1, vector<int>(no_of_days, 0));
    
    for(int i=1;i<=max_tran;i++)
    {
        int max_diff=-A[0];
        
        for(int j=1;j<no_of_days;j++)
        {
            dp[i][j]=max(max_diff+A[j], dp[i][j-1]);
            max_diff=max(max_diff, dp[i-1][j]-A[j]);
        }
    }
    
    return dp[max_tran][no_of_days-1];
}


int main(int argc, const char * argv[]) {
    vector<int> x = {7,2,4,8,7};
    maxProfit_Fast(x);
    return 0;
}

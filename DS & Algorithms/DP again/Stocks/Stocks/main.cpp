//
//  main.cpp
//  Stocks
//
//  Created by Giriraj Saigal on 03/11/20.
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

long solve(long shares, int i, vector<int> prices, vector<vector<long>> &dp) {
    
//    int n = prices.size();
//
//    if(dp[shares][i] != -1)
//        return dp[shares][i];
//
//    if(i == n) {
//        return 0;
//    }
//
//    long ans = 0;
//    //buy
//    ans = max(-prices[i] + solve(shares+1, i+1, prices, dp), ans);
//
//    //sell + nothing
//    for(int j = 0; j <= shares; j++) {
//        ans = max((prices[i] * j) + solve(shares-j, i+1, prices, dp), ans);
//    }
//
//    return dp[shares][i] = ans;
    
    long profit = 0L;
    int maxSoFar = 0;
    for (int i = prices.size() - 1; i > -1 ; i--) {
        if (prices[i] >= maxSoFar) {
            maxSoFar = prices[i];
        }
        profit += maxSoFar - prices[i];
    }
    
    return profit;
    
}

long stockmax(vector<int> prices) {
    long shares = 0;
    int n = prices.size();
    
    vector<vector<long>> dp(n+1, vector<long>(n+1, -1));
    
    if(n == 0 || n == 1)
        return 0;
        
    return solve(shares, 0, prices, dp);
}


int main(int argc, const char * argv[]) {
    cout<<stockmax({1 ,2 ,100});
    return 0;
}

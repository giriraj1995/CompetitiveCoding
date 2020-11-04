//
//  main.cpp
//  Matrix chain Mul
//
//  Created by Giriraj Saigal on 04/11/20.
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

long solve(vector<int> arr, int i, int j, vector<vector<long>> &dp){
    
    if(j == i + 1){
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    long ans = INT_MAX;
    
    for(int k = i+1; k < j; k++) {
        long x = arr[i] * arr[k] * arr[j];
        long left;
        long right;
        
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = dp[i][k] = solve(arr, i, k, dp);
        
        if(dp[k][j] != -1)
            right = dp[k][j];
        else
            dp[k][j] = right = solve(arr, k , j, dp);
        
        ans = min(ans, x + left + right);
    }
    
    return dp[i][j] = ans;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {40,20,30,10,30};
    int i = 0;
    int j = (int)arr.size()-1;
    int n = arr.size();
    vector<vector<long>> dp(n, (vector<long>(n, -1)));
    cout<<solve(arr, i, j, dp)<<endl;
    return 0;
}

//
//  main.cpp
//  MinPath Matrix
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

int solve(int i, int j, vector<vector<int>> A, vector<vector<int>> &dp) {
    
    if(i == 0 && j == 0){
        return A[i][j];
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int next_val = INT_MAX;
    
    if(i-1 >= 0){
        int val;
        if(dp[i-1][j] != -1)
        {
            val = dp[i-1][j];
        }else{
            dp[i-1][j] = val = solve(i-1, j, A, dp);
        }
        
        next_val = min(next_val, val);
    }
        
    if(j-1 >= 0){
        int val;
        if(dp[i][j-1] != -1)
        {
            val = dp[i][j-1];
        }else{
            dp[i][j-1] = val = solve(i, j-1, A, dp);
        }
        next_val = min(next_val, val);
    }
        
    return dp[i][j] = A[i][j] + next_val;
}

int minPathSum(vector<vector<int> > &A) {
    
    // int n = A.size();
    
    // if(n == 0)
    //     return 0;
        
    // int m = A[0].size();
    
    // if(m == 0)
    //     return 0;
        
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    // return solve(n-1, m-1, A, dp);
    
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    if(m == 0)
        return 0;
        
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    dp[0][0] = A[0][0];
    
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + A[i][0];
    }
    
    for(int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + A[0][j];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    
    return dp[n-1][m-1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

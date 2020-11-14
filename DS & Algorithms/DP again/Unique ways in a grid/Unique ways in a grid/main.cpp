//
//  main.cpp
//  Unique ways in a grid
//
//  Created by Giriraj Saigal on 14/11/20.
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

int solve(int i, int j, vector<vector<int> > &A, vector<vector<int>> &dp) {
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(A[i][j] == 1)
        return dp[i][j] = 0;
        
    if(i == A.size()-1 && j == A[0].size()-1){
        return dp[i][j] = 1;
    }
    
    int ways = 0;
    
    if(i+1 < A.size()) {
        dp[i+1][j] = solve(i+1, j, A, dp);
        ways += dp[i+1][j];
    }
    
    if(j+1 < A[0].size()) {
        dp[i][j+1] = solve(i, j+1, A, dp);
        ways += dp[i][j+1];
    }
    
    return dp[i][j] = ways;
}

int uniquePathsWithObstacles(vector<vector<int> > A) {
    int n = A.size();
    
    if(n == 0)
        return 0;
        
    int m = A[0].size();
    
    if(m == 0)
        return 0;
        
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
    return solve(0, 0, A, dp);
}


int main(int argc, const char * argv[]) {
    uniquePathsWithObstacles({{0,1}});
    return 0;
}

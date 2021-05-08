//
//  main.cpp
//  62. Unique Paths
//
//  Created by Giriraj Saigal on 05/05/21.
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

int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if(i > m || j > n)
        return 0;
    
    if(i == m && j == n) {
        return dp[i][j] = 1;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int down = solve(i+1, j, m, n, dp);
    int right = solve(i, j+1, m, n, dp);
    
    return dp[i][j] = down + right;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    solve(1,1,m,n,dp);
    return dp[1][1];
}

int main(int argc, const char * argv[]) {
    uniquePaths(3,7);
    return 0;
}

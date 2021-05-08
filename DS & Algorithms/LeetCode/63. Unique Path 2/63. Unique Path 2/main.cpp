//
//  main.cpp
//  63. Unique Path 2
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
int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp) {
    
    if(i >= n || j >= m)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(grid[i][j] == 1)
        return dp[i][j] = 0;
    
    if(i == n-1 && j == m-1)
        return dp[i][j] = 1;
    
    int down = solve(i+1, j, n, m, grid, dp);
    int right = solve(i, j+1, n, m, grid, dp);
    
    return dp[i][j] = down + right;
}
int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(0,0,n,m,obstacleGrid,dp);
    return dp[0][0];
}

int main(int argc, const char * argv[]) {
    uniquePathsWithObstacles({{0,0},{0,1}});
    return 0;
}

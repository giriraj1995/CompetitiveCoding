//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by Giriraj Saigal on 07/05/21.
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

long long solve(int n, int m, vector<vector<int>> grid) {
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
                continue;
            }
            
            if(i-1 < 0 || j-1 < 0) {
                if(i-1 < 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }else{
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
            }else{
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    return dp[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    
    solve(n,m,grid);
    return 0;
}

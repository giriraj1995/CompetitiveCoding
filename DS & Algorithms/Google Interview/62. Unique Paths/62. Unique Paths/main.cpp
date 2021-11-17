//
//  main.cpp
//  62. Unique Paths
//
//  Created by Giriraj Saigal on 17/11/21.
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

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1)
            return 1;
        
        if(i > m-1 || j > n-1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = solve(i+1, j, m, n);
        int right = solve(i, j+1, m, n);
        
        return dp[i][j] = down + right;
    }
    
    int uniquePaths(int m, int n) {
       int i = 0;
       int j = 0;
        dp = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return solve(i,j,m,n);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}

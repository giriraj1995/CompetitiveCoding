//
//  main.cpp
//  120. Triangle
//
//  Created by Giriraj Saigal on 22/06/21.
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

int solve(int i, int j, vector<vector<int>>& T, vector<vector<int>> &dp) {
    if(i == T.size()){
        return dp[i][j] = T[i-1][j-1];
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    return dp[i][j] = T[i-1][j-1] + min(solve(i+1,j,T,dp), solve(i+1,j+1, T,dp));
    
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1,1,triangle,dp);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

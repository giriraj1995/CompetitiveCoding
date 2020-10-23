//
//  main.cpp
//  Max area of square in a grid
//
//  Created by Giriraj Saigal on 22/10/20.
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

int solve(vector<vector<int> > A) {
    
    int n = A.size();
    int m = A[0].size();
    
    if(n == 0 || m == 0)
        return 0;
    
    if(n == 1){
        
        for(int i = 0; i < n; i++)
            if(A[i][0] == 1)
                return 1;
                
        return 0;
    }
        
    if(m == 1){
        
        for(int j = 0; j < m; j++)
            if(A[0][j] == 1)
                return 1;
        
        return 0;
    }
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for(int j = 0; j < m; j++)
        dp[0][j] = A[0][j];
        
    for(int i = 0; i < n; i++)
        dp[i][0] = A[i][0];
        
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(A[i][j] == 1){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }else
                dp[i][j] = 0;
        }
    }
    
    return ans * ans;
    
}

int main(int argc, const char * argv[]) {
    cout<<solve(  {{0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0}});
    return 0;
}

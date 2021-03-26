//
//  main.cpp
//  Subset Problem
//
//  Created by Giriraj Saigal on 26/03/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

bool subset1(int i, vector<int> A, int W, vector<vector<int>> &dp) {
    if(W == 0)
        return 1;
    
    if(W < 0)
        return 0;
        
    if(i == 0)
        return 0;
        
    if(dp[i][W] != -1)
        return dp[i][W];
        
    if(A[i-1] <= W) {
        int with = subset1(i-1, A, W - A[i-1], dp);
        int without = subset1(i-1, A, W, dp);
        
        if(with || without)
            return dp[i][W] = 1;
        else
            return dp[i][W] = 0;
    }else{
        int without = subset1(i-1, A, W, dp);
        return dp[i][W] = without;
    }
    
}

bool subset(vector<int> A, int W) {
    int n = A.size();
    vector<vector<bool>> dp(n+1, vector<bool>(W+1, false));
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(A[i-1] <= j) {
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    
    return dp[n][W];
}

bool solve(vector<int> A, int B) {
    return subset(A, B);
}


int main(int argc, const char * argv[]) {
    cout<<solve({3, 34, 4, 12, 5, 2 }, 9);
    return 0;
}

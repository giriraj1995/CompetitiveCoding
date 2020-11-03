//
//  main.cpp
//  Coins in a line
//
//  Created by Giriraj Saigal on 03/11/20.
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

int solve(int i, int j, vector<int> A, int turn, vector<vector<vector<int>>> &dp) {
    
    if(i > j) {
        return 0;
    }
    
    if(dp[i][j][turn] != -1)
        return dp[i][j][turn];
    
    if(i == j && turn == 0) {
        return 0;
    }else if(i == j && turn == 1){
        return dp[i][j][turn] = A[i];
    }
    
    int x;

    if(turn == 1) {
        x = max(A[i] + solve(i + 1, j, A, 0, dp), A[j] + solve(i, j - 1, A, 0, dp));
    } else {
        
        if(A[i] > A[j]) {
            x = solve(i + 1, j, A, 1, dp);
        }
        else if (A[i] < A[j])
        {
            x = solve(i, j - 1, A, 1, dp);
        }
        else
        {
            x = max(solve(i + 1, j, A, 1, dp), solve(i, j - 1, A, 1, dp));
        }
        
    }
    
    dp[i][j][turn] = x;
    
    return x;
    
}

int maxcoin(vector<int> A) {
    
    int i = 0;
    int j = A.size()-1;
    
    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    
    if(i == j) {
        return A[i];
    }
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    solve(i, j, A, 1, dp);
    
    return dp[i][j][1];
}


int main(int argc, const char * argv[]) {
    cout<<maxcoin({1, 2, 3, 4});
    return 0;
}

//
//  main.cpp
//  Repeating Sub-Sequence
//
//  Created by Giriraj Saigal on 25/03/21.
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

int solve(string A) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[i-1] == A[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][n] > 1 ? 1 : 0;
}

int anytwo(string A) {
    int n = A.size();
    if(n == 1)
        return 0;
    return solve(A);
}


int main(int argc, const char * argv[]) {
    anytwo("aabb");
    return 0;
}

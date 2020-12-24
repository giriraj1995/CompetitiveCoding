//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by Giriraj Saigal on 24/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>

int solve1(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    vector<vector<int >> dp(n+1, vector<int>(m+1, 0 ));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}
int Solution::solve(string A, string B) {
    return solve1(A, B);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  Regular Expression II
//
//  Created by Giriraj Saigal on 18/06/21.
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

int isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = 1;

    for(int j = 1; j <= m; j++) {
        if(B[j-1] != '*'){
            dp[0][j] = 0;
        }else{
            dp[0][j] = dp[0][j-2];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(A[i-1] == B[j-1] || B[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }else if(B[j-1] == '*') {
                if(B[j-2] == A[i-1] || B[j-2] == '.') {
                    dp[i][j] = dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-2];
                }
            }else{
                dp[i][j] = 0;
            }

        }
    }

    return dp[n][m];
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

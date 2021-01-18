//
//  main.cpp
//  Max LCS
//
//  Created by Giriraj Saigal on 18/01/21.
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

vector<int> maxLCS(string A) {
    int n = A.size();
    
    if(n == 1)
        return {1,0};
    
    string B = string(A.rbegin(), A.rend());
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int o = -1;
    int x = -1;
    
    int i,j;
    for(i = 1, j = n-1; (i < n),(j > 0); i++,j--) {
            if(dp[i][j] > x) {
                x = dp[i][j];
                o = i;
            }
    }
    
    
    return {o, x};
}

int main(int argc, const char * argv[]) {
    maxLCS("a");
    return 0;
}

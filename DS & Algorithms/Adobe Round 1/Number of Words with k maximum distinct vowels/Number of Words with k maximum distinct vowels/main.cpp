//
//  main.cpp
//  Number of Words with k maximum distinct vowels
//
//  Created by Giriraj Saigal on 13/12/20.
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

int kvowelwords(int N,int K)
{
    const int MOD = 1000000007;
    vector<vector<long long>> dp(N+1, vector<long long>(K+1, 0));

    dp[0][0] = 1;

    int sum = 1;
    for(int i = 1; i <= N; i++) {
        
        sum = (21 * sum) % MOD;
        dp[i][0] = sum;
        
        for(int j = 1; j <= min(K, i); j++) {
            dp[i][j] = (dp[i-1][j-1] * 5) % MOD;
            sum = (sum + dp[i][j]) % MOD;
        }
        
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    kvowelwords(5,2);
    return 0;
}

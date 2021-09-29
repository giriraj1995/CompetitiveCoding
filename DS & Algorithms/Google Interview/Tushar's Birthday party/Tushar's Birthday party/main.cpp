//
//  main.cpp
//  Tushar's Birthday party
//
//  Created by Giriraj Saigal on 29/09/21.
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

int solve(const vector<int> A, const vector<int> B, const vector<int> C) {
    int cap = INT_MIN;
    
    for(int i : A) {
        cap = max(cap , i);
    }
    
    int n = B.size();
    vector<vector<long long>> dp(n+1, vector<long long>(cap+1, INT_MAX));
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    //{2, 3, 1, 5, 4 },{3, 2, 4, 1},{1, 2, 5, 10}
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= cap; j++) {
            if(B[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-B[i-1]]+C[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int ans = 0;
    int i = n;
    
    for(int j = 0; j < A.size(); j++) {
        ans += dp[n][A[j]];
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << solve({2, 3, 1, 5, 4 },{3, 2, 4, 1},{1, 2, 5, 10});
    return 0;
}

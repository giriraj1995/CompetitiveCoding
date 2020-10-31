//
//  main.cpp
//  Longest Arthimatic Progression
//
//  Created by Giriraj Saigal on 30/10/20.
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

int solve(const vector<int> A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    
    int ans = 0;
    unordered_map<int, int> mp;
    vector<unordered_map<int, int>> v(n, mp);
    
    for(int i = 1; i < n; i++) {
                
        for(int j = 0; j < i; j++) {
            
            if(v[j].find(A[i] - A[j]) != v[j].end()) {
                v[i][A[i] - A[j]] = v[j][A[i] - A[j]] + 1;
            }else{
                v[i][A[i] - A[j]]++;
            }
            
            ans = max(ans, v[i][A[i] - A[j]]);
        }
                
    }
    
    return ans+1;
}

long getWays(int n, vector<long> c) {

    int a = (int)c.size();
    vector<vector<long>> dp(a+1, vector<long>(n+1, 0));

    for(int i = 0; i <= a; i++){
        dp[i][0] = 1;
    }

    int ans = 0;

    for(int i = 1; i <= a; i++) {

        for(int j = 1; j <= n; j++) {

            if(c[i-1] <= j) {
                dp[i][j] = dp[i-1][j-c[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }

        }

    }

    return dp[a][n];
}


int main(int argc, const char * argv[]) {
    cout<<solve({100, 10, 8, 300, 6, 1, 4, 2});
    return 0;
}

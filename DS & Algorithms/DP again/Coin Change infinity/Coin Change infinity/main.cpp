//
//  main.cpp
//  Coin Change infinity
//
//  Created by Giriraj Saigal on 15/11/20.
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

//int solve(vector<int> &A, int B) {
//
//    int n = A.size();
//    int m = B;
//
//    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//
//    for(int i = 1; i <= n; i++) {
//        dp[i][0] = 1;
//    }
//
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= m; j++) {
//
//            if(A[i-1] <= j) {
//                dp[i][j] = max(1 + dp[i][j-A[i-1]], dp[i-1][j]);
//            }else{
//                dp[i][j] = dp[i-1][j];
//            }
//        }
//    }
//
//    return dp[n][m];
//
//}
//
//int coinchange2(vector<int> A, int B) {
//
//    return solve(A, B);
//}

const int MODVAL = 1000007;

int coinchange2(vector<int> A, int B) {
    int len = A.size();
    vector<int> vec(B+1, 0);
    vec[0] = 1;
    for(int i=0; i<len; i++){
        for(int j=1; j<=B; j++){
            int a = ((j-A[i]) < 0 ) ? 0 : vec[j-A[i]];
            int b = i > 0 ? vec[j] : 0;
            vec[j] = (a + b)%MODVAL;
        }
    }
    return vec[B];
}


int main(int argc, const char * argv[]) {
    coinchange2({1,2,3}, 4);
    return 0;
}

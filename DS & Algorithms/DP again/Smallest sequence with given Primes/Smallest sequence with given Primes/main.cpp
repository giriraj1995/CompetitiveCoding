//
//  main.cpp
//  Smallest sequence with given Primes
//
//  Created by Giriraj Saigal on 21/10/20.
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

int min(int a, int b) {
    return a>b ? b : a;
}

vector<int> solve(int A, int B, int C, int D) {
    
    vector<vector<int>> dp(3, vector<int>(D, 0));
    
    vector<int> arr;
    arr.push_back(A);
    arr.push_back(B);
    arr.push_back(C);

    
    for(int i = 0; i < 3; i++) {
        dp[i][0] = A;
    }
    
    for(int j = 0; j < D; j++) {
        dp[0][j] = pow(A, j+1);
    }
    
    for(int i = 1; i < 3; i++){
        for(int j = 1; j < D; j++){
            
            int a = min(dp[i-1][j], arr[i] * dp[i][j-1]);
            int b = min(dp[i-1][j-1] * arr[i-1], pow(arr[i], j));
            dp[i][j] = min(a,b);
            
        }
    }
    
    return dp[2];
}


int main(int argc, const char * argv[]) {
    solve(2,3,5, 5);
    return 0;
}

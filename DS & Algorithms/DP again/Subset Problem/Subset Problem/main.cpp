//
//  main.cpp
//  Subset Problem
//
//  Created by Giriraj Saigal on 12/10/20.
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

int solve(vector<int> &A, int B) {
    
    int n = A.size();
    bool dp[n+1][B+1];
    
    for(int j = 0; j <= B; j++){
        dp[0][j] = false;
    }
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= B; j++){
            if(A[i-1] <= B){
                dp[i][j] = dp[i-1][j-A[i-1]] | dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][B];
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

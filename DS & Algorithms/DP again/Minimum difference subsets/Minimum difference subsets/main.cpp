//
//  main.cpp
//  Minimum difference subsets
//
//  Created by Giriraj Saigal on 28/10/20.
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

vector<bool> knapsack(vector<int> A, int C) {
    
    int n = A.size();
    
    vector<vector<bool>> dp(n+1, vector<bool>(C+1, false));
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= C; j++) {
            
            if(A[i-1] <= j) {
                
                dp[i][j] = dp[i-1][j-A[i-1]] | dp[i-1][j];
                
            }else {
                
                dp[i][j] = dp[i-1][j];
                
            }
            
        }
    }
    
    return dp[n];
}

int solve(vector<int> &A) {
    
    int sum = 0;
    
    for(int i : A) {
        sum += i;
    }
    
    vector<bool> dp = knapsack(A, sum);
    
    int ans = INT_MAX;
    
    for(int i = 0; i <= sum/2; i++) {
        
        if(dp[i] == false){
            continue;
        }
        
        else {
            
            ans = min(ans, sum - 2*i);
            
        }
        
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {58, 38, 60, 24, 42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47, 6, 91, 30, 71};
    cout<<solve(x);
    return 0;
}

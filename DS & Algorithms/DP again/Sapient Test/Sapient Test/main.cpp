//
//  main.cpp
//  Sapient Test
//
//  Created by Giriraj Saigal on 17/10/20.
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

int result(int a, int b, int c){
    if(a < b){
        if(a < c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b < c){
            return b;
        }else{
            return c;
        }
    }
}

int solve2(vector<int> A, vector<int> B, int C){
    
    int n = A.size();
    int m = B.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    
    for(int j = 1; j <= m; j++)
        dp[0][j] = INT_MAX/2;
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = result(C+dp[i-1][j-1], C+dp[i][j-1], dp[i-1][j]);
            }
            
        }
    }
    
    return dp[n][m];
    
}

int solve(vector<int> A, vector<int> B, int C) {
    
    if(B.size() > A.size())
        return INT_MAX;
        
    
    return solve2(A, B, C);
}

int main(int argc, const char * argv[]) {
    cout<<solve({1,6,3,5,10}, {3,1,5}, 2);
    return 0;
}

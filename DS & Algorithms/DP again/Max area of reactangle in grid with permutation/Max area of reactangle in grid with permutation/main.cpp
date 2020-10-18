//
//  main.cpp
//  Max area of reactangle in grid with permutation
//
//  Created by Giriraj Saigal on 18/10/20.
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

bool comp(int a, int b){
    if(a > b)
        return true;
    else
        return false;
}

int solve(vector<vector<int> > A) {
    
    if(A.size() == 0)
        return 0;
        
    if(A[0].size() == 0)
        return 0;
    
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    dp[0] = A[0];
        
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)
        {
            if(A[i][j] != 0)
                dp[i][j] = 1 + dp[i-1][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        sort(dp[i].begin(), dp[i].end(), comp);
    }
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < m; j++){
            
            if(dp[i][j] == 0)
                break;
            
            int k = dp[i][j] * (j+1);
            ans = max(ans, k);
            
        }
        
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x = { {0, 1, 0, 1, 0},
       {0, 1, 1, 1, 1},
       {1, 1, 1, 0, 1},
       {1, 1, 1, 1, 1}
    };
    cout<<solve(x);
    return 0;
}

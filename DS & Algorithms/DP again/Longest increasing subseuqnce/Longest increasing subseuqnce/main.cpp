//
//  main.cpp
//  Longest increasing subseuqnce
//
//  Created by Giriraj Saigal on 10/10/20.
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

int solve(vector<vector<int> > A) {
        
    int n = A.size();
    
    if(n == 1 || n == 0)
        return n;
    
    int dp[n];
    
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    
    int ans = 1;
    
    for(int i = 1; i < n; i++){
        
        for(int j = 0; j < i; j++){
            
            if(A[i][0] > A[j][1] && dp[j] >= dp[i]){
                dp[i] = dp[j]+1;
                ans = max(ans, dp[i]);
            }
            
        }
        
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve({
        {414, 470},
         {359, 527},
        {87, 945},
           {41, 831}
    });
    return 0;
}

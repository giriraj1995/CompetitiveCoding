//
//  main.cpp
//  Max Sum without Ajacent Elements
//
//  Created by Giriraj Saigal on 17/11/20.
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

int adjacent(vector<vector<int> > A) {
    
    int m = A[0].size();
    
    if(m == 0)
        return 0;
        
    if(m == 1) {
        return A[0][0] > A[1][0] ? A[0][0] : A[1][0];
    }
    
    vector<int> flag(m+1, 0);
    vector<int> dp(m+1, 0);
    
    dp[1] = A[0][0] > A[1][0] ? A[0][0] : A[1][0];
    flag[1] = 1;
    
    for(int i = 2; i <= m; i++) {
        int t = A[0][i-1] > A[1][i-1] ? A[0][i-1] : A[1][i-1];
        
        if(flag[i-1] == 0) {
            flag[i] = 1;
            dp[i] = dp[i-1] + t;
        }else{
            if(dp[i-2] + t > dp[i-1]){
                flag[i] = 1;
                flag[i-1] = 0;
                dp[i] = dp[i-2] + t;
            }else{
                dp[i] = dp[i-1];
            }
        }
    }
    
    return dp[m];
    
}


int main(int argc, const char * argv[]) {
    adjacent(
    {
        {74, 37, 82, 1},
        {66, 38, 16, 1}  });
    return 0;
}

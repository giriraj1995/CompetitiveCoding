//
//  main.cpp
//  Longest Subsequnce Lenght
//
//  Created by Giriraj Saigal on 11/10/20.
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

int longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1)
        return n;
    
    vector<int> dp(n,1);
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j] && dp[j] >= dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
    }
    
    
    vector<int> dp2(n,1);
            
    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(A[i] > A[j] && dp2[j] >= dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    
    int ans;
    
    for(int i = 0 ; i < n; i++){
        ans = max(ans, dp[i] + dp2[i]);
    }
    
    
    return ans-1;
}


int main(int argc, const char * argv[]) {
    cout<<longestSubsequenceLength({1, 11, 2, 10, 4, 2, 1});
    return 0;
}

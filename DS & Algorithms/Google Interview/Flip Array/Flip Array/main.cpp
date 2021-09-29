//
//  main.cpp
//  Flip Array
//
//  Created by Giriraj Saigal on 29/09/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int solve(const vector<int> &A) {
    int n = A.size();
        int sum=0;
        for(auto x:A)
            sum+=x;
        sum/=2;
        
        vector<vector<long long>> dp(n+1, vector<long long>(sum+1, INT_MAX));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(A[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-A[i-1]]+1);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int i = n;
        for(int j = sum; j >= 0; j--) {
            if(dp[i][j] != (INT_MAX))
                return dp[i][j];
        }
        
        return sum;
}

int main(int argc, const char * argv[]) {
    solve({9,6});
    return 0;
}

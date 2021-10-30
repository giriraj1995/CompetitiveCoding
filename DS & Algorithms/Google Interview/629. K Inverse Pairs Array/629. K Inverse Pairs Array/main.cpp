//
//  main.cpp
//  629. K Inverse Pairs Array
//
//  Created by Giriraj Saigal on 29/10/21.
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

int kInversePairs(int n, int k) {
        if(k == 0)
            return 1;
        
        int mod = 1000000007;
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
        
        for(int i = 1; i <= n; i++) dp[i][0] = 1;
        
        for(long long i = 2; i <= n; i++) {
            for(long long j = 1; j <= k; j++) {
                long long sum = 0;
                for(long long K = 0; K <= min(j,i-1); K++) {
                    sum = (sum + (dp[i-1][j-K])) % mod;
                }
                dp[i][j] = sum;
            }
        }
        
        return dp[n][k];
    }

int main(int argc, const char * argv[]) {
    cout << kInversePairs(3,3) << endl;
    return 0;
}

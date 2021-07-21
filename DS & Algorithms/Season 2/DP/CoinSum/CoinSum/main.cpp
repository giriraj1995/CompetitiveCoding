//
//  main.cpp
//  CoinSum
//
//  Created by Giriraj Saigal on 19/07/21.
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

int mod = 1000007;
vector<vector<long long>> dp;
long long solve(vector<int> &A, int i, int B) {
    if(i == A.size() && B == 0)
        return 1;
    
    if(i == A.size())
        return 0;
    
    if(B == 0)
        return 1;
        
    if(dp[i][B] != -1)
        return dp[i][B];
    
    if(A[i] <= B) {
        long long x = solve(A,i,B-A[i]);
        long long y = solve(A,i+1,B);
        return dp[i][B] = (x+y) % mod;
    }else{
        long long x = solve(A,i+1,B);
        return dp[i][B] = x % mod;
    }
}
int coinchange2(vector<int> A, int B) {
    dp = vector<vector<long long>>(A.size()+1, vector<long long>(B+1, -1));
    long long x = solve(A,0,B);
    return x;
}

int adjacent(vector<vector<int> > A) {
    int n = A[0].size();
    
    if(n == 1)
        return max(A[0][0], A[1][0]);
    
    vector<int> dp(n);
    
    dp[0] = max(A[0][0], A[1][0]);
    dp[1] = max(max(A[0][1], A[1][1]), dp[0]);
    int ans = dp[1];
    for(int i = 2; i < n; i++) {
        dp[i] = max(max(A[0][i], A[1][i]) + dp[i-2], dp[i-1]);
        ans = max(dp[i], ans);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    adjacent(
             {{2, 6, 6, 1, 16, 6, 15},
              {9, 16, 5, 4, 20, 3, 3}}
             );
    cout<< coinchange2({18, 24, 23, 10, 16, 19, 2, 9, 5, 12, 17, 3, 28, 29, 4, 13, 15, 8}, 458) << endl;
    return 0;
}

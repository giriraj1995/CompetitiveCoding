//
//  main.cpp
//  interset cords
//
//  Created by Giriraj Saigal on 27/06/21.
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

int mod = 1e9 + 7;

long long solve(int a, vector<long long> &dp) {
    if(a == 0 || a == 1)
        return 1;
    
    if(dp[a] != -1)
        return dp[a];
        
    long long ans = 0;
    
    for(int i = 0; i < a; i++) {
        long long left = solve(i, dp);
        long long right = solve(a-1-i,dp);
        
        ans = (ans + (left * right) % mod) % mod;
    }
    
    return ans;
}

int chordCnt(int A) {
    vector<long long> dp(A+1, -1);
    return solve(A, dp);
}


int main(int argc, const char * argv[]) {
    cout << chordCnt(10) << endl;
    return 0;
}

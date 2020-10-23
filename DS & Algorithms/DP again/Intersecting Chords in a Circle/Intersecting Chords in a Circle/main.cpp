//
//  main.cpp
//  Intersecting Chords in a Circle
//
//  Created by Giriraj Saigal on 23/10/20.
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

int solve(int A) {
    
    vector<int> dp(A+1);
    
    long long int mod=1000000007;
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=A;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        dp[i]= (dp[i] + (dp[j] * dp[i-j-1])%mod)%mod;
    }
    return dp[A];
}

int chordCnt(int A) {
    return solve(A);
}


int main(int argc, const char * argv[]) {
    chordCnt(6);
    return 0;
}

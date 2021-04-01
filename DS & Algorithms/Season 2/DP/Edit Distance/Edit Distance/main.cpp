//
//  main.cpp
//  Edit Distance
//
//  Created by Giriraj Saigal on 25/03/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//test git
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

int solve(string a, string b, int n, int m, vector<vector<int>> &dp) {
    if(n == 0)
        return m;
    if(m == 0)
        return n;
        
    if(dp[n][m] != -1)
        return dp[n][m];
        
    if(a[n-1] == b[m-1])
        return dp[n][m] = solve(a,b,n-1,m-1,dp);
    
    //delete
    int del = 1 + solve(a,b,n-1,m,dp);
    
    //replace
    int rep = 1 + solve(a,b,n-1,m-1,dp);
    
    //insert
    int ins = 1 + solve(a,b,n,m-1,dp);
    
    return dp[n][m] = min(del,min(rep,ins));
}

int minDistance(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return solve(a,b,n,m,dp);
}


int main(int argc, const char * argv[]) {
    cout<<minDistance("bbbabbaabbbbaabbbabb","ab");
    return 0;
}

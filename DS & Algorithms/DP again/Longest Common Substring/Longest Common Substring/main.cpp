//
//  main.cpp
//  Longest Common Substring
//
//  Created by Giriraj Saigal on 09/10/20.
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

int dp[1005][1005];

int solve(string a, string b, int n, int m){
    
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
    if(n == 0 || m == 0)
        return 0;
    
    if(a[n-1] == b[m-1]){
        dp[n][m] = 1 + solve(a, b, n-1, m-1);
    }else{
        dp[n][m] = max(solve(a, b, n-1, m), solve(a,b, n, m-1));
    }
    
    return dp[n][m];
}

int main(int argc, const char * argv[]) {
    string a = "abbcdgf";
    string b = "bbadcgf";
    
    int n = a.size();
    int m = b.size();
    
    memset(dp, -1, sizeof(dp));
    
    cout<<solve(a,b,n,m);
    
    cout<<endl;
    
    for(int i = 1; i < n + 1; i++){
        for (int j = 1; j < m+1; j++) {
            if(dp[i][j] < 0)
                cout<<dp[i][j]<<" ";
            else
                cout<<" "<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    return 0;
}

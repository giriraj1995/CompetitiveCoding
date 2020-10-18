//
//  main.cpp
//  interleaving A and B
//
//  Created by Giriraj Saigal on 18/10/20.
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

bool solve(string t, string a, string b, int n, int p, int q){
    
    if(n == 0)
        return true;
    
    if(p == 0 && q == 0)
        return false;
    
    if(p > 0 && q > 0 && t[n-1] == a[p-1] && t[n-1] == b[q-1]){
        return solve(t,a,b, n-1, p-1, q) || solve(t,a,b, n-1, p-1, q);
    }
    if(p > 0 && t[n-1] == a[p-1]){
        return solve(t,a,b, n-1, p-1, q);
    }
    else if(q > 0 && t[n-1] == b[q-1]){
        return solve(t,a,b,n-1,p,q-1);
    }else{
        if(q == 0)
            return solve(t,a,b,n,p-1,q);
        else
            return solve(t,a,b,n,p,q-1);
    }
    
}

int isInterleave(string c, string a, string b) {
    
    int n = a.size();
    int m = b.size();
    int t = c.size();
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(m+1, vector<bool>(t+1, false)));
    
    for(int i = 0; i <= n; i++){
        dp[i][0][0] = false;
    }
    
    for(int j = 0; j <= m; j++){
        dp[0][j][0] = false;
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j][0] = true;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int z = 1; z <= t; z++){
                
                if(c[z-1] == a[i-1] && c[z-1] == b[j-1]){
                    dp[i][j][z] = dp[i-1][j][z-1] | dp[i][j-1][z-1];
                }else if(c[z-1] == a[i-1]){
                    dp[i][j][z] = dp[i-1][j][z-1];
                }else if(c[z-1] == b[j-1]){
                    dp[i][j][z] = dp[i][j-1][z-1];
                }else{
                    dp[i][j][z] = dp[i-1][j][z] | dp[i][j-1][z];
                }
                
            }
        }
    }
    
    return dp[n][m][t];
    
}


int main(int argc, const char * argv[]) {
    string x = "Be";
    string a = "B";
    string b = "e";
    
    cout<<isInterleave(x,a,b);
    return 0;
}

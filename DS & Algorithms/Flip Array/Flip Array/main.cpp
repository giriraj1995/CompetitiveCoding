//
//  main.cpp
//  Flip Array
//
//  Created by Giriraj Saigal on 17/10/20.
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

vector<bool> knapsack(int C, vector<int> A){
    
    int n = A.size();
    vector<bool> x(C+1);
    vector<vector<bool>> t(n+1, x);
    
    for(int i = 0; i <= C; i++){
        t[0][i] = false;
    }
    
    for(int i = 0; i <= n; i++){
        t[i][0] = true;
    }
    

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= C; j++)
            if(A[i-1] <= j){
                t[i][j] = t[i-1][j-A[i-1]] | t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
            
    
    return t[n];
}

int knapsack2(int C, vector<int> A){
    
    int n = A.size();
    vector<bool> x(C+1);
    vector<vector<bool>> t(n+1, x);
    
    for(int i = 0; i <= C; i++){
        t[0][i] = false;
    }
    
    for(int i = 0; i <= n; i++){
        t[i][0] = true;
    }
    

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= C; j++)
            if(A[i-1] <= j){
                t[i][j] = t[i-1][j-A[i-1]] | t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
            
    int i = n;
    int j = C;
    bool d = t[i][j];
    int s = 0;
    
    while(i > 0 && j > 0 && d){
        
        if(j-A[i-1] >= 0){
            if(t[i-1][j-A[i-1]]){
                d = t[i-1][j-A[i-1]];
                j = j - A[i-1];
                i = i-1;
                s++;
            }else{
                d = t[i-1][j];
                i = i-1;
            }
        }else{
            d = t[i-1][j];
            i = i-1;
        }
    }
    
    return min(s, n-s);
}

int solve(const vector<int> &A) {
    
    int sum = 0;

    for(int i : A)
        sum += i;
        
    vector<bool> x = knapsack(sum, A);
    
    int ans = INT_MAX;
    int k;
    for(int i = 0; i < x.size(); i++){
        if(x[i]){
            if(sum-(2*i) < 0)
                break;
                
            k = i;
            ans = min(ans, sum - (2*i));
        }
    }
    return knapsack2(k, A);
}

int solve3(vector<int> x){
    int c = 0;
    
    for(int i : x)
        c+=i;
    
    c>>=1;
    int n = x.size();
    int dp[n+1][c+1];
    
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= c; i++)
        dp[0][i] = INT_MAX;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            
            if(x[i-1] > j || dp[i-1][j-x[i-1]] == INT_MAX)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1 + dp[i-1][j-x[i-1]], dp[i-1][j]);
        }
    }
    
    int k = c;
    
    while(dp[n][k] == INT_MAX){
        k--;
    }
    
    return dp[n][k];
    
    
}

int main(int argc, const char * argv[]) {
    cout<<solve3({5, 4, 6, 8, 7, 2, 3})<<endl;
    return 0;
}

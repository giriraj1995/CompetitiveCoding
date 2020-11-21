//
//  main.cpp
//  Arrange 2
//
//  Created by Giriraj Saigal on 21/11/20.
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

int calculate(string A, int i, int j) {
    
    int black = 0;
    int white = 0;
    
    for(int c = i; c <= j; c++) {
        
        if(A[c] == 'W')
            white++;
        
        if(A[c] == 'B')
            black++;
        
    }
    return white * black;
}

int solve(string A, int i, int j, int cuts) {
    
    int n = j - i + 1;
    if(cuts == 0)
        return calculate(A, i, j);
        
    if(cuts >= n)
        return -1;
      
    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        int left;
        int right;
        for(int m = 0; m <= cuts - 1; m++) {
            left = solve(A, i, k, m);
            right = solve(A, k+1, j, cuts - 1 - m);
            
            if(left == -1 || right == -1)
                continue;
            else{
                ans = min(ans, left + right);
            }
        }
    }
    
    return ans;
}

int dp[1000][1000];
int dfs(int ind, string s, int k)
{
    if(dp[ind][k] != -1)
        return dp[ind][k];
        
    if(ind == s.size() && k == 0)
        return 0;
        
    if(k <= 0)
        return -1;
        
    int w = 0;
    int b = 0;
    
    int ans = INT_MAX;
    for(int i = ind; i < s.size(); i++) {
        
        if(s[i] == 'W')
            w++;
        if(s[i] == 'B')
            b++;
            
        int temp = dfs(i+1, s, k-1);
        
        if(temp != -1 && temp != INT_MAX)
        {
            ans = min(ans, temp + w * b);
        }
    }
    
    return dp[ind][k] = ans;
}
int arrange2(string A, int B)
{
  if(B>A.size())
    return -1;
  memset(dp,-1,sizeof(dp));
  return dfs(0,A,B);
 
}


int arrange(string A, int B) {
    
    int n = A.size();
    
    if(n == B)
        return 0;
        
    if(B > n)
        return -1;
        
    int cuts = B - 1;
    
    return solve(A, 0, n-1, cuts);
}

int main(int argc, const char * argv[]) {
    cout<<arrange("WWWB", 2)<<endl;
    return 0;
}

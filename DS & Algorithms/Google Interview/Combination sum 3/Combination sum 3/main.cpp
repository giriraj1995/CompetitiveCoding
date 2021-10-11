//
//  main.cpp
//  Combination sum 3
//
//  Created by Giriraj Saigal on 11/10/21.
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

void solve(int i, int j, vector<int> vec, vector<int> inp,vector<vector<bool>> &dp, vector<vector<int>> &ans, int k) {
        if(dp[i][j] == false)
            return;
        
        if(i == 0 && j != 0)
            return;
        
        if(j == 0) {
            if(inp.size() == k)
                ans.push_back(inp);
            return;
        }
        
        if(dp[i-1][j] == true) {
            solve(i-1,j,vec,inp,dp,ans,k);
        }
        
        if(j-vec[i-1] >= 0 && dp[i-1][j-vec[i-1]] == true) {
            inp.push_back(vec[i-1]);
            solve(i-1,j-vec[i-1],vec,inp,dp,ans,k);
            inp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec = {1,2,3,4,5,6,7,8,9};
        vector<vector<bool>> dp(vec.size()+1, vector<bool>(k+1, false));
        
        for(int i = 0; i <= 9; i++) {
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= n; j++) {
                if(vec[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-vec[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        vector<vector<int>> ans;
        solve(vec.size(),n,vec,{},dp,ans,k);
        return ans;
    }

int main(int argc, const char * argv[]) {
    combinationSum3(3,7);
    return 0;
}

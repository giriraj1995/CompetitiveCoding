//
//  main.cpp
//  longestincreasingpath
//
//  Created by Giriraj Saigal on 08/09/21.
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

vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &matrix) {

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> Xs = {0,0,1,-1};
        vector<int> Ys = {1,-1,0,0};
        
        int ans = 1;
        for(int k = 0; k < 4; k++) {
            int p = i+Xs[k];
            int q = j+Ys[k];
            
            if(p >= 0 && p < n && q >= 0 && q < m && matrix[p][q] > matrix[i][j]) {
                int t = solve(p,q,matrix);
                if(t+1 > ans){
                    ans = t+1;
                }
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>> matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        int temp = INT_MIN;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x = solve(i,j,matrix);
                if(x > temp){
                    temp = x;
                }
            }
        }
        
        return temp;
    }

int main(int argc, const char * argv[]) {
    longestIncreasingPath({{9,9,4},{6,6,8},{2,1,1}});
    return 0;
}

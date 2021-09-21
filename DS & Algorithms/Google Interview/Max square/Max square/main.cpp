//
//  main.cpp
//  Max square
//
//  Created by Giriraj Saigal on 21/09/21.
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

int maximalSquare(vector<vector<char>> cmatrix) {
        
        int n = cmatrix.size();
        int m = cmatrix[0].size();
        vector<vector<int>> matrix(n, vector<int>(m));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] = cmatrix[i][j]-'0';
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(m));
        dp = matrix;
        vector<vector<int>> B = matrix;
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if(B[i][j] != 0) {
                    B[i][j] += B[i+1][j];
                }
            }
        }
        
        vector<vector<int>> C = matrix;
        for(int j = m-2; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(C[i][j] != 0) {
                    C[i][j] += C[i][j+1];
                }
            }
        }
        
        int ans = 0;
        for(int i = n-2; i >= 0; i--) {
            for(int j = m-2; j >= 0; j--) {
                if(dp[i][j] != 0){
                    int low = min(B[i][j], C[i][j]);
                    if(dp[i+1][j+1] >= low){
                        dp[i][j] = low+1;
                    }else{
                        dp[i][j] = dp[i+1][j+1]+1;
                    }
                    
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return ans*ans;
    }

int main(int argc, const char * argv[]) {
    maximalSquare({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
    return 0;
}

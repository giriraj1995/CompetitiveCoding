//
//  main.cpp
//  Min sum path in matrix
//
//  Created by Giriraj Saigal on 25/06/21.
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

int solve(int i, int j, vector<vector<int> >& A, vector<vector<int> > &dp) {
    if(i == A.size()-1 && j == A[0].size()-1){
        return A[i][j];
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int x = A[i][j];
    
    if(i+1 < A.size() && j+1 < A[0].size()){
        int down = solve(i+1,j,A,dp);
        int right = solve(i,j+1,A,dp);
        return dp[i][j] = x + min(down,right);
    }else if(i+1 < A.size()){
        int down = solve(i+1,j,A,dp);
        return dp[i][j] = x+down;
    }else{
        int right = solve(i,j+1,A,dp);
        return dp[i][j] = x+right;
    }
}

int minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(0,0,A,dp);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  Unique ways in a grid
//
//  Created by Giriraj Saigal on 26/06/21.
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

int solve(int i, int j, vector<vector<int> > &A, vector<vector<int> > &dp) {
    if(i == A.size()-1 && j == A[0].size()-1)
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(A[i][j] == 1)
        return dp[i][j] = 0;
    
    if(i+1 < A.size() && j+1 < A[0].size()){
        return dp[i][j] = solve(i+1,j,A,dp) + solve(i,j+1,A,dp);
    }else if(i+1 < A.size()){
        return dp[i][j] = solve(i+1,j,A,dp);
    }else{
        return dp[i][j] = solve(i,j+1,A,dp);
    }
}

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size()==0)
        return 0;
        
    if(A[0].size() == 0)
        return 0;
        
    if(A[A.size()-1][A[0].size()-1] == 1)
        return 0;
    
    if(A[0][0] == 1)
        return 0;
        
    vector<vector<int> > dp(A.size(), vector<int>(A[0].size(), -1));
    return solve(0,0,A,dp);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

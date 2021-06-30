//
//  main.cpp
//  Min path in Triangle
//
//  Created by Giriraj Saigal on 30/06/21.
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

int solve(int i, int j, vector<vector<int> > &a, vector<vector<int> >&dp) {
    
    if(i == a.size()-1) {
        dp[i][j] = a[i][j];
        return dp[i][j];
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int x = solve(i+1,j,a,dp);
    int y = solve(i+1,j+1,a,dp);
    
    return dp[i][j] = a[i][j] + min(x,y);
}

int minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(0,0,A,dp);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

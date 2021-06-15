//
//  main.cpp
//  Distinct Subsequences
//
//  Created by Giriraj Saigal on 15/06/21.
//

#include <iostream>
<<<<<<< HEAD
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int solve(string A, string B, int n, int m, vector<vector<int>> &dp) {
    if(dp[n][m] != -1)
        return dp[n][m];
    
    if(m > n)
        return 0;
        
    if(n == 0 && m == 0)
        return 1;
    
    if(m == 0)
        return 1;
        
    if(n == 0)
        return 0;
    
    if(A[n-1] == B[m-1]) {
        return dp[n][m] =
        solve(A,B,n-1,m-1,dp)+
        solve(A,B,n-1,m,dp);
    }
    
    return dp[n][m] = solve(A,B,n-1,m,dp);
    
}

int numDistinct(string A, string B) {
    if(B.size() > A.size())
        return 0;
    
    if(A.compare(B) == 0)
        return 1;
    
    if(A.size() == B.size())
        return 0;
        
    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, -1));
    return solve(A, B, A.size(), B.size(), dp);
}

=======
>>>>>>> d0b21371fce724a10709d6b33c936236fa632e39

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

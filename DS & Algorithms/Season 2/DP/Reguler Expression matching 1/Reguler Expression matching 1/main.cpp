//
//  main.cpp
//  Reguler Expression matching 1
//
//  Created by Giriraj Saigal on 17/06/21.
//

#include <iostream>

// int solve(const string A, const string B, int i, int j, vector<vector<int>> &dp) {
//     if(dp[i][j] != -1)
//         return dp[i][j];
    
//     if(i == 0 && j == 0){
//         return dp[i][j] = true;
//     }
    
//     if(j == 0) {
//         return dp[i][j] = false;
//     }
    
//     if(i == 0) {
//         if(B[j-1] == '*'){
//             return dp[i][j] = solve(A,B,i,j-1,dp);
//         }else{
//             return dp[i][j] = false;
//         }
//     }
        
//     if(A[i-1] == B[j-1] || B[j-1] == '?') {
//         return dp[i][j] = solve(A,B,i-1,j-1,dp);
//     }else if(B[j-1] == '*') {
//         return dp[i][j] = solve(A,B,i,j-1,dp) || solve(A,B,i-1,j-1,dp) || solve(A,B,i-1,j,dp);
//     }else{
//         return dp[i][j] = false;
//     }
// }

// int solve1(const string A, const string B) {
    
//     int n = A.size();
//     int m = B.size();
    
//     vector<vector<int>> dp(n+1, vector<int>(m+1 , 0));
//     dp[0][0] = 1;
    
//     for(int j = 1; j <= m; j++)
//     {
//         if(B[j-1] == '*'){
//             dp[0][j] = dp[0][j-1];
//         }else{
//             dp[0][j] = 0;
//         }
//     }
    
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
            
//             if(A[i-1] == B[j-1] || B[j-1] == '?'){
//                 dp[i][j] = dp[i-1][j-1];
//             }else if(B[j-1] == '*'){
//                 dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
//             }else{
//                 dp[i][j] = 0;
//             }
            
//         }
//     }
    
//     return dp[n][m];
// }

// int Solution::isMatch(const string A, const string B) {
//     // int n = A.size();
//     // int m = B.size();
    
//     // vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
    
//     return solve1(A,B);
// }

int isMatch(const string A, const string B) {
    int i = 0, j = 0, starIdx = -1, backIdx = -1;
    while (i < A.length()) {
        if (A[i] == B[j] || B[j] == '?') {
            i++;
            j++;
        }
        else if (B[j] == '*') { // Star encountered - ignore all previous
            starIdx = j++;
            backIdx = i;
        }
        else if (starIdx > -1) { // Backtrack to last star, trying from every next idx
            i = ++backIdx;
            j = starIdx + 1;
        }
        else
            return 0;
    }

    while (j < B.length()) // Must match entire pattern. Only stars remaining will satisfy
        if (B[j++] != '*')
            return 0;

    return 1;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

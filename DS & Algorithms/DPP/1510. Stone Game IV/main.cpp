#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int dp[100005];
    
    bool solve(int n) {
        
        if(dp[n] != -1)
            return dp[n];
        
        // current loses
        if(n == 0)
            return dp[n] = false;
        
        //current wins
        if(sqrt(n) - (double)((int)sqrt(n)) == 0.0)
            return dp[n] = true;

        int c = 0;
        int x = 0;
        
        while((c+1) * (c+1) <= n) {
            c++;
            x = c * c;
            
            if(solve(n-x)) {
                // donot want this condition
                // current loses
                // opponent wins
            } else {
                return dp[n] = true;
                // cuurent wins in atleast one scenario
                // opponent loses
            }

        }
        
        return dp[n] = false;
    }
    
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

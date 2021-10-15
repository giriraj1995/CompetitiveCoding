//
//  main.cpp
//  Decode ways 2
//
//  Created by Giriraj Saigal on 15/10/21.
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
int mod;
int numDecodings(string s) {
        mod = 1000000007;
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[0] = 1;
        
        if(n == 0){
            return 1;
        }
        
        if(s[0] == '*')
            dp[1] = 9;
        else if(s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;
        
        
        for(int i = 2; i <= n; i++) {
            long long ans = 0;
        
            if(s[i-1] == '0') {
                ans = 0;
                if(s[i-2] == '*'){
                    ans = (ans + 2 * dp[i-2]) % mod;
                }
                if(s[i-2] == '0')
                    return 0;
                if(s[i-2] == '1' || s[i-2] == '2')
                    ans = (ans + dp[n-2]) % mod;
            }

            if(s[i-1]-'0' >= 1 && s[i-1]-'0' <= 6) {
                ans = dp[i-1];
                if(s[i-2] == '*') {
                    ans = (ans + 2 * dp[i-2]) % mod;
                }
                if(s[i-2] == '1' || s[i-2] == '2') {
                    ans = (ans + dp[i-2]) % mod;
                }
            }

            if(s[i-1]-'0' >= 7 && s[i-1]-'0' <= 9) {
                ans = dp[i-1];
                if(s[i-2] == '1' || s[i-2] == '*'){
                    ans = (ans + dp[i-2]) % mod;
                }
            }

            if(s[i-1] == '*') {
                ans = (9*dp[i-1]) % mod;
                if(s[n-2] == '*') {
                    ans = (ans + 15 * dp[i-2]) % mod;
                }
                if(s[n-2] == '1'){
                    ans = (ans + 9 * dp[i-2]) % mod;
                }
                if(s[n-2] == '2'){
                    ans = (ans + 6 * dp[i-2]) % mod;
                }
            }
            
            dp[i] = ans;
        }
        
        return dp[n];
    }

int main(int argc, const char * argv[]) {
    cout << numDecodings("*1*") << endl;
    return 0;
}

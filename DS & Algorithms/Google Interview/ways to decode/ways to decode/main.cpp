//
//  main.cpp
//  ways to decode
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

int numDecodings(string A) {
    int n = (int)A.size();
    int mod = 1000000007;
    if(n == 1) {
        if(A[0] == '0')
            return 0;
        return 1;
    }
    
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    if(A[0] == '0')
        return 0;
        
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        int x = (A[i-2] - '0') * 10 + (A[i-1] - '0');
        if(A[i-1] == '0') {
            if(x >= 1 && x <= 26) {
                dp[i] = dp[i-2] % mod;
            }else{
                return 0;
            }
        }else{
            long long sum = 0;
            sum = dp[i-1];
            if(A[i-2] != '0'){
                if(x >= 1 && x <= 26){
                    sum = (sum + dp[i-2]) % mod;
                }
            }
            dp[i] = sum;
        }
    }
    
    return (int)dp[n-1];
}


int main(int argc, const char * argv[]) {
    numDecodings("2611055971756562");
    return 0;
}

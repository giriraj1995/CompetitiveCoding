//
//  main.cpp
//  Tiling with dominoes
//
//  Created by Giriraj Saigal on 31/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int solve(int A) {
    
    if(A == 0)
        return 1;
        
    if(A == 1)
        return 0;
        
    if(A == 2)
        return 3;
    
    vector<long long> dp(A+1, 0);
    int mod = 1000000007;
    
    dp[0] = 1;

    for(int i = 2; i <= A; i++) {
        
        if(i % 2 == 1){
            dp[i] = 0;
        }else{
            
            int x = (3 * dp[i-2]) % mod;
            int y = (2 * dp[i-2]) % mod;
            int z = 0;
            
            if(i - 3 >= 0)
            {
                z = dp[i-3];
            }
            
            dp[i] = (x + z) % mod;
            dp[i-1] = (y + z) % mod;
            
        }
        
    }
    
    return dp[A] ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

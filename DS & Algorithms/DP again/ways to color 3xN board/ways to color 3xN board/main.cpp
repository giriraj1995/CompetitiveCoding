//
//  main.cpp
//  ways to color 3xN board
//
//  Created by Giriraj Saigal on 29/10/20.
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
    
    if (A == 0)
        return -1;
        
    int mod = 1000000007;
        
    vector<long long> dp2(A+1);
    vector<long long> dp3(A+1);
    
    dp2[0] = 0;
    dp3[0] = 0;
    
    dp2[1] = 12;
    dp3[1] = 24;
    
    for(int i = 2; i <= A; i++) {
        
        dp2[i] = (5*dp3[i-1])%mod + (7*dp2[i-1])%mod;
        dp3[i] = (11*dp3[i-1])%mod + (10*dp2[i-1])%mod;
        

    }
    
    return (dp2[A] + dp3[A])%mod;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

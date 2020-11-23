//
//  main.cpp
//  nth catalon number
//
//  Created by Giriraj Saigal on 23/11/20.
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

int numTrees(int A) {
    
    int n = A;
    vector<int> dp(n+1, 0);
    
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        
        double num = 2 * (2 * i - 1);
        double dem = i + 1;
        
        
        dp[i] = (int)((num * dp[i-1]) / dem);
        
    }
    
    return dp[n];
}


int main(int argc, const char * argv[]) {
    numTrees(3);
    return 0;
}

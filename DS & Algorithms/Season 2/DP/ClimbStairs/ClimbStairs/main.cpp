//
//  main.cpp
//  ClimbStairs
//
//  Created by Giriraj Saigal on 11/05/21.
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

    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }


int main(int argc, const char * argv[]) {
    cout<<climbStairs(1)<<endl;
    return 0;
}

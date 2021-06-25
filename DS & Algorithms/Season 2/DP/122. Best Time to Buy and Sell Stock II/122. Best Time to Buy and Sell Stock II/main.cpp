//
//  main.cpp
//  122. Best Time to Buy and Sell Stock II
//
//  Created by Giriraj Saigal on 24/06/21.
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

int solve(vector<int> x, int i, int s, int p, vector<vector<vector<int>>> &dp) {
        if(i == x.size())
            return p;
        
       if(dp[i][s][p] != -1)
           return dp[i][s][p];
        
    //nothin
    int a = solve(x,i+1, s, p, dp);
    int b = 0;
    int c = 0;
    
    if(s == 1) {
        //sell
        b = solve(x, i+1, 0, p+x[i], dp);
        return dp[i][s][p] = max(a,b);
    }else{
        //buy
        c = solve(x,i+1,1, p-x[i], dp);
        return dp[i][s][p] = max(a,c);
    }
    
}
    int maxProfit(vector<int> prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(10,vector<vector<int>>(10, vector<int>(10, -1)));
        return solve(prices, 0, 0, 0, dp);
    }

int main(int argc, const char * argv[]) {
    maxProfit({7,1,5,3,6,4});
    return 0;
}

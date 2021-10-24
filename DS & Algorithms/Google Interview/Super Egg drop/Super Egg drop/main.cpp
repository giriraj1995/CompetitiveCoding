//
//  main.cpp
//  Super Egg drop
//
//  Created by Giriraj Saigal on 24/10/21.
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

vector<vector<int>> dp;
int solve(int k, int n) {
    if(k == 0)
        return 0;
    if(k == 1)
        return n;
    if(n <= 1)
        return n;
    
    if(dp[k][n] != -1)
        return dp[k][n];
    
    int ans = INT_MAX;
    for(int f = 1; f <= n; f++) {
        //breaks
        //down
        int x = 1+solve(k-1, f-1);
        //not breaks
        //go up
        int y = 1+solve(k, n-f);
        ans = min(ans, max(x,y));
    }
    
    return dp[k][n] = ans;
}

int superEggDrop(int k, int n) {
    dp.clear();
    dp = vector<vector<int>>(k+1, vector<int>(n+1, -1));
    return solve(k,n);
}
int main(int argc, const char * argv[]) {
    cout << superEggDrop(4,10000) << endl;
    return 0;
}

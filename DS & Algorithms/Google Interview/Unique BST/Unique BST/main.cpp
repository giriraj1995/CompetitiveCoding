//
//  main.cpp
//  Unique BST
//
//  Created by Giriraj Saigal on 04/09/21.
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

vector<long long> dp;
int cat(long long n) {
    dp = vector<long long>(n+1);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        int x = i-1;
        dp[i] = ( 2*(2*(x)+1)*dp[x] ) / (x+2);
    }
    
    return dp[n];
}

int numTrees(int n) {
    return cat(n);
}

int main(int argc, const char * argv[]) {
    cat(3);
    return 0;
}

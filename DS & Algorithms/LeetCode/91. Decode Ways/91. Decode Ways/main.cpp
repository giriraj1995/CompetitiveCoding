//
//  main.cpp
//  91. Decode Ways
//
//  Created by Giriraj Saigal on 07/06/21.
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
vector<int> dp;
    
int solve(int i, string s) {
    
    int k = i;
    
    if(dp[k] != -1)
        return dp[k];
            
    if(i == s.size()){
        return 1;
    }
    
    int a = 0,b=0;
    
    int x = s[i]-'0';
    
    if(x == 0)
        return 0;
    
    if(x >= 1 && x <= 26) {
        a = solve(i+1,s);
    }
    
    i++;
    
    if(i == s.size())
        return a;
    
    x = x*10 + s[i]-'0';
    
    if(x >= 1 && x <= 26) {
        b = solve(i+1,s);
    }
    
    return dp[k] = a+b;
}

int numDecodings(string s) {
    int ans = 0;
    dp = vector<int>(101, -1);
    ans = solve(0,s);
    return ans;
}

int main(int argc, const char * argv[]) {
    numDecodings("226");
    return 0;
}

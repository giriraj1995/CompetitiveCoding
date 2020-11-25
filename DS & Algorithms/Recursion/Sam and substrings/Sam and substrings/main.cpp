//
//  main.cpp
//  Sam and substrings
//
//  Created by Giriraj Saigal on 24/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <set>
#include <queue>
using namespace std;

int solve(string a, unordered_map<string, int> &dp) {
    
    int n = a.size();
    
    
    if(dp.find(a) != dp.end())
        return 0;
    
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        int x = stoi(a);
        return dp[a] = x;
    }
    
    long ans = 0;
    int actual = stoi(a);

    for(int k = 1; k < n; k++) {
        string left = a.substr(0, k);
        string right = a.substr(k, n - k);
        
        int l = solve(left, dp);
        int r = solve(right, dp);
        ans += ((long)l + (long)r) % 1000000007;
        
    }
    
    dp[a] = actual+ans;
    return actual+ans;
}

//int substrings(string n) {
//    long ans = 0;
//    solve(n, "", ans);
//    return ans;
//}

int main(int argc, const char * argv[]) {
    unordered_map<string, int> mp;
    set<pair<int,int>> s;
    
    cout<<solve("123", mp);
    return 0;
}

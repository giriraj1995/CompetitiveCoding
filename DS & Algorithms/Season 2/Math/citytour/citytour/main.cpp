//
//  main.cpp
//  citytour
//
//  Created by Giriraj Saigal on 10/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
long long int pow_a(int x, int y) {
    int mod = 1000000007;

    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(x == 1)
        return x;
    
    long long temp = pow_a(x,y/2) % mod;
    
    if(y % 2 == 0)
        return (temp * temp) % mod;
    
    return ((x * temp) % mod * temp ) % mod;
}
long long int fact(int x) {
    int mod = 1000000007;
    long long int ans = 1;
    for(int i = 2; i <= x; i++) {
        ans = (ans*i) % 1000000007;
    }
    return ans;
}

int solve(int A, vector<int> B) {
    int mod = 1000000007;
    sort(B.begin(), B.end());
    unordered_set<int> s;
    for(int i : B) {
        s.insert(i-1);
    }
    
    vector<int> g;
    int prev = -1;
    
    for(int i = 0; i < A; i++) {
        if(s.find(i) != s.end()) {
            g.push_back(i - prev - 1);
            prev = i;
        }
    }
    
    g.push_back(A - prev - 1);
        
    int n = A - B.size();
    
    long long int ans = fact(n);

    for(int i = 0; i < g.size(); i++) {
        ans *= (pow_a(fact(g[i]), mod-2)) % mod;
        ans = ans%mod;
    }
    
    long long int z = 1;
    for(int i = 1;i < g.size()-1; i++) {
        if(g[i] < 2)
            continue;
        
        z *= pow_a(2, g[i]-1);
        z = z%mod;
    }
    
    ans = (ans*z)%mod;
    
    return ans % mod;
}


int main(int argc, const char * argv[]) {
    cout<<solve(5, {2,5});
    return 0;
}

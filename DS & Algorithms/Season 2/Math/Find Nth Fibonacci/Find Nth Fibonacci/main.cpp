//
//  main.cpp
//  Find Nth Fibonacci
//
//  Created by Giriraj Saigal on 05/02/21.
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
using namespace std;

void multiply(vector<vector<long>> &F, vector<vector<long>> &M) {
    int mod = 1000000007;
    long x = ((F[0][0] * M[0][0]) % mod + (F[0][1] * M[1][0]) % mod) % mod;
    long y = ((F[0][0] * M[0][1]) % mod + (F[0][1] * M[1][1]) % mod) % mod;
    long p = ((F[1][0] * M[0][0]) % mod + (F[1][1] * M[1][0]) % mod) % mod;
    long q = ((F[1][0] * M[0][1]) % mod + (F[1][1] * M[1][1]) % mod) % mod;
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = p;
    F[1][1] = q;
}

int power(vector<vector<long>> &F, int n) {
    vector<vector<long>> M = {{1,1},{1,0}};
    
    if(n == 0 || n == 1)
        return F[0][0];
    
    power(F,n/2);
    multiply(F,F);
    
    if(n % 2 != 0) {
        multiply(F,M);
    }
    
    return F[0][0];
}

int solve(int A) {
    vector<vector<long>> F = {{1,1},{1,0}};
    return power(F, A-1);
}

int main(int argc, const char * argv[]) {
    cout<<solve(50);
    return 0;
}

//
//  main.cpp
//  Power Function
//
//  Created by Giriraj Saigal on 14/02/21.
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

int solve(int x, int n, int d) {
    
    if(n == 1)
        return x % d;
    if(n == 0)
        return 1;
    
    long long temp = solve(x,n/2,d);
    
    if(n%2 != 0) {
        return (long long)(((long long)(temp * temp) % d) * x) % d;
    }
    
    return (temp * temp) % d;
}

int pow(int x, int n, int d) {
    if(x == 0)
        return 0;
    return solve(x,n,d);
}


int main(int argc, const char * argv[]) {
    pow
    return 0;
}

//
//  main.cpp
//  Max no of max heaps 2
//
//  Created by Giriraj Saigal on 21/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[105];
int log2Base[105];

int getLeft(int n){
    
    int h = log2Base[n];
    int m = 1<<h;
    int a = n - ((1<<h) - 1);
    if(a < m/2){
        return (1<<h) - 1 - (m/2 - a);
    }else
        return (1<<h) - 1;
}

long long int ncr(long long int n, long long int r){
    
    if(r == 0)
        return 1;
    else if(r == 1)
        return n;
    else if(n == r)
        return 1;
    else if(n-1 == r)
        return n;
        
    return ncr(n-1, r-1) + ncr(n-1, r);
    
}

int maxHeaps(int k){
    
    long long int n = (long long int)k;
    
    if(n <= 1)
        return 1;
        
    if(dp[n] != -1)
        return dp[n];
        
    long long int left = getLeft(n);
        
    long long int ans = ((ncr(n-1,left) * maxHeaps(left) % 1000000007) * maxHeaps(n-1-left) % 1000000007);
    
    dp[n] = ans;
    
    return ans;
    
}

int solve1(int n){
    
    if(n <= 1)
        return 1;
        
    memset(dp, -1, sizeof(dp));
    
    int prod = 1;
    int actual = -1;
    
    for(int i = 1; i<= n; i++){
        if(i == prod){
            ++actual;
            prod *= 2;
        }
        log2Base[i] = actual;

    }
    
    return maxHeaps(n);
        
}

int solve(int A) {
    return solve1(A);
}


int main(int argc, const char * argv[]) {
    cout<<solve(20);
    return 0;
}

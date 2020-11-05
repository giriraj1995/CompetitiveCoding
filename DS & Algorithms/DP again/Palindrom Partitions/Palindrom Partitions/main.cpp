//
//  main.cpp
//  Palindrom Partitions
//
//  Created by Giriraj Saigal on 04/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrom(int i, int j, string A) {
    
    while(i < j) {
        
        if(A[i] != A[j])
            return false;
            
        i++;
        j--;
    }
    
    return true;
}

int solve(int i, int j, string A) {
    
    if(i >= j || isPalindrom(i, j, A))
        return 0;
        
    int x = INT_MAX;
    for(int k = i; k < j; k++) {
        x = min(x, 1 + solve(i, k, A) + solve(k+1, j, A));
    }
    
    return x;
}

int minCut(string A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1)
        return 0;
        
    if(isPalindrom(0, n-1, A))
        return 0;
        
    return solve(0, n-1, A);
}

int main(int argc, const char * argv[]) {
    cout<<minCut("giri");
    return 0;
}

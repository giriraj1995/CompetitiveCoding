//
//  main.cpp
//  First missing positive Integer
//
//  Created by Giriraj Saigal on 29/01/21.
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

int firstMissingPositive(vector<int> A) {
    int n = A.size();
    
    for(int i = 0; i < n; i++) {
        if(A[i] < 1 || A[i] > n) {
            A[i] = n+1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(abs(A[i]) <= n) {
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i] > 0)
            return i+1;
    }
    
    return n+1;
}


int main(int argc, const char * argv[]) {
    firstMissingPositive({1});
    return 0;
}

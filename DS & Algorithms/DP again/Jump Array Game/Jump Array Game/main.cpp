//
//  main.cpp
//  Jump Array Game
//
//  Created by Giriraj Saigal on 26/10/20.
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

bool solve(vector<int> &A, int i, int n){
    
    if(i == n){
        return true;
    }
    
    if(n == 0) {
        return false;
    }
    
    if(A[i] == 0){
        return false;
    }
    
    bool x = false;
    
    x = solve(A, i+A[i], n);
    
    return x;
}

int canJump(vector<int> A) {
    
    int n = A.size()-1;
    return solve(A, 0, n) ? 1 : 0;
    
}

int main(int argc, const char * argv[]) {
    canJump({10, 0, 1, 1, 0 });
    return 0;
}

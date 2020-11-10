//
//  main.cpp
//  Princess Dungoan
//
//  Created by Giriraj Saigal on 10/11/20.
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

int solve(int health, int i, int j, vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    if((i == n - 1) && (j == m - 1)) {
        return min(health + A[i][j], health);
    }
    
    if(i + 1 < n) {
        health = min(solve(min(health + A[i][j], health), i+1, j, A), health);
    }
    
    if(j + 1 < m) {
        health = min(solve(min(health + A[i][j], health), i, j+1, A), health);
    }
    
    return health;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  Set Matrix Zeros
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

void setZeroes(vector<vector<int> > &A) {
    bool row = false;
    bool col = false;
    
    int n = A.size();
    int m = A[0].size();
    
    for(int j = 0; j < m; j++) {
        if(A[0][j] == 0){
            row = true;
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i][0] == 0){
            col = true;
            break;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            
            if(A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
            
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    if(row) {
        for(int j = 0; j < m; j++) {
            A[0][j] = 0;
        }
    }
    
    if(col) {
        for(int i = 0; i < n; i++) {
            A[i][0] = 0;
        }
    }
        
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

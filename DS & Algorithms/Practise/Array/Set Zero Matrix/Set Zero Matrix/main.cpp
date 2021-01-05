//
//  main.cpp
//  Set Zero Matrix
//
//  Created by Giriraj Saigal on 05/01/21.
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
    
    bool firstCol = false;
    bool firstRow = false;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == 0) {
            firstCol = true;
            break;
        }
    }
    
    for(int j = 0; j < A[0].size(); j++) {
        if(A[0][j] == 0) {
            firstRow = true;
            break;
        }
    }
    
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == 0) {
                A[0][j] = A[i][0] = 0;
                continue;
            }
        }
    }
    
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    if(firstCol) {
        for(int i = 0; i < A.size(); i++) {
            A[i][0] = 0;
        }
    }
    
    if(firstRow) {
        for(int j = 0; j < A[0].size(); j++) {
            A[0][j] = 0;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

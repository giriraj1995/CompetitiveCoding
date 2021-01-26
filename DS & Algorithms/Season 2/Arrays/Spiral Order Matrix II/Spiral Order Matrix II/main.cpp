//
//  main.cpp
//  Spiral Order Matrix II
//
//  Created by Giriraj Saigal on 26/01/21.
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
vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> mat(A, vector<int>(A, -1));
    
    int i = 0, j = 0;
    int c = 1;
    
    mat[0][0] = c;
    c++;
    
    while(c <= A*A) {
        
        while(j+1 < A && mat[i][j+1] == -1) {
            j++;
            mat[i][j] = c;
            c++;
        }
        
        while(i+1 < A && mat[i+1][j] == -1) {
            i++;
            mat[i][j] = c;
            c++;
        }
        
        while(j-1 >= 0 && mat[i][j-1] == -1) {
            j--;
            mat[i][j] = c;
            c++;
        }
        
        while(i-1 >= 0 && mat[i-1][j] == -1) {
            i--;
            mat[i][j] = c;
            c++;
        }
    }
    
    return mat;
}


int main(int argc, const char * argv[]) {
    generateMatrix(5);
    return 0;
}

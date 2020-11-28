//
//  main.cpp
//  Maximus the matrix
//
//  Created by Giriraj Saigal on 28/11/20.
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

void plus2(vector<vector<int> > &A, int C, int i, int j) {
    
    for(int k = 0; k < C; k++) {
        A[i][j+k] += 2;
    }
    
    
}

int solve(vector<vector<int> > A, int B, int C) {
    
    int rows = A.size();
    // if(rows == 0)
    //     return 0;
    int cols = A[0].size();
    // if(cols == 0)
    //     return 0;
        
    int x = INT_MAX;
    
    int minIndexRow;
    int minIndexCol;
    
    for(int i = 0 ; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(x >= A[i][j]){
                minIndexRow = i;
                minIndexCol = j;
                x = A[i][j];
            }
        }
    }
    
    if(B == 0)
        return x;
        
    
    while(B--) {
        
        x = INT_MAX;
        for(int i = 0 ; i < rows; i++) {
        
            vector<int> arr = A[i];
            int check = INT_MAX;
            
            int k = 0;
            int sum = 0;
            
            while(k < C) {
                sum += arr[k];
                k++;
            }
            
            if(sum < check){
                minIndexRow = i;
                minIndexCol = 0;
                check = sum;
            }
            
            while(k < cols) {
                sum -= arr[k - C];
                sum+= arr[k];
                
                if(sum < check){
                    minIndexRow = i;
                    minIndexCol = k - C + 1;
                    check = sum;
                }
                k++;
            }
        }
           plus2(A, C, minIndexRow, minIndexCol);
    }
    
        for(int i = 0 ; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(x >= A[i][j]){
                    minIndexRow = i;
                    minIndexCol = j;
                    x = A[i][j];
                }
            }
        }
    
    return x;
}


int main(int argc, const char * argv[]) {
    solve({{2,-1,5}, {-2,3,-2}}, 4,2);
    return 0;
}

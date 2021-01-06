//
//  main.cpp
//  Maximum Sum Square SubMatrix
//
//  Created by Giriraj Saigal on 06/01/21.
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

int solve(vector<vector<int> > A, int B) {
    int ans = 0;
    
    vector<vector<int> > mat = A;
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            mat[i][j] += mat[i-1][j];
        }
    }
    
    for(int i = B-1; i < A.size(); i++) {
        
        vector<int> x = mat[i];
        
        if(i - B >= 0){
            for(int j = 0; j < A.size(); j++){
                x[j] -= mat[i-B][j];
            }
        }
        
        int k = 0;
        int CurrSum = 0;
        
        while(k < B){
            CurrSum += x[k];
            k++;
        }
        
        ans = max(ans, CurrSum);
        
        while(k < A.size()) {
            CurrSum -= x[k-B];
            CurrSum += x[k];
            ans = max(ans, CurrSum);
            k++;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 8, 6, 7, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}
    };
    
    solve(mat, 3);
    return 0;
}

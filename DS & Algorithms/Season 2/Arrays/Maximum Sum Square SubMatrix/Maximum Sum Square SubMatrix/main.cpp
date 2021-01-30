//
//  main.cpp
//  Maximum Sum Square SubMatrix
//
//  Created by Giriraj Saigal on 30/01/21.
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
    int n = A.size();
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] += A[i-1][j];
        }
    }
    
    int ans = INT_MIN;
    
    for(int i = B-1; i < n; i++) {
        vector<int> x = A[i];
        
        if(i-B >= 0) {
            for(int j = 0; j < n; j++) {
                x[j] -= A[i-B][j];
            }
        }
        
        int sum = 0;
        int k = 0;
        
        while(k < B) {
            sum += x[k];
            k++;
        }
        
        ans = max(ans, sum);
        
        while(k < n) {
            sum -= x[k-B];
            sum += x[k];
            
            ans = max(ans, sum);
        }
    }
    
    return ans;
    
    
}


int main(int argc, const char * argv[]) {
    return 0;
}

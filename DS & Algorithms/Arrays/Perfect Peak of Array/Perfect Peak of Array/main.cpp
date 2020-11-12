//
//  main.cpp
//  Perfect Peak of Array
//
//  Created by Giriraj Saigal on 12/11/20.
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

int perfectPeak(vector<int> &A) {
    
    vector<int> left(A.size(), 0);
    vector<int> right(A.size(), 0);


    int n = A.size();
    
    if(n == 0)
        return 0;
        
        
    left[0] = 0;
    right[n-1] = n-1;
    
    int maxLeftIndex = 0;
    
    for(int i = 1; i < n; i++) {
        
        if(A[i] > A[maxLeftIndex]) {
            maxLeftIndex = i;
        }
        
        left[i] = maxLeftIndex;
    }
    
    int minRightIndex = n-1;

    
    for(int i = n-2; i >= 0; i--) {
        
        if(A[i] < A[minRightIndex]) {
            minRightIndex = i;
        }
        
        right[i] = minRightIndex;
    }
    
    for(int i = 0; i < n; i++) {
        
        if(left[i] == i && right[i] == i){
            return 1;
        }
        
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    perfectPeak(A);
    return 0;
}

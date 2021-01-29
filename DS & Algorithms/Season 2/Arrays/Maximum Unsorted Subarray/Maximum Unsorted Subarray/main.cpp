//
//  main.cpp
//  Maximum Unsorted Subarray
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

vector<int> subUnsort(vector<int> A) {
    
    int n = A.size();
    
    if(A[n-1] < A[0]) {
        return {0, n-1};
    }
    
    int i = 0;
    int j = 0;
    
    while(j < n) {
        i = j;
        
        if(j+1 < n && A[j] > A[j+1]) {
            int k = j+1;
            int smallest = INT_MAX;
            int largest = INT_MIN;
            
            while(k < n) {
                if(A[k-1] > A[k] || A[k] < largest){
                    j = k;
                    smallest = min(smallest, A[j]);
                }
                largest = max(largest, A[k]);
                k++;
            }
            
            while(i > 0 && smallest < A[i-1]) {
                i--;
            }
            
            return {i, j};
        }
        
        j++;
    }
    
    return {-1};
}


int main(int argc, const char * argv[]) {
    subUnsort({3, 8, 5, 18, 8, 10, 15, 12, 18, 8, 15 });
    return 0;
}

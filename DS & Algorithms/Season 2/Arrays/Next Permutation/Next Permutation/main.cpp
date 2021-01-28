//
//  main.cpp
//  Next Permutation
//
//  Created by Giriraj Saigal on 28/01/21.
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

vector<int> nextPermutation(vector<int> A) {
    int ind = -1;
    int n = A.size();
    
    for(int i = n-2; i >= 0; i--) {
        if(A[i] < A[i+1]) {
            ind = i;
            break;
        }
    }
    
    if(ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }
    
    int i = n-1;
    int low = INT_MAX;
    int ind2 = -1;
    
    while(i > ind) {
        if(A[i] > A[ind] && low > A[i]) {
            low = A[i];
            ind2 = i;
        }
        i--;
    }
    
    int temp = A[ind2];
    A[ind2] = A[ind];
    A[ind] = temp;
    
    sort(A.begin()+ind+1, A.end());
    
    return A;
}


int main(int argc, const char * argv[]) {
    nextPermutation({20, 50, 113});
    return 0;
}

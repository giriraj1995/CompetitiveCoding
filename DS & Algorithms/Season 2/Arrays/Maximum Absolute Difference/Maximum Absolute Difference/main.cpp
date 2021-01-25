//
//  main.cpp
//  Maximum Absolute Difference
//
//  Created by Giriraj Saigal on 25/01/21.
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

int maxArr(vector<int> &A) {
    int n = (int)A.size();
    vector<int> plus(n), mis(n);
    
    for(int i = 0; i < n; i++) {
        plus[i] = A[i] + i;
        mis[i] = A[i] - i;
    }
    
    int maxP = INT_MIN, minP = INT_MAX, maxM = INT_MIN, minM = INT_MAX;

    for(int i = 0; i < n; i++) {
        maxP = max(maxP, plus[i]);
        minP = min(minP, plus[i]);
        maxM = max(maxM, mis[i]);
        minM = min(minM, mis[i]);
    }
    
    return max(maxP - minP, maxM - minM);
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

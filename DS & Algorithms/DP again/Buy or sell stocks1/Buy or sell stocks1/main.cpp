//
//  main.cpp
//  Buy or sell stocks1
//
//  Created by Giriraj Saigal on 11/11/20.
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

int maxProfit(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1)
        return 0;
        
    int t = A[0];
    
    int maxProfit = 0;
    for(int i = 1; i < A.size(); i++) {
        t = min(t, A[i]);
        maxProfit = max(maxProfit, A[i] - t);
    }
    
    return maxProfit;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

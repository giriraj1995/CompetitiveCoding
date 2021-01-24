//
//  main.cpp
//  Max subArray - Kanedes Algo
//
//  Created by Giriraj Saigal on 24/01/21.
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

int maxSubArray(const vector<int> &A) {
    int ans = A[0];
    int sum = A[0];
    
    for(int i = 1; i < A.size(); i++) {
        sum = max(sum + A[i], A[i]);
        ans = max(sum, ans);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {

    return 0;
}

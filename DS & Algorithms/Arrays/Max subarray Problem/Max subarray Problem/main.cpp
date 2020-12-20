//
//  main.cpp
//  Max subarray Problem
//
//  Created by Giriraj Saigal on 20/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int maxSum(vector<int> arr){
    
    int maxSumSoFar = 0;
    int ans = 0;
    
    for(int i : arr) {
        maxSumSoFar = max(i, maxSumSoFar+i);
        ans = max(ans, maxSumSoFar);
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    cout<<maxSum({1,3,-99,10,-5,10,-99})<<endl;
    return 0;
}

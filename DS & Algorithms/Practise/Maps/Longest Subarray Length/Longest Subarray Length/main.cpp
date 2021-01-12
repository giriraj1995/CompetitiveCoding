//
//  main.cpp
//  Longest Subarray Length
//
//  Created by Giriraj Saigal on 11/01/21.
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

int solve(vector<int> A) {
    
    int j = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 0)
            A[i] = -1;
    }
    
    int curSum = 0;
    int ans = 0;
    
    mp[0] = -1;
    int maxLength = 0;
    while(j < A.size()) {
        curSum += A[j];
        
        if(mp.find(curSum - 1) != mp.end()) {
            maxLength = max(maxLength, j - mp[curSum - 1]);
        }
        
        if(mp.find(curSum) == mp.end()) {
            mp[curSum] = j;
        }
        
        j++;
    }
    
    return maxLength;
}

int main(int argc, const char * argv[]) {
    solve({0, 1, 1, 0, 0, 1});
    return 0;
}

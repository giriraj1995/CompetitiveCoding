//
//  main.cpp
//  Subarrays with equal length
//
//  Created by Giriraj Saigal on 12/01/21.
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

int solve(vector<int> A, int B, int C) {
    
    unordered_map<int, int> mp;
    mp[0]=1;
    int diff = 0;
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++) {
        
        if(A[i] == B) {
            diff++;
        }else if(A[i] == C) {
            diff--;
        }
        
        ans += mp[diff];
        mp[diff]++;
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    solve({1,2,1}, 1, 2);
    return 0;
}

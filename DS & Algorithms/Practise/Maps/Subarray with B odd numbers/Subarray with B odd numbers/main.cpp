//
//  main.cpp
//  Subarray with B odd numbers
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

int solve(vector<int> &A, int B) {
    
    unordered_map<int, int> mp;
    mp[0] = 1;
    int odd = 0;
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        
        if(A[i] & 1) {
            odd++;
        }
        
        if(mp.find(odd-B) != mp.end()) {
            ans += mp[odd-B];
        }
        
        mp[odd]++;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

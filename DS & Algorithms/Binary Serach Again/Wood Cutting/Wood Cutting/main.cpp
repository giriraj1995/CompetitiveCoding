//
//  main.cpp
//  Wood Cutting
//
//  Created by Giriraj Saigal on 28/11/20.
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

bool check(int req, vector<int> t, int mid) {
    
    int ans = 0;
    for(int i = 0; i < t.size(); i++) {
        if(t[i] > mid) {
            ans += t[i] - mid;
        }
        
        if(ans >= req)
            return true;
    }
    
    return false;
    
}

int solve(vector<int> A, int B) {
    
    int low = INT_MAX;
    int high = INT_MIN;
    int res = -1;
    
    for(int i = 0; i < A.size(); i++) {
        low = min(low, A[i]);
        high = max(high, A[i]);
    }
    
    while(low <= high) {
        int mid = low + (high - low)/2;
        
        if(check(B, A, mid)) {
            res = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    cout<<solve({4, 42, 40, 26, 46}, 20)<<endl;
    return 0;
}

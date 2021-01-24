//
//  main.cpp
//  Maximum Sum Triplet
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

int solve(vector<int> A) {
    int n = (int)A.size();
    vector<int> maxleft(n, INT_MIN);
    
    for(int i = n-2; i >= 0; i--) {
        maxleft[i] = max(maxleft[i+1], A[i+1]);
    }
    
    set<int> s;
    s.insert(A[0]);
    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        auto lo = s.lower_bound(A[i]);
        
        if(lo == s.begin()){
            s.insert(A[i]);
            continue;
        }
        
        lo--;
        
        int ele = *lo;
        if(maxleft[i] > A[i])
            ans = max(ans, ele + A[i] + maxleft[i]);
        s.insert(A[i]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<solve({1,2,3});
    return 0;
}

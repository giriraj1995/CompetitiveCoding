//
//  main.cpp
//  Max Distance
//
//  Created by Giriraj Saigal on 29/01/21.
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

int maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({A[i],i});
    }
    
    sort(v.begin(), v.end());
    
    int i = 0;
    int j = n-1;
    int ans = 0;
    int ma = INT_MIN;
    
    for(int i = n-1; i >= 0; i--) {
        ma = max(ma, v[i].second);
        ans = max(ma - v[i].second, ans);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

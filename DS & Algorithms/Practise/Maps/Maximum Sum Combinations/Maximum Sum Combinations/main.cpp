//
//  main.cpp
//  Maximum Sum Combinations
//
//  Created by Giriraj Saigal on 20/01/21.
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

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<tuple<int,int,int>> h;
    map<int, int> mp;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    for(int i = 0; i < C; i++) {
        h.push({A[i] + B[0], i, 0});
    }
    
    vector<int> ans;
    for(int c = 0; c < C; c++) {
        auto [sum, i, j] = h.top();
        h.pop();
        ans.push_back(sum);
        h.push({A[i] + A[j+1], i, j+1});
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

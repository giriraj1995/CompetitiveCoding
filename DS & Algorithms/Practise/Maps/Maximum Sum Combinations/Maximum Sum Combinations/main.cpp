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
    vector<int>res;
    priority_queue<tuple<int, int, int>>q;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    for(int i=0; i<C; i++) {
        q.push({A[i]+B[0], i, 0});
    }
    while(res.size()<C) {
        auto [sum, i, j] = q.top(); q.pop();
        res.push_back(sum);
        q.push({A[i]+B[j+1], i, j+1});
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

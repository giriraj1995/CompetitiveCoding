//
//  main.cpp
//  Combination Sum 1
//
//  Created by Giriraj Saigal on 22/04/21.
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

void solve(vector<int> c, int t, set<vector<int>> &s, vector<int> inp, int i) {
    if(t == 0) {
        s.insert(inp);
        return;
    }
    
    if(i == c.size()) {
        return;
    }
    
    solve(c, t, s, inp, i+1);
    
    if(c[i] <= t) {
        inp.push_back(c[i]);
        solve(c, t-c[i], s, inp, i);
        inp.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> A, int B) {
    set<vector<int>> s;
    solve(A,B,s,{},0);
    vector<vector<int> > ans;
    for(auto k : s) {
        ans.push_back(k);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    combinationSum({2,3,6,7}, 7);
    return 0;
}

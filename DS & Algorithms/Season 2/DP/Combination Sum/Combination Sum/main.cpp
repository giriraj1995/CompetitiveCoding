//
//  main.cpp
//  Combination Sum
//
//  Created by Giriraj Saigal on 13/04/21.
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

void solve(vector<int> inp, vector<int> x, int i, int t, set<vector<int>> &ans) {
    if(i == x.size()){
        if(t == 0) {
           ans.insert(inp);
        }
        return;
    }
    
    if(t == 0) {
        ans.insert(inp);
        return;
    }
    
    int ele = x[i];
    
    solve(inp, x, i+1, t, ans);

    if(ele <= t) {
        inp.push_back(ele);
        solve(inp, x, i, t-ele, ans);
        inp.pop_back();
    }
    
}
vector<vector<int>> combinationSum(vector<int> c, int t) {
    vector<int> inp;
    set<vector<int>> ans;
    
    solve(inp, c, 0, t, ans);
    
    vector<vector<int>> x;
    
    for(auto k : ans) {
        x.push_back(k);
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    combinationSum({2,3,6,7}, 7);
    return 0;
}

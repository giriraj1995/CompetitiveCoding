//
//  main.cpp
//  Combinations
//
//  Created by Giriraj Saigal on 24/04/21.
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

void solve(vector<int> A, int B, vector<int> inp, int i, vector<vector<int>> &ans) {
    if(inp.size() == B) {
        ans.push_back(inp);
        return;
    }
    
    if(i >= (int)A.size())
        return;
    
    inp.push_back(A[i]);
    solve(A, B, inp, i+1, ans);
    inp.pop_back();
    
    solve(A, B, inp, i+1, ans);
}

vector<vector<int> > combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> k;
    for(int i = 1; i <= A; i++) {
        k.push_back(i);
    }
    
    solve(k,B,{},0,ans);
    return ans;
}


int main(int argc, const char * argv[]) {
    combine(1,1);
    return 0;
}

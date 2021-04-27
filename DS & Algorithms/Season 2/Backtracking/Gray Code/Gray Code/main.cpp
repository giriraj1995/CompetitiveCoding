//
//  main.cpp
//  Gray Code
//
//  Created by Giriraj Saigal on 27/04/21.
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

void solve(int x, int A, set<int> &s, vector<int> &ans) {
    for(int i = 0; i < A; i++) {
        int t = (1 << i) ^ x;
        if(s.find(t) == s.end()) {
            s.insert(t);
            ans.push_back(t);
            solve(t, A, s, ans);
            break;
        }
    }
}
vector<int> grayCode(int A) {
    if(A == 0)
        return {};
        
    if(A == 1)
        return {0,1};
    
    int x = 0;
    set<int> s;
    vector<int> ans;
    s.insert(x);
    ans.push_back(x);
    solve(x,A,s,ans);
    return ans;
}


int main(int argc, const char * argv[]) {
    grayCode(4);
    return 0;
}

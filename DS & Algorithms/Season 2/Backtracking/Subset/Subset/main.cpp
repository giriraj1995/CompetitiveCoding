//
//  main.cpp
//  Subset
//
//  Created by Giriraj Saigal on 20/04/21.
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

void solve(vector<int> inp, int i, vector<int> cd, set<vector<int>> &st){
    if(i == cd.size()){
        st.insert(inp);
        return;
    }
    
    inp.push_back(cd[i]);
    solve(inp, i+1, cd, st);
    inp.pop_back();
    
    solve(inp, i+1, cd, st);
}

vector<vector<int> > subsets(vector<int> A) {
    set<vector<int>> st;
    sort(A.begin(), A.end());
    solve({}, 0, A, st);
    vector<vector<int> > ans;
    
    for(auto y : st) {
        ans.push_back(y);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    subsets({1,2,2});
    return 0;
}

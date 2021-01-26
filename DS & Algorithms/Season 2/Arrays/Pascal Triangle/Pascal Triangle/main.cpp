//
//  main.cpp
//  Pascal Triangle
//
//  Created by Giriraj Saigal on 26/01/21.
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

vector<vector<int> > solve(int A) {
    vector<vector<int>> ans;
    
    for(int i = 0; i < A; i++) {
        vector<int> v(i+1,1);
        
        for(int j = 1; j < i; j++) {
            v[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        
        ans.push_back(v);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve(10);
    return 0;
}

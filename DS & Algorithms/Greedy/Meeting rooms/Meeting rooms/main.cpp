//
//  main.cpp
//  Meeting rooms
//
//  Created by Giriraj Saigal on 25/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
int solve(vector<vector<int> > A) {
    
    vector<pair<int, int>> s;
    
    for(int i = 0; i < A.size(); i++) {
        s.push_back(make_pair(A[i][0], 1));
        s.push_back(make_pair(A[i][1], 0));
    }
    
    sort(s.begin(), s.end());
    
    int ans = 0;
    int cur = 0;
    
    for(pair<int,int> i : s) {
        if(i.second == 1)
            cur++;
        if(i.second == 0)
            cur--;
            
        ans = max(cur, ans);
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    solve({
        {7, 10},
        {4, 19},
        {19, 26},
        {14, 16},
        {13, 18},
        {16, 21}});
        
    return 0;
}

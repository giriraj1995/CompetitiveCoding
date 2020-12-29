//
//  main.cpp
//  Anti diagonals
//
//  Created by Giriraj Saigal on 29/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    
    queue<pair<pair<int, int>, int>> q;
    map<int, vector<int>> mp;
    vector<vector<int>> visited(A.size(), vector<int>(A.size(), 0));
    q.push({{0,0}, 0});
    visited[0][0] = 1;
    while(q.size() > 0) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        
        int x = p.first.first;
        int y = p.first.second;
        
        int level = p.second;
        
        mp[level].push_back(A[x][y]);
        
        if(y + 1 < A[0].size() && visited[x][y+1] == 0) {
            visited[x][y+1] = 1;
            q.push({{x,y+1}, level+1});
        }
        
        if(x + 1 < A.size() && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            q.push({{x+1,y}, level+1});
        }
        
    }
    
    vector<vector<int>> ans;
    
    for(auto j : mp) {
        ans.push_back(j.second);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    diagonal(x);
    return 0;
}

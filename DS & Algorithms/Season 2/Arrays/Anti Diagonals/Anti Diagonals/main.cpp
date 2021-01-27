//
//  main.cpp
//  Anti Diagonals
//
//  Created by Giriraj Saigal on 27/01/21.
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

vector<vector<int> > diagonal(vector<vector<int> > &A) {
    vector<vector<int>> ans;
    map<int,vector<int>> mp;
    int n = A.size();
    
    vector<vector<int> > visited(n, vector<int>(n, 0));
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0}, 0});
    
    visited[0][0] = 1;
    
    while(q.size() > 0) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int level = q.front().second;
        q.pop();
        visited[i][j] = 2;
        
        mp[level].push_back(A[i][j]);
        
        if(j+1 < n && visited[i][j+1] == 0) {
            visited[i][j+1] = 1;
            q.push({{i,j+1},level+1});
        }
        
        if(i+1 < n && visited[i+1][j] == 0) {
            visited[i+1][j] = 1;
            q.push({{i+1,j},level+1});
        }
    }
    
    for(auto k : mp) {
        ans.push_back(k.second);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

//
//  main.cpp
//  bfs shortest path
//
//  Created by Giriraj Saigal on 02/12/20.
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

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> empty;
    vector<vector<int>> ll(n, empty);
    
    for(int i = 0; i < edges.size(); i++) {
        ll[edges[i][0] - 1].push_back(edges[i][1] - 1);
    }
    
    queue<int> q;
    q.push(s-1);
    
    vector<int> x(n, 0);
    vector<int> level(n, INT_MAX);
    x[s-1] = 1;
    level[s-1] = 0;
    
    while(q.size() > 0) {
        int p = q.front();
        q.pop();
        vector<int> y = ll[p];
        
        for(int i = 0; i < y.size(); i++) {
            if(x[y[i]] == 0) {
                x[y[i]] = 1;
                q.push(y[i]);
                
                if(level[y[i]] > level[p] + 6){
                    level[y[i]] = level[p] + 6;
                }
            }
        }
    }
    
    for(int i = 0; i < level.size(); i++) {
        if(level[i] == INT_MAX)
            level[i] = -1;
    }
        
    level.erase(level.begin() + s-1);
    
    return level;
}

int main(int argc, const char * argv[]) {
    bfs(4,2,{{1,2},{1,3}},1);
    return 0;
}

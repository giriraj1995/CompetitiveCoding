//
//  main.cpp
//  prims algo 3
//
//  Created by Giriraj Saigal on 10/12/20.
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

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    
    vector<int> key(n);
    vector<int> weight(n, INT_MAX);
    vector<bool> visited(n, false);
    weight[start - 1] = 0;
    key[start - 1] = -1;
    
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < (int)edges.size(); i++) {
        adj[edges[i][0]-1].push_back({edges[i][1]-1, edges[i][2]});
        adj[edges[i][1]-1].push_back({edges[i][0]-1, edges[i][2]});
    }
    
    for(int count = 0; count < n-1; count++) {
        
        int u;
        int m = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(weight[i] < m && visited[i] == false)
            {
                u = i;
                m = weight[i];
            }
        }
        
        
        visited[u] = true;
        vector<pair<int, int>> vec = adj[u];
        
        for(int i = 0; i < vec.size(); i++) {
            int v = vec[i].first;
            int w = vec[i].second;
            
            if(weight[v] > w && visited[v] == false) {
                key[v] = u;
                weight[v] = w;
            }
       }
    }
    
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        if(start - 1 == i)
            continue;
        sum += weight[i];
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

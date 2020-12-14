//
//  main.cpp
//  Dijkstra Algo Like Prim
//
//  Created by Giriraj Saigal on 14/12/20.
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

void dijkstra(int n, vector<int> &visited, vector<vector<int>> edges) {
    
    vector<vector<pair<int, int>>> adj(n);
    
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    
    for(int c = 0; c <= n; c++) {
        
        int u;
        int m = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(dis[i] < m && visited[i] == 0){
                m = dis[i];
                u = i;
            }
        }
        
        visited[u] = 1;
        
        for(auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            
            if(dis[u] + w < dis[v] && visited[v] == 0) {
                dis[v] = dis[u] + w;
            }
        }
    }
    
    cout<<"done";
    return;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,8},
        {1,2,11},
        {1,4,2},
        {1,3,8},
        {3,4,4},
        {2,4,1}
    };
    
    vector<int> visited(5, 0);
    dijkstra(5, visited, edges);
    return 0;
}


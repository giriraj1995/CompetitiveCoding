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
    
    vector<int> parent(n);
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    parent[0] = -1;
    
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
                parent[v] = u;
            }
        }
    }
    
    cout<<"WEIGHT\t"<<"\tPATH\t"<<endl;
    for(int i = 1; i < n; i++) {
        int x = i;
        cout<<dis[i]<<"\t\t\t";

        cout<<i <<" <- ";
        while(parent[x] != -1) {
            if(parent[parent[x]] == -1)
                cout<<parent[x];
            else
                cout<<parent[x]<<" <- ";
            x = parent[x];
        }
        
        cout<<endl;
    }
    return;
}
int main(int argc, const char * argv[]) {
    int n = 9;
    vector<vector<int>> edges = {
        {0,1,4},
        {0,4,8},
        {1,2,8},
        {1,4,11},
        {2,3,7},
        {2,6,4},
        {2,8,2},
        {3,7,9},
        {3,6,14},
        {4,8,7},
        {4,5,1},
        {5,8,6},
        {5,6,2},
        {6,7,10}
    };
    vector<int> visited(n, 0);
    dijkstra(n, visited, edges);
    return 0;
}


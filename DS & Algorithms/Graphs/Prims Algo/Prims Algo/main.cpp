//
//  main.cpp
//  Prims Algo
//
//  Created by Giriraj Saigal on 06/12/20.
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

void prim(int s, int n, vector<vector<int>> edges) {
    
    vector<vector<pair<int, int>>> ll(n+1);
    
    for(int i =0 ; i < edges.size(); i++) {
        ll[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        ll[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<bool> visited(n+1, false);
    vector<int> weight(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    
    weight[s] = 0;
    parent[s] = -1;
    
    for(int c = 0; c < n-1; c++) {
        
        int u;
        
        int m = INT_MAX;
        
        for(int i = 1; i <= n; i++) {
            if(weight[i] < m && visited[i] == false){
                m = weight[i];
                u = i;
            }
        }
        
        visited[u] = true;
        
        vector<pair<int,int>> x = ll[u];
        
        for(int i = 0 ; i < x.size(); i++) {
            int v = x[i].first;
            int w = x[i].second;
            
            if(visited[v] == false && w < weight[v]){
                parent[v] = u;
                weight[v] = w;
            }
        }
    }
    
    cout<<"source - destination -> weigth"<<endl;
    for(int i = 1; i <= n; i++) {
        if(i == s)
            continue;
        
        cout<<i<<" - "<<parent[i]<<" -> "<<weight[i]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    int n = 6;
    vector<vector<int>> edges = {
        {1,2,10},
        {1,2,5},
        {1,3,3},
        {1,6,7},
        {2,3,6},
        {2,4,2},
        {2,5,4},
        {3,6,1},
        {3,4,3},
        {4,5,2},
        {5,5,1}
    };
    
    prim(1, n, edges);
    return 0;
}

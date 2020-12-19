//
//  main.cpp
//  Useful Extra Edges
//
//  Created by Giriraj Saigal on 19/12/20.
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

vector<int> dijkstra(int s, int n, vector<vector<pair<int,int>>> adj) {
    
    vector<bool> visited(n, false);
    vector<int> dis(n, INT_MAX);
    dis[s] = 0;
    
    for(int c = 1; c < n; c++) {
        
        int u;
        int m = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == false && dis[i] < m) {
                m = dis[i];
                u = i;
            }
        }
        
        visited[u] = true;
        
        for(auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            
            if(visited[v] == false && dis[u] + w < dis[v]) {
                dis[v] = w + dis[u];
            }
        }
    }
    
    return dis;
}

int solve(int A, vector<vector<int> > B,
int C, int D, vector<vector<int> > E) {
    
    vector<vector<pair<int,int>>> adj(A);
    
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]-1].push_back({B[i][1]-1, B[i][2]});
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < E.size(); i++) {
        
        if(E[i][0]-1 >= A || E[i][1]-1 >= A)
            continue;
        
        vector<vector<pair<int,int>>> madj = adj;
        madj[E[i][0]-1].push_back({E[i][1]-1, E[i][2]});
        madj[E[i][1]-1].push_back({E[i][0]-1, E[i][2]});

        vector<int> dis = dijkstra(C-1, A, madj);
        ans = min(ans, dis[D-1]);
    }
    
    return ans == INT_MAX ? -1 : ans;
}

int main(int argc, const char * argv[]) {
    solve(6, {{1,5,5},{2,3,2}}, 2, 4, {{6,7,4}});
    return 0;
}

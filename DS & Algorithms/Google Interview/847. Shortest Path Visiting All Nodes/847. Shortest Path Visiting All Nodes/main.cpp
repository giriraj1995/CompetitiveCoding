//
//  main.cpp
//  847. Shortest Path Visiting All Nodes
//
//  Created by Giriraj Saigal on 17/10/21.
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

long long solve(int u, int mask, vector<vector<long long>> &grid, vector<int> &adj) {
        
    int n = adj.size();
    if(mask == (1<<n)-1)
        return 0;
    
    int next = 0;
    
    //mask 0101
    //next 1110
    //     1010 | 1110
    
    for(int i = 0; i < n; i++) {
        if(((1<<i) & mask)) {
            next = next | adj[i];
        }
    }
    
    // mask ^ next (1111 & 1110)
    next = next & (next^mask);
    
    long long temp = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if((1<<i) & next){
            mask = (1<<i) ^ mask;
            temp = min(temp, grid[u][i] + solve(i,mask,grid, adj));
            mask = (1<<i) ^ mask;
        }
    }
    
    return temp;
}
    
    int shortestPathLength(vector<vector<int>> graph) {
        int n = graph.size();
        vector<vector<long long>> grid(n, vector<long long>(n, INT_MAX));
        
        for(int u = 0; u < graph.size(); u++) {
            for(int v : graph[u]) {
                grid[u][v] = 1;
                grid[u][u] = 0;
                grid[v][v] = 0;
            }
        }
        
        vector<int> adj(n);
        
        for(int i = 0; i < n; i++) {
            int next = 0;
            for(int v : graph[i]) {
                next = (1<<v) | next;
            }
            adj[i] = next;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][k] == INT_MAX || grid[k][j] == INT_MAX)
                        continue;
                    grid[i][j] = min(grid[i][k]+grid[k][j], grid[i][j]);
                }
            }
        }
        
        int ans = 0;
        int low = INT_MAX;
        for(int i = 0; i < n; i++) {
            int mask = 0;
            mask = (1<<i) ^ mask;
            int d = solve(i, mask, grid, adj);
            
            if(d < low) {
                low = d;
                ans = 1;
            }else if(d == low){
                ans++;
            }
        }
        
        return low;
    }

int main(int argc, const char * argv[]) {
    cout << shortestPathLength({{1,2,3},{0},{0},{0}}) << endl;
    return 0;
}

//
//  main.cpp
//  2 teams
//
//  Created by Giriraj Saigal on 15/12/20.
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

bool dfs(int u, vector<vector<int> > &adj,
vector<bool> visited, bool team, set<int> &s1, set<int> &s2) {
    
    visited[u] = true;
    
    if(team) {
        if(s2.find(u) != s2.end()){
            return false;
        }
        
        s1.insert(u);
    }else{
        if(s1.find(u) != s1.end()){
            return false;
        }
        
        s2.insert(u);
    }
    
    bool flag = true;
    
    for(auto v : adj[u]) {
        if(visited[v] == false) {
            flag = dfs(v, adj, visited, !team, s1, s2);
            
            if(flag == false)
                return false;
        }
    }
    
    return flag;
}

int solve(int A, vector<vector<int> > B) {
    
    int n = A;
    vector<vector<int>> adj(n+1);
    set<int> s1, s2;
    
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    vector<bool> visited(n+1, false);
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(visited[i] == false) {
            flag = dfs(i, adj, visited, true, s1, s2);
            if(flag == false)
                return 0;
        }
    }
    
    return 1;
}


int main(int argc, const char * argv[]) {
    solve(11, {{8,7},{8,6},{8,2},{4,9},{11,10},{5,10},{1,10},{3,7},{3,6},{11,7},{5,7},{1,6},{3,2},{8,9},{4,10},{5,6},{4,7},{4,6}});
    return 0;
}

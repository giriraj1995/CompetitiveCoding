//
//  main.cpp
//  Largest Distance between 2 nodes in a TREE
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
#include <set>
using namespace std;

void dfs(int s, vector<int> &visited ,vector<vector<int>> adj, int val, int &ans, int &finalans) {
    
    visited[s] = 1;
    priority_queue<int> q;
    for(auto v : adj[s]) {
        if(visited[v] == 0) {
            int val1 = 0;
            int ans1 = 0;
           dfs(v, visited, adj, val1+1, ans1, finalans);
           q.push(ans1);
        }
    }
    
    if(q.size() == 0) {
        ans = max(ans, val);
        finalans = max(finalans, ans);
    }else if(q.size() == 1) {
        ans = max(ans, q.top() + val);
        finalans = max(finalans, ans);
    }else{
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        
        ans = max(ans, x + val);
        finalans = max(finalans, x + y);
    }
}

int solve(vector<int> &A) {
    
    int n = A.size();
    vector<vector<int>> adj(n);
    int r;
    for(int i = 0; i < A.size(); i++) {
        
        if(A[i] == -1){
            r = i;
            continue;
        }
        
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    
    priority_queue<int> q;
    vector<int> visited(n, 0);
    int finalans = 0;
    int ans = 0;
    
    dfs(r, visited, adj, 0, ans, finalans);

    return finalans;
}


int main(int argc, const char * argv[]) {
    vector<int> ed = {-1, 0, 0, 0, 3};
    solve(ed);
    return 0;
}

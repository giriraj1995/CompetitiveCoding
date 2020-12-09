//
//  main.cpp
//  Detect Cycle in Directed Graph
//
//  Created by Giriraj Saigal on 09/12/20.
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

bool isCyclic_util(int A, vector<bool> visited, vector<vector<int>> adj) {
    
    if(visited[A] == true)
        return true;
        
    visited[A] = true;
    
    vector<int> x = adj[A];
    bool flag = false;
    for(int i = 0; i < x.size(); i++) {
        flag = isCyclic_util(x[i], visited, adj);
        
        if(flag == true)
            return true;
    }
    
    return flag;
}

bool isCyclic(int A, vector<vector<int>> adj) {
    
    bool flag = false;
    vector<bool> visited(A+1, false);
    
    for(int i = 1; i <= A; i++) {
        flag = isCyclic_util(i, visited, adj);
        if(flag == true)
            return true;
    }
    
    return flag;
}

int solve(int A, vector<vector<int> > B) {
    
    vector<vector<int>> adj(A+1);
    
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back(B[i][1]);
    }
    
    return isCyclic(A, adj);
}


int main(int argc, const char * argv[]) {
    cout<<solve(5, {{1,2}, {2,3}, {3,4}, {4,5}});
    return 0;
}

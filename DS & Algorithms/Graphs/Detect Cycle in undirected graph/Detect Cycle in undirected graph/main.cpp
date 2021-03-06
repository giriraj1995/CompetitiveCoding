//
//  main.cpp
//  Detect Cycle in undirected graph
//
//  Created by Giriraj Saigal on 07/12/20.
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

int find(int a, vector<int> &parent) {
    if(parent[a] < 0)
        return a;
    else{
        return parent[a] = find(parent[a], parent);
    }
}

int solve2(int A, vector<vector<int> > B) {
    vector<vector<int>> ll(A+1);
    
    for(int i = 0; i < B.size(); i++) {
        ll[B[i][0]].push_back(B[i][1]);
        ll[B[i][1]].push_back(B[i][0]);
    }
    
    vector<int> parent(A+1,-1);
    
    for(int i = 0; i < B.size(); i++) {
        int x = find(B[i][0], parent);
        int y = find(B[i][1], parent);
        
        if(x!=y) {
            parent[y] = x;
        }else{
            return 1;
        }
    }
    
    return 0;
    
}

int solve3(int x, vector<vector<int>> ll, vector<int> visited) {
    
    vector<int> y = ll[x];
    visited[x] = 1;
    
    for(int i = 0; i < y.size(); i++) {
        if(visited[y[i]] == 0) {
            visited[y[i]] = 1;
            int g = solve3(y[i], ll, visited);
            if(g == 1){
                return g;
            }
        }else if(visited[y[i]] == 1){
            visited[y[i]] = 2;
        }else{
            return 1;
        }
    }
    
    return 0;
}

int solve(int A, vector<vector<int> > B) {
    vector<int> visited(A+1, 0);
    vector<vector<int>> ll(A+1);
    
    for(int i = 0; i < B.size(); i++) {
        ll[B[i][0]].push_back(B[i][1]);
        ll[B[i][1]].push_back(B[i][0]);
    }
    
    
    return solve3(1, ll, visited);
}

int main(int argc, const char * argv[]) {
    solve(5, {
        {1, 2},
        {1, 3},
         {2, 3},
          {1, 4},
           {4, 5}});
    return 0;
}

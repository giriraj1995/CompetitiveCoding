//
//  main.cpp
//  prims algorithm 2
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

int prim(int A, vector<vector<int> > &B) {
    
    vector<vector<pair<int, int>>> ll(A+1);
    
    for(int i = 0; i < B.size(); i++) {
        ll[B[i][0]].push_back({B[i][1], B[i][2]});
        ll[B[i][1]].push_back({B[i][0], B[i][2]});
    }
    
    vector<int> key(A+1);
    vector<int> weight(A+1, INT_MAX);
    vector<bool> visited(A+1, false);

    key[1] = -1;
    weight[1] = 0;
    
    for(int c = 1; c <= A-1; c++) {
        
        int u;
        int m = INT_MAX;
        
        for(int i = 1; i <= A; i++) {
            if(weight[i] < m && visited[i] == false) {
                m = weight[i];
                u = i;
            }
        }
        
        visited[u] = true;
        
        vector<pair<int, int>> x = ll[u];
        
        for(int i = 0; i < x.size(); i++) {
            int v = x[i].first;
            int w = x[i].second;
            if(visited[v] == false && w < weight[v]) {
                weight[v] = w;
                key[v] = u;
            }
        }
    }
    
    int sum = 0;
    for(int i = 2; i <= A; i++) {
        sum += weight[i];
    }
    
    return sum;
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
    
    prim(n, edges);
    return 0;
}

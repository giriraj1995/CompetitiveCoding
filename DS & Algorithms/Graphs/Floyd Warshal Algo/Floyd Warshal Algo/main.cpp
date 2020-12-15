//
//  main.cpp
//  Floyd Warshal Algo
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

//when graph is dense
void floyd_warshal(int n, vector<vector<long>> &adj) {
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int n = 4;
    vector<vector<long>> adj = {
        {0, 9, -4, INT_MAX},
        {6,0,INT_MAX, 2},
        {INT_MAX, 5,0,INT_MAX},
        {INT_MAX, INT_MAX, 1,0}
    };
    
    floyd_warshal(n, adj);
    return 0;
}

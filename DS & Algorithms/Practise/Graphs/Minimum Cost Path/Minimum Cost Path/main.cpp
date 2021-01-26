//
//  main.cpp
//  Minimum Cost Path
//
//  Created by Giriraj Saigal on 25/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

void dijkstra(int i, int j,
vector<vector<int>>& grid,
vector<vector<int>> &cost)
{
    int n = (int)cost.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    cost[i][j] = grid[i][j];
    set<pair<int, pair<int,int>>> mp;
    mp.insert({cost[i][j],{i,j}});
    
    while(mp.size() > 0) {
        int p = mp.begin()->second.first;
        int q = mp.begin()->second.second;
        int d = mp.begin()->first;
        mp.erase(mp.begin());
        visited[p][q] = true;
        
        vector<int> Xs = {1, -1,  0, 0};
        vector<int> Ys = {0,  0, -1, 1};
        
        for(int k = 0; k < 4; k++) {
            int x = p + Xs[k];
            int y = q + Ys[k];
            
            if(x >= 0 && x < n && y >= 0 && y < n){
                if(!visited[x][y]){
                    if(d + grid[x][y] < cost[x][y]) {
                        cost[x][y] = d + grid[x][y];
                        mp.insert({cost[x][y],{x,y}});
                    }
                }
            }
        }
    }
    
}

int minimumCostPath(vector<vector<int>> grid) {
    int n = (int)grid.size();
    vector<vector<int>> cost(n, vector<int>(n, 2147483647));
    dijkstra(0,0,grid,cost);
    return cost[n-1][n-1];
}
int main(int argc, const char * argv[]) {
    minimumCostPath({
        {1,11},
        {1,1}});
    return 0;
}

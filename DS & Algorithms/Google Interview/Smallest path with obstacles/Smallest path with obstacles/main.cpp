//
//  main.cpp
//  Smallest path with obstacles
//
//  Created by Giriraj Saigal on 25/09/21.
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


vector<int> Xs;
vector<int> Ys;

long long solve(int i, int j, vector<vector<int>>& grid, int ob, vector<vector<int>> visited) {
    
    
    if(grid[i][j] == 1){
        ob--;
    }
    
    if(ob == -1)
        return INT_MAX;
    
    if(i == grid.size()-1 && j == grid[0].size()-1){
        return 0;
    }
    visited[i][j] = 1;
    long long temp = INT_MAX;
    for(int k = 0; k < 4; k++) {
        int x = i + Xs[k];
        int y = j + Ys[k];
        
        if(
           x >= 0
           && x < grid.size()
           && y >= 0
           && y < grid[0].size() &&
           visited[x][y] == 0){
            temp = min(temp, solve(x,y,grid,ob,visited));
        }
    }
    
    if(temp == INT_MAX || temp == -1)
        return -1;
    
    return temp+1;
}

int shortestPath(vector<vector<int>> grid, int k) {
    Xs = {0,0,1,-1};
    Ys = {1,-1,0,0};
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    long long ans = solve(0,0,grid,k,visited);
    
    if(ans >= INT_MAX)
        return -1;
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << shortestPath({{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}}, 1) << endl;
    return 0;
}

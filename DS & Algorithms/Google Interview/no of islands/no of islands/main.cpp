//
//  main.cpp
//  no of islands
//
//  Created by Giriraj Saigal on 10/10/21.
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

void dfs(int i, int j, vector<vector<char>>& grid) {
        
        grid[i][j] = '2';
        
        vector<int> x = {0, 0, 1,-1};
        vector<int> y = {1,-1, 0, 0};
        
        for(int t = 0; t < 4; t++) {
            int ii = i + x[t];
            int jj = j + y[t];
            
            if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[0].size() && grid[ii][jj]=='1'){
                dfs(ii,jj,grid);
            }
        }
    }
    int numIslands(vector<vector<char>> grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    numIslands({
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
      });
    return 0;
}

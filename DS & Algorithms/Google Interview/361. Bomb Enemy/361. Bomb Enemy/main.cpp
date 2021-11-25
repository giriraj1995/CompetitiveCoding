//
//  main.cpp
//  361. Bomb Enemy
//
//  Created by Giriraj Saigal on 25/11/21.
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

int maxKilledEnemies(vector<vector<char>> grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 'W')
                    left[i][j] += (j != 0 ? left[i][j-1] : 0) + (grid[i][j] == 'E' ? 1 : 0);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = m-1; j >= 0; j--) {
                if(grid[i][j] != 'W')
                    right[i][j] += (j != m-1 ? right[i][j+1] : 0) + (grid[i][j] == 'E' ? 1 : 0);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 'W')
                    up[i][j] += (i!= 0 ? up[i-1][j] : 0) + (grid[i][j] == 'E' ? 1 : 0);
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 'W')
                    down[i][j] += (i != n-1 ? down[i+1][j] : 0) + (grid[i][j] == 'E' ? 1 : 0);
            }
        }
        
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0')
                    ans = max(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    maxKilledEnemies({
        {'0', 'E', '0', '0'},
        {'E', '0', 'W', 'E'},
        {'0', 'E', '0', '0'}});
    return 0;
}

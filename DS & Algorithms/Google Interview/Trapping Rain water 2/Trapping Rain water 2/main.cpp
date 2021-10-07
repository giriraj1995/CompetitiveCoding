//
//  main.cpp
//  Trapping Rain water 2
//
//  Created by Giriraj Saigal on 07/10/21.
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

#define pip pair<int,pair<int,int>>
class Solution {
public:
    int trapRainWater(vector<vector<int>> grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        if(n == 1 || m == 1)
            return 0;
        
        int minH = 0;
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pip, vector<pip>, greater<pip>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    q.push({grid[i][j], {i,j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int vol = 0;
        
        while(q.size() > 0) {
            int height = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            minH = max(minH, height);
            q.pop();
            
            vector<int> x = {0,0,1,-1};
            vector<int> y = {1,-1,0,0};
            
            for(int i = 0; i < 4; i++) {
                int rr = r + x[i];
                int cc = c + y[i];
                
                if(rr >= 0 && rr < n && cc >= 0 && cc < m && vis[rr][cc] == false) {
                    q.push({grid[rr][cc], {rr,cc}});
                    vis[rr][cc] = true;
                    if(grid[rr][cc] < minH){
                        vol += minH-grid[rr][cc];
                    }
                }
            }
        }
        
        return vol;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.trapRainWater({{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}});
    return 0;
}

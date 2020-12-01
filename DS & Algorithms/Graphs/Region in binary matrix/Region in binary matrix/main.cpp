//
//  main.cpp
//  Region in binary matrix
//
//  Created by Giriraj Saigal on 01/12/20.
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

int solve(vector<vector<int> > A) {
    
    int n = A.size();
    
    if(n == 0)
        return 0;
        
    int m = A[0].size();
    
    if(m == 0)
        return 0;
        
    vector<vector<int>> x(n, vector<int>(m, 0));
    vector<pair<int, int>> y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 0) {
                x[i][j] = -1;
            }else{
                y.push_back({i,j});
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < y.size(); i++) {
        pair<int, int> p = y[i];
        
        int sx = p.first;
        int sy = p.second;
        int r = 0;

        if(x[sx][sy] == 0) {
            queue<pair<int, int>> q;
            q.push({sx,sy});
            x[sx][sy] = 1;
            while(q.size() > 0) {
                pair<int, int > pt = q.front();
                q.pop();
                r++;
                int stx = pt.first;
                int sty = pt.second;
                
                if(stx + 1 < n && x[stx+1][sty] == 0) {
                    x[stx+1][sty] = 1;
                    q.push({stx+1,sty});
                }
                
                if(sty + 1 < m && x[stx][sty+1] == 0) {
                    x[stx][sty+1] = 1;
                    q.push({stx,sty+1});
                }
                
                if(stx + 1 < n && sty + 1 < m && x[stx+1][sty+1] == 0) {
                    x[stx+1][sty+1] = 1;
                    q.push({stx+1,sty+1});
                }
                
                if(stx - 1 >= 0 && x[stx-1][sty] == 0) {
                    x[stx-1][sty] = 1;
                    q.push({stx-1,sty});
                }
                
                if(sty - 1 >= 0 && x[stx][sty-1] == 0) {
                    x[stx][sty-1] = 1;
                    q.push({stx,sty-1});
                }
                
                if(stx - 1 >= 0 && sty - 1 >= 0 && x[stx-1][sty-1] == 0) {
                    x[stx-1][sty-1] = 1;
                    q.push({stx-1,sty-1});
                }
                
                if(stx - 1 >= 0 && sty + 1 < m && x[stx-1][sty+1] == 0) {
                    x[stx-1][sty+1] = 1;
                    q.push({stx-1,sty+1});
                }
                
                if(stx + 1 < n && sty - 1 >= 0 && x[stx+1][sty-1] == 0) {
                    x[stx+1][sty-1] = 1;
                    q.push({stx+1,sty-1});
                }
            }
        }
        
        ans = max(ans, r);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({{0, 0, 1, 1, 0},{1, 0, 1, 1, 0},{0, 1, 0, 0, 0},{0, 0, 0, 0, 1}});
    return 0;
}

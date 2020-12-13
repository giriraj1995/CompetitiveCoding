//
//  main.cpp
//  Capture Regions
//
//  Created by Giriraj Saigal on 13/12/20.
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

void solve(vector<vector<char> > &A) {
    
    int n = A.size();
    if(n == 0)
        return ;
    int m = A[0].size();
    if(m == 0)
        return ;
        
    
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<pair<int, int>> open;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && (A[i][j] == 'O')) {
                open.push_back({i,j});
            }
            
            if(A[i][j] == 'O')
                visited[i][j] = 0;
        }
    }
    
    for(int i = 0; i < open.size(); i++) {
        int a = open[i].first;
        int b = open[i].second;
        
        if(visited[a][b] == 0) {
            queue<pair<int, int>> q;
            visited[a][b] = 1;
            q.push({a,b});
            
            while(q.size() > 0) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                vector<int> Xs = {1, -1, 0 ,0 };
                vector<int> Ys = {0, 0, 1, -1};
                
                for(int g = 0; g < 4; g++) {
                    int newx = x + Xs[g];
                    int newy = y + Ys[g];
                    
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m
                    && visited[newx][newy] == 0) {
                        visited[newx][newy] = 1;
                        q.push({newx, newy});
                    }
                }
            }
        }
    }
    
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0) {
                A[i][j] = 'X';
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    vector<vector<char>> vec = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    
    solve(vec);
    return 0;
}

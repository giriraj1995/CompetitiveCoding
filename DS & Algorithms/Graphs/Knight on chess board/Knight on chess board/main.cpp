//
//  main.cpp
//  Knight on chess board
//
//  Created by Giriraj Saigal on 10/12/20.
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

int solve(int A, int B, int C, int D, int E, int F) {
    
    vector<int> X = {2, 2,-2,-2,-1,1,-1, 1};
    vector<int> Y = {1,-1, 1,-1, 2,2,-2,-2};
    
    queue<pair<int,int>> q;
    vector<vector<int>> level(A, vector<int>(B, INT_MAX));
    vector<vector<bool>> visited(A, vector<bool>(B, false));

    q.push({C-1,D-1});
    level[C-1][D-1] = 0;
    visited[C-1][D-1] = true;
    while(q.size() > 0) {
        
        int x = q.front().first;
        int y = q.front().second;
        int l = level[x][y];
        
        q.pop();
        
        if(x == E-1 && y == F-1) {
            return level[x][y];
        }
        
        int new_x = x;
        int new_y = y;
        
        for(int i = 0; i < 8; i++) {
            
            new_x = x + X[i];
            new_y = y + Y[i];
            
            if(new_x >= 0 && new_x < A && new_y >= 0 && new_y < B
            && !visited[new_x][new_y]){
                q.push({new_x,new_y});
                visited[new_x][new_y] = true;
                if(level[new_x][new_y] > level[x][y] + 1) {
                    level[new_x][new_y] = level[x][y]+1;
                }
            }
        }
    }
    
    return -1;
    
}

int knight(int A, int B, int C, int D, int E, int F) {
    
    return solve(A, B, C, D, E, F);
    
}


int main(int argc, const char * argv[]) {
    knight(8, 8, 1, 1, 8, 8);
    return 0;
}

//
//  main.cpp
//  Min cost Path
//
//  Created by Giriraj Saigal on 05/12/20.
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

int solve(int A, int B, vector<string> C) {
    
    vector<vector<int>> cost(A, vector<int>(B, INT_MAX));
    vector<vector<int>> visited(A, vector<int>(B, 0));

    queue<pair<int, int>> q;
    q.push({0,0});
    
    int ans = INT_MAX;
    cost[0][0] = 0;
    visited[0][0] = 1;
    while(q.size() > 0) {
        int x = q.front().first;
        int y = q.front().second;
        int c = cost[x][y];
        visited[x][y] = 2;
        q.pop();
        
        if(x == A-1 && y == B-1) {
            ans = min(ans,cost[x][y]);
            continue;
        }
        
        
        if(x+1 < A) {
//            if(visited[x+1][y] == 0) {
//                visited[x+1][y] = 1;
//                q.push({x+1,y});
//            }
            
            if(C[x][y] == 'D') {
                if(c < cost[x+1][y]){
                    q.push({x+1,y});
                    cost[x+1][y] = c;
                }
            }else{
                if(c+1 < cost[x+1][y]){
                    q.push({x+1,y});
                    cost[x+1][y] = c+1;
                }
            }
        }
        
        if(y+1 < B) {
//            if(visited[x][y+1] == 0) {
//                visited[x][y+1] = 1;
//                q.push({x,y+1});
//            }
            
            if(C[x][y] == 'R') {
                if(c < cost[x][y+1]){
                    q.push({x,y+1});
                    cost[x][y+1] = c;
                }
            }else{
                if(c+1 < cost[x][y+1]){
                    q.push({x,y+1});
                    cost[x][y+1] = c+1;
                }
            }
        }
        
        if(x-1 >= 0) {
//            if(visited[x-1][y] == 0) {
//                visited[x-1][y] = 1;
//                q.push({x-1,y});
//            }
                
            if(C[x][y] == 'U') {
                if(c < cost[x-1][y]){
                    q.push({x-1,y});
                    cost[x-1][y] = c;
                }
            }else{
                if(c+1 < cost[x-1][y]){
                    q.push({x-1,y});
                    cost[x-1][y] = c+1;
                }
            }
        }
        
        if(y-1 >= 0) {
            
//            if(visited[x][y-1] == 0) {
//                visited[x][y-1] = 1;
//                q.push({x,y-1});
//            }
            
            if(C[x][y] == 'L') {
                if(c < cost[x][y-1]){
                    q.push({x,y-1});
                    cost[x][y-1] = c;
                }
            }else{
                if(c+1 < cost[x][y-1]){
                    q.push({x,y-1});
                    cost[x][y-1] = c+1;
                }
            }
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<solve(5, 5, {"RRRRD", "DLLLL", "RRRRD", "DLLLL", "RRRRR"});
    return 0;
}

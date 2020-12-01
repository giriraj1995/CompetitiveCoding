//
//  main.cpp
//  Valid path
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

string solve(int A, int B, int C, int D, vector<int> E, vector<int> F) {
    
    vector<vector<int>> x(A+1, vector<int>(B+1, 0));
    queue<pair<int,int>> q;
    
    for(int i = 0; i <= A; i++) {
        for(int j = 0; j <= B; j++) {
            for(int p = 0; p < E.size(); p++) {
                if(sqrt(pow(E[p] - i,2) + pow(F[p] - j,2)) <= D){
                    x[i][j] = -1;
                }
            }
        }
    }
    
    if(x[0][0] == -1)
        return "NO";
        
    q.push({0,0});
    x[0][0] = 1;

    while(q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        
        int px = p.first;
        int py = p.second;
        
        if(px == A && py == B){
            return "YES";
        }
        
        if(px + 1 <= A && x[px+1][py] == 0){
            q.push({px+1,py});
            x[px+1][py] = 1;
        }
        
        if(py + 1 <= B && x[px][py+1] == 0){
            q.push({px,py+1});
            x[px][py+1] = 1;
        }
        
        if(px + 1 <= A && py + 1 <= B && x[px+1][py+1] == 0) {
            q.push({px+1,py+1});
            x[px+1][py+1] = 1;
        }
        
        if(px - 1 >= 0 && x[px-1][py] == 0) {
            q.push({px-1,py});
            x[px-1][py] = 1;
        }
        
        if(py - 1 >= 0 && x[px][py-1] == 0) {
            q.push({px,py-1});
            x[px][py-1] = 1;
        }
        
        if(py - 1 >= 0 && px - 1 >= 0 && x[px-1][py-1] == 0) {
            q.push({px-1,py-1});
            x[px-1][py-1] = 1;
        }
        
        if(py - 1 >= 0 && px + 1 <= A && x[px+1][py-1] == 0) {
            q.push({px+1,py-1});
            x[px+1][py-1] = 1;
        }
        
        if(py + 1 <= B && px - 1 >= 0 && x[px-1][py+1] == 0) {
            q.push({px-1,py+1});
            x[px-1][py+1] = 1;
        }
    }
    
    return "NO";
}


int main(int argc, const char * argv[]) {
    solve(2,3,1,1,{2},{3});
    return 0;
}

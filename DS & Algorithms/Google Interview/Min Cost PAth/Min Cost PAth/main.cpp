//
//  main.cpp
//  Min Cost PAth
//
//  Created by Giriraj Saigal on 16/09/21.
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

int solve(int A, int B, vector<string> &C) {
    int n = A;
    int m = B;
    vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
    queue<pair<pair<int,int>, int>> q;
    q.push({{0,0},0});
    visited[0][0] = 0;
    vector<int> Xs = {0,0,-1,1};
    vector<int> Ys = {1,-1,0,0};
    
    int ans = INT_MAX;
    while(q.size() > 0) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int level = q.front().second;
        q.pop();
        
        if(x == A-1 && y == B-1){
            ans = min(ans, visited[x][y]);
            continue;
        }
        
        if(level >= ans)
            continue;
            
        for(int i = 0 ; i < 4; i++) {
            
            char dir;
            if(i == 0)
                dir = 'R';
            else if(i == 1)
                dir = 'L';
            else if(i == 2)
                dir = 'U';
            else
                dir = 'D';
            
            int l = x + Xs[i];
            int w = y + Ys[i];
            int cost = C[x][y] == dir ? level : level+1;
            
            if(l >= 0 && l < A && w >= 0 && w < B && cost < visited[l][w]) {
                visited[l][w] = cost;
                q.push({{l,w},cost});
            }
            
        }
    }
    
    return visited[A-1][B-1];
}

#define ppl pair<int,pair<int,int>>
int solve1(int A, int B, vector<string> C) {
    vector<vector<int>> visited(A, vector<int>(B, INT_MAX));
    visited[0][0] = 0;
    priority_queue<ppl, vector<ppl>, greater<ppl>> q;
    q.push({0, {0,0}});
    int tot = A*B;
    vector<int> Xs = {0,0,-1,1};
    vector<int> Ys = {1,-1,0,0};
    int count = 0;
    while(true) {
        count++;
        ppl rec = q.top();
        int ux = rec.second.first;
        int uy = rec.second.second;
        int dis = rec.first;
        q.pop();
        
        if(ux == A-1 && uy == B-1)
            break;
        
        for(int i = 0; i < 4; i++) {
            char dir;
            if(i == 0)
                dir = 'R';
            else if(i == 1)
                dir = 'L';
            else if(i == 2)
                dir = 'U';
            else
                dir = 'D';
            
            int l = ux + Xs[i];
            int w = uy + Ys[i];
            int cost = (C[ux][uy] == dir) ? dis : dis+1;
            if(l >= 0 && l < A && w >= 0 && w < B && visited[l][w] > cost) {
                visited[l][w] = cost;
                q.push({cost,{l,w}});
            }
        }
    }
    
    return visited[A-1][B-1];
}

int main(int argc, const char * argv[]) {
    solve1(5,20, {"RRLRRRLLRLLRLLRLRLRR", "LRLLLRLRLRLLLLRRLRRR", "LRLRLRRLLRRLRRRLRRLR", "RLRRRLLLLLRLRLRRLRLL", "LRLRRRLRRRLRRLLLRRRL"});
    return 0;
}

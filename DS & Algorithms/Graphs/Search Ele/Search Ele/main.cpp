//
//  main.cpp
//  Search Ele
//
//  Created by Giriraj Saigal on 17/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int find_queue(int x, int y, vector<vector<int>> &visited, string B, vector<string> A) {
    
    int n = visited.size();
    int m = visited[0].size();
    int target = B.size();
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {x,y}});
    visited[x][y] = 1;
    
    while(q.size() > 0) {
        
        int a = q.front().second.first;
        int b = q.front().second.second;
        int next_at = q.front().first;
        
        q.pop();
        
        if(next_at == target)
            return 1;
        
        char c = B[next_at];
        
        vector<int> Xs = {1,-1,0,0};
        vector<int> Ys = {0,0,1,-1};
        
        for(int g = 0; g < 4; g++) {
            int newX = a + Xs[g];
            int newY = b + Ys[g];
            
            if(newX >= 0 && newX > n && newY >= 0 && newY < m
            && visited[newX][newY] == 0 && A[newX][newY] == c) {
                q.push({next_at + 1, {newX,newY}});
            }
        }
    }
    
    return 0;
}

int find_dfs(int x, int y, int ele, string B, vector<string> A) {
    
    int n = (int)A.size();
    int m = (int)A[0].size();
    
    if(ele == B.size())
        return 1;
    
    char c = B[ele];
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    int flag = 0;
    for(int g = 0; g < 4; g++) {
        int newX = x + Xs[g];
        int newY = y + Ys[g];
        
        if(newX >= 0 && newX < n && newY >= 0 && newY < m
           && A[newX][newY] == c) {
            
            if(find_dfs(newX, newY, ele+1, B, A))
                return 1;
        }
    }
    
    return 0;
}

int exist(vector<string> &A, string B) {
    
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    if(m == 0)
        return 0;
        
    if(B.size() == 0)
        return 1;
    
    char firstLetter = B[0];
    vector<pair<int,int>> f;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == firstLetter)
                f.push_back({i,j});
        }
    }
    
    for(int s = 0; s < f.size(); s++) {
        
        int x = f[s].first;
        int y = f[s].second;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        if(find_dfs(x,y,1,B,A))
            return 1;
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    vector<string> A = {
        {"ABCE"},
         {"SFCS"},
          {"ADEE"}
    };
    
    
    cout<<exist(A, "ABCB")<<endl;
    return 0;
}

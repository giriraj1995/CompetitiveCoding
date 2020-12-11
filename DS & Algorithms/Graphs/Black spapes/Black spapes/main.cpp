//
//  main.cpp
//  Black spapes
//
//  Created by Giriraj Saigal on 11/12/20.
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

int solve(vector<pair<int, int>> x, vector<vector<int>> visited, int n, int m) {
    
    int ans = 0;
    for(int i = 0; i < x.size(); i++) {
        int a = x[i].first;
        int b = x[i].second;
        
        if(visited[a][b] == 0) {
            ans++;
            queue<pair<int, int>> q;
            visited[a][b] = 1;
            q.push({a,b});
            
            while(q.size() > 0) {
                int c = q.front().first;
                int d = q.front().second;
                
                q.pop();
                
                vector<int> xs = {1,-1,0,0};
                vector<int> ys = {0,0,1,-1};
                
                int newp;
                int newq;
                
                for(int j = 0; j < 4; j++) {
                    newp = c + xs[j];
                    newq = d + ys[j];
                    
                    if(newp >= 0 && newp < n && newq >= 0 && newq < m
                    && visited[newp][newq] == 0) {
                        q.push({newp, newq});
                        visited[newp][newq] = 1;
                    }
                }
                
            }
        }
    }
    
    return ans;
}

int black(vector<string> A) {
    
    int n = A.size();
    
    if(n == 0)
        return 0;
        
    int m = A[0].size();
    
    if(m == 0)
        return 0;
        
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<pair<int,int>> x;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 'X'){
                x.push_back({i,j});
                visited[i][j] = 0;
            }
        }
    }
    
    if(x.size() == 0)
        return 0;
        
    int ans = 0;
    
    return solve(x, visited, n, m);
    
}


int main(int argc, const char * argv[]) {
    black({"OOOXOOO", "OOXXOXO","OXOOOXO"});
    return 0;
}

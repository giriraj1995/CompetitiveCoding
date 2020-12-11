//
//  main.cpp
//  water flow
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

void first(int x, int y, vector<vector<int> > &A, vector<vector<int> > &visited) {
    
    if(visited[x][y] == 1) {
        return;
    }
    
    int n = A.size();
    int m = A[0].size();
    
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    
    while(q.size() > 0) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        vector<int> xs = {1,-1,0,0};
        vector<int> ys = {0,0,1,-1};
        
        for(int i = 0; i < 4; i++) {
            int nx = a + xs[i];
            int ny = b + ys[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
            A[nx][ny] >= A[a][b] && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    
}

int second(int x, int y, vector<vector<int> > &A, vector<vector<int> > &visited) {
    
    int ans = 0;
    
    int n = A.size();
    int m = A[0].size();
        
    if(visited[x][y] == 2) {
        return 0;
    }
    
    if(visited[x][y] == 1) {
        visited[x][y] = 2;
        ans++;
    }
    
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = 2;
    
    while(q.size() > 0) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        vector<int> xs = {1,-1,0,0};
        vector<int> ys = {0,0,1,-1};
        
        for(int i = 0; i < 4; i++) {
            int nx = a + xs[i];
            int ny = b + ys[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(A[nx][ny] >= A[a][b] && visited[nx][ny] == 0){
                    visited[nx][ny] = 2;
                    q.push({nx,ny});
                }
                
                else if(A[nx][ny] >= A[a][b] && visited[nx][ny] == 1){
                    ans++;
                    visited[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    return ans;
    
}

int solve(vector<vector<int> > A) {
    
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m , 0));
    
    int i = 0;
    int j = 0;
    
    for(j = 0; j < m; j++) {
        first(i,j,A,visited);
    }
    
    i = 0;
    j = 0;
    
    for(i = 0; i < n; i++) {
        first(i,j,A,visited);
    }
    
    int sum = 0;
    j = 0;
    i = n-1;
    
    for(j = 0; j < m; j++) {
        sum += second(i,j,A,visited);
    }
    
    i = 0;
    j = m-1;
    
    for(i = 0; i < n; i++) {
        sum += second(i,j,A,visited);
    }
    
    return sum;
}


int main(int argc, const char * argv[]) {
    cout<<solve({{1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
         {2, 4, 5, 3, 1},
          {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}})<<endl;
    return 0;
}

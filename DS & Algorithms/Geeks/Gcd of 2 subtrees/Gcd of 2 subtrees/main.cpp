//
//  main.cpp
//  Gcd of 2 subtrees
//
//  Created by Giriraj Saigal on 04/10/20.
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

int N[5][5];

bool checkSame(int n, vector<vector<int>> N, int s, int c){
    
    queue<int> q;
    q.push(s);
    int visited[n];
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;
    
    while(!q.empty()){
        
        int i = q.front();
        q.pop();
        
        for(int j = 0; j < n; j++){
            if(N[i][j] && visited[j] == 0){
                q.push(j);
                visited[j] = 1;
                if(j == c){
                    return true;
                }
            }
        }
    }
    
    return false;
    
}

long long solve(long x, long y){
    
    if(y == 0)
        return x;
        
   return solve(y, x%y);
}

long long gcd(int n, vector<vector<int>> N, int i, vector<int> t){
    
   queue<int> q;
   long long ans = 0;
    q.push(i);
    int visited[n];
    memset(visited, 0, sizeof(visited));
    visited[i] = 1;
    
    while(!q.empty()){
        
        int s = q.front();
        q.pop();
        
        ans = solve(ans, t[s]);
        
        for(int j = 0; j < n; j++){
            if(N[s][j] && visited[j] == 0){
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    return ans;
}

int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
{
    
    vector<int> k(n,0);
    vector<vector<int>> N(n,k);
    
    for(int i = 0; i < edges.size(); i++)
        N[edges[i][0]][edges[i][1]] = 1;
        
    if(checkSame(n, N, x, y) | checkSame(n, N, y, x)){
        return -1;
    }
    
    long long ans1 = gcd(n, N, x, val);
    long long ans2 = gcd(n, N, y, val);
    
    return (int)solve(ans1, ans2);
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {2, 3}};
    vector<int> val = {30, 24, 10, 20, 24};
    cout<<gcdTree(5,edges, val, 2,1)<<endl;
    return 0;
}

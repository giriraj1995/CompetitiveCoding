//
//  main.cpp
//  Path with good nodes
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

int solve(vector<int> A, vector<vector<int> > B, int C) {
    
    int n = A.size();
    
    vector<vector<int>> ll(n+1);
    
    for(int i = 0 ; i < B.size(); i++) {
        ll[B[i][0]].push_back(B[i][1]);
        ll[B[i][1]].push_back(B[i][0]);
    }
    
    queue<pair<int, int>> q;
    
    vector<int> visited(n+1, 0);
    visited[1] = 1;
    
    q.push({1,0});
    
    int ans = 0;
    while(q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        
        int k = p.first;
        int no = p.second;
        
        vector<int> x = ll[k];
        int flag = 0;
        for(int i = 0; i < x.size(); i++)
        {
            if(visited[x[i]] == 0) {
                flag = 1;
                visited[x[i]] = 1;
                if(A[k-1] == 0)
                    q.push({x[i],no});
                else
                    q.push({x[i],no+1});
            }
        }
        
        if(flag == 0)
        {
            if(A[k-1] == 0){
                if(no <= C){
                    ans++;
                }
            }
            else
            {
                if(no+1 <= C){
                    ans++;
                }
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    vector<int> x = {1, 1, 1, 0, 1, 0, 1, 0};
    vector<vector<int>> y = {{8,2},{6,3},{5,2},{3,1},{4,2},{7,2},{2,1}};
    int z = 2;
    
    solve(x,y,z);
        
    return 0;
    
}

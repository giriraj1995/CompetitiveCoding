//
//  main.cpp
//  Path Exist ?
//
//  Created by Giriraj Saigal on 04/12/20.
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

int solve(int A, vector<vector<int> > B) {
    
    vector<vector<int>> ll(A+1);
    
    for(int i = 0; i < B.size(); i++) {
        ll[B[i][0]].push_back(B[i][1]);
    }
    
    queue<int> q;
    q.push(1);
    vector<int> visited(A+1, 0);
    visited[1] = 1;
    
    while(q.size() > 0) {
        int curr = q.front();
        q.pop();
        
        if(curr == A)
            return 1;
        
        vector<int> x = ll[curr];
        
        for(int i = 0; i < x.size(); i++)
        {
            if(visited[x[i]] == 0) {
                visited[x[i]] = 1;
                q.push(x[i]);
            }
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    solve(4, {{1,2},{2,3},{4,3}});
    return 0;
}

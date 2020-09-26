//
//  main.cpp
//  BFS
//
//  Created by Giriraj Saigal on 26/09/20.
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

vector <int> bfs(vector<int> g[], int N) {
    
    vector<int> ans;
    vector<int> k(N, 0);
    
    k[0] = 1;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        
        int i = q.front();
        q.pop();
        
        ans.push_back(i);
        
        for(int j = 0; j < N; j++){

            if(g[i][j] != 0 && k[j] == 0){
                q.push(j);
                k[j] = 1;
            }
            
        }
        
    }
    
    return ans;

    // Your code here
}

int main(int argc, const char * argv[]) {
    vector<int> g[3];
    g[0] = {0,1,0};
    g[1] = {1,0,1};
    g[2] = {0,1,0};
    bfs(g,3);
    return 0;
}

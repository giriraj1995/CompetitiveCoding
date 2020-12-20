//
//  main.cpp
//  Journey to the moon
//
//  Created by Giriraj Saigal on 19/12/20.
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

void counts(int s, vector<bool> &visited, vector<vector<int>> adj, int &curr) {
    
    int count = 0;
    // queue<int> q;
    // q.push(s);
    visited[s] = true;
    curr++;
    // while(q.size() > 0) {
    //     int x = q.front();
    //     q.pop();
        
    //     count++;
        
    //     for(auto i : adj[x]){
    //         if(visited[i] == false){
    //             q.push(i);
    //             visited[i] = true;
    //         }
    //     }
    // }
    
    for(int i : adj[s]) {
        if(!visited[i]) {
            counts(i, visited, adj, curr);
        }
    }
}
// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> A) {
    
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < (int)A.size(); i++) {
        adj[A[i][0]].push_back(A[i][1]);
        adj[A[i][1]].push_back(A[i][0]);
    }
    
    vector<bool> visited(n, false);
    vector<int> countries;
    int ans = 0;
    int total = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            int size = 0;
            counts(i, visited, adj, size);
            countries.push_back(size);
            ans += total * size;
            total += size;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

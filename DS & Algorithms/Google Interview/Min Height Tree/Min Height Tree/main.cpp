//
//  main.cpp
//  Min Height Tree
//
//  Created by Giriraj Saigal on 26/09/21.
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


int func(int u, unordered_map<int, vector<int>> &mp) {
    vector<int> visited(mp.size(), INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,u});
    visited[u] = 0;
    
    while(q.size()>0) {
        int d = q.top().first;
        int x = q.top().second;
        q.pop();
        
        for(int v : mp[x]) {
            if(d+1 < visited[v]){
                visited[v] = d+1;
                q.push({d+1,v});
            }
        }
    }
    
    int t = INT_MIN;
    for(int k = 0; k < visited.size(); k++) {
        t = max(t, visited[k]);
    }
    
    return t;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>> edges) {
    
    if(n == 1)
        return {0};
    
    if(n == 2)
        return {0,1};
    
    unordered_map<int, vector<int>> mp;
    
    for(auto k : edges) {
        mp[k[0]].push_back(k[1]);
        mp[k[1]].push_back(k[0]);
    }
    
    map<int,vector<int>> mp2;
    for(int i = 0; i < n; i++) {
        if(mp[i].size() == 1)
            continue;
        mp2[func(i, mp)].push_back(i);
    }
    
    return mp2.begin()->second;
}


int main(int argc, const char * argv[]) {
    vector<int> x=  findMinHeightTrees(6,{{3,0},{3,1},{3,2},{3,4},{5,4}}) ;
    return 0;
}

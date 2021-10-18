//
//  main.cpp
//  882. Reachable Nodes In Subdivided Graph
//
//  Created by Giriraj Saigal on 17/10/21.
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

int reachableNodes(vector<vector<int>> edges, int maxMoves, int n) {
        unordered_map<int, vector<pair<int,int>>> mp;
        
        for(int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back({edges[i][1], edges[i][2]+1});
            mp[edges[i][1]].push_back({edges[i][0], edges[i][2]+1});
        }
        
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});
        dis[0] = 0;
        
        while(q.size() > 0) {
            int d = q.top().first;
            int u = q.top().second;
            q.pop();
            
            for(auto k : mp[u]) {
                if(dis[u] + k.second < dis[k.first]) {
                    dis[k.first] = dis[u] + k.second;
                    q.push({dis[k.first], k.first});
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dis[i] <= maxMoves)
                ans++;
        }
        
        for(int i = 0; i < edges.size(); i++) {
            if(dis[edges[i][0]] > maxMoves && dis[edges[i][1]] > maxMoves) {
                continue;
            }
            
            int x = edges[i][0];
            int y = edges[i][1];
            int z = edges[i][2];
            
            int c1 = max(maxMoves-dis[x],0);
            int c2 = max(maxMoves-dis[y],0);
            
            ans += min(c1+c2,edges[i][2]);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    reachableNodes({{0,1,10},{0,2,1},{1,2,2}},
                   6,
                   3);
    return 0;
}

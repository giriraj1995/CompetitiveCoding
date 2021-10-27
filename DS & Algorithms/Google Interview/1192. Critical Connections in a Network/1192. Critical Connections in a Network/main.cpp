//
//  main.cpp
//  1192. Critical Connections in a Network
//
//  Created by Giriraj Saigal on 27/10/21.
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

vector<vector<int>> ans;
unordered_map<int, vector<int>> mp;
void dfs(int u, int &time, vector<int> &low, vector<int> &dis, int p, vector<int> &parent,vector<bool> &inStack) {
        dis[u] = low[u] = time;
        inStack[u] = true;
        time++;
        
        for(int v : mp[u]) {
            if(dis[v] == -1) {
                parent[v] = u;
                dfs(v, time, low, dis, u, parent, inStack);
                low[u] = min(low[u], low[v]);
                
                if(low[u] < low[v]) {
                    ans.push_back({u,v});
                }
                
            }else{
                if(p != v && inStack[v] == true) {
                    low[u] = min(low[u], dis[v]);
                }
            }
        }
        
    inStack[u] = false;
}
    
vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
        
        vector<int> low(n, -1);
        vector<int> dis(n, -1);
        vector<int> parent(n, -1);
        vector<bool> inStack(n,false);
        int time = 0;
        
        mp.clear();
        for(int i = 0; i < connections.size(); i++) {
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(0, time, low, dis, -1, parent,inStack);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    criticalConnections(2,
                        {{0,1}});
    return 0;
}

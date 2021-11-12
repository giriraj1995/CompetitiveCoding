//
//  main.cpp
//  802. Find Eventual Safe States
//
//  Created by Giriraj Saigal on 13/11/21.
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

bool isSafe(int i, vector<vector<int>>& graph, vector<bool> &visited, set<int> &safenodes, set<int> &cyclenodes) {
                
        if(safenodes.count(i)){
            return true;
        }
    
        if(visited[i] == true || cyclenodes.count(i)){
            cyclenodes.insert(i);
            return false;
        }
        
        visited[i] = true;
        
        bool ans = true;
        
        for(int v : graph[i]) {
            if(!isSafe(v, graph, visited, safenodes, cyclenodes)) {
                ans = false;
            }
        }
        
        if(!ans){
            cyclenodes.insert(i);
            return false;
        }
        
        safenodes.insert(i);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>> graph) {
        set<int> safenodes;
        set<int> cyclenodes;
        
        int n = graph.size();
        
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == false)
                isSafe(i, graph, visited, safenodes, cyclenodes);
        }
        
        vector<int> ans;
        
        for(int i : safenodes)
            ans.push_back(i);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    eventualSafeNodes({{1,2},{2,3},{5},{0},{5},{},{}});
    return 0;
}

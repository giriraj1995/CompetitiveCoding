//
//  main.cpp
//  Course Scheduler IV
//
//  Created by Giriraj Saigal on 12/10/21.
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

set<int> dfs(int u, vector<bool>& vis, unordered_map<int, set<int>> &topo, unordered_map<int, vector<int>> &mp) {
        vis[u] = true;
        set<int> ans;
        
        for(int v : mp[u]) {
            ans.insert(v);
            if(vis[v] == false) {
                set<int> temp = dfs(v, vis, topo, mp);
                for(int x : temp) {
                    ans.insert(x);
                }
            }else{
                set<int> temp = topo[v];
                for(int x : temp) {
                    ans.insert(x);
                }
            }
        }
        
        return topo[u] = ans;
    }
    
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> prerequisites, vector<vector<int>> queries) {
    
    unordered_map<int, vector<int>> mp;
    
    for(int i = 0; i < prerequisites.size(); i++) {
        mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    
    unordered_map<int, set<int>> topo;
    vector<bool> vis(numCourses, false);
    
    for(int i = 0; i < numCourses; i++) {
        if(vis[i] == false) {
            dfs(i,vis,topo,mp);
        }
    }
    vector<bool> ans;
    for(int i = 0; i < queries.size(); i++) {
        if(topo[queries[i][0]].count(queries[i][1]))
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    checkIfPrerequisite(3, {{1,2},{1,0},{2,0}}, {{1,0},{1,2}});
    return 0;
}

//
//  main.cpp
//  851. Loud and Rich
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

void dfs(int u, int val, vector<bool> &visited, unordered_map<int, vector<int>> &mp, vector<int>& quiet, vector<int>& ans) {
        if(mp[u].size() == 0) {
            ans[u] = min(val, quiet[u]);
            return;
        }
        
        visited[u] = true;
        
        val = min(val, quiet[u]);
        
        for(int v : mp[u]) {
            dfs(v, val, visited, mp, quiet, ans);
        }
        
        ans[u] = val;
    }

void sort(int u, vector<bool> &visited, unordered_map<int, vector<int>> &mp, stack<int> &s) {
    if(visited[u])
        return;
    
    visited[u] = true;
    
    for(int v : mp[u]) {
        sort(v, visited, mp, s);
    }
    
    s.push(u);
}
    
    vector<int> loudAndRich(vector<vector<int>> richer, vector<int> quiet) {
        int n = quiet.size();
        vector<bool> visited(n, false);
        
        unordered_map<int, vector<int>> mp;
        vector<int> inorder(n, 0);
        
        for(int i = 0; i < richer.size(); i++) {
            inorder[richer[i][1]]++;
            mp[richer[i][0]].push_back(richer[i][1]);
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(inorder[i] == 0)
                q.push(i);
        }
        
        vector<int> ans(n, INT_MAX);
        
        for(int i = 0; i < n; i++) {
            ans[i] = i;
        }
        
        while(q.size() > 0) {
            int x = (int)q.size();
            for(int i = 0; i < x; i++) {
                int u = (int)q.front();
                q.pop();
                
                for(int v : mp[u]) {
                    inorder[v]--;
                    
                    if(inorder[v] == 0)
                        q.push(v);
                    
                    if(quiet[u] < quiet[v]) {
                        quiet[v] = quiet[u];
                        ans[v] = ans[u];
                    }
                }
                
            }
        }
        return ans;
    }

int main(int argc, const char * argv[]) {
    loudAndRich({{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}},
    {3,2,5,4,6,1,7,0});
    return 0;
}

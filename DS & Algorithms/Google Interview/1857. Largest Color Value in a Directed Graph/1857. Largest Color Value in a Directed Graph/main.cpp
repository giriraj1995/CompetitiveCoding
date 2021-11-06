//
//  main.cpp
//  1857. Largest Color Value in a Directed Graph
//
//  Created by Giriraj Saigal on 06/11/21.
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

int largestPathValue(string colors, vector<vector<int>> edges) {
        int n = (int)colors.size();
        vector<int> indegree(n);
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        vector<int> colorsInt(n);
        
        for(int i = 0; i < n; i++) {
            colorsInt[i] = colors[i] - 'a';
        }
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0){
                q.push(i);
                dp[i][colorsInt[i]]++;
            }
        }
        
        int visited = 0;
        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            visited += 1;
            
            for(int v : mp[u]) {
                indegree[v] -= 1;
                
                for(int i = 0; i < 26; i++) {
                    dp[v][i] = max(dp[v][i], dp[u][i] + (i == colorsInt[v] ? 1 : 0));
                }
                
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if(visited != n)
            return -1;
    
        int maxAns = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26 ; j++) {
                maxAns = max(maxAns, dp[i][j]);
            }
        }
        
        return maxAns;
    }

int main(int argc, const char * argv[]) {
    largestPathValue("abaca", {{0,1},{0,2},{2,3},{3,4}});
    return 0;
}

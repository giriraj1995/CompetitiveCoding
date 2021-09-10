//
//  main.cpp
//  Max Edge Queries
//
//  Created by Giriraj Saigal on 08/09/21.
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

bool solve1(int u, int v, vector<set<pair<int,int>>> &adj, map<string,int> &dp, string visited)
{
    string key = to_string(u) + "|" + to_string(v) + "|" + visited;
    
    if(u == v) {
        dp[key] = 0;
        return true;
    }
    
    if(dp.find(key) != dp.end())
        return dp[key];
    
    visited[u] = '1';
    
    int temp = 0;
    bool ans = false;
    for(auto k : adj[u]) {
        if(visited[k.first] == '0') {
            bool t = solve1(k.first,v,adj,dp,visited);
            if(!t)
                continue;
            ans = true;
            int x = max(dp[to_string(k.first) + "|" + to_string(v) + "|" + visited], k.second);
            temp = max(x, temp);
        }
    }
    
    dp[key] = temp;
    return ans;
}
vector<int> solve(vector<vector<int> > A, vector<vector<int> > B) {
    int n = INT_MIN;
    for(auto k : A) {
        n = max(n, max(k[0], k[1]));
    }
    vector<set<pair<int,int>>> adj(n+1);
    for(auto k : A){
        adj[k[0]].insert({k[1],k[2]});
        adj[k[1]].insert({k[0],k[2]});
    }
    map<string, int> dp;
    vector<int> ans;
    
    string visited = string(n+1, '0');
    for(auto q : B){
        solve1(q[0],q[1],adj,dp,visited);
        ans.push_back(dp[to_string(q[0]) + "|" + to_string(q[1]) + "|" + visited]);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({{1,2,11},{1,3,1},{2,4,12},{2,5,100}},{{3,5},{2,3}});
    return 0;
}

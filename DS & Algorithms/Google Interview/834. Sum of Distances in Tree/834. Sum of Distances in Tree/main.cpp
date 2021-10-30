//
//  main.cpp
//  834. Sum of Distances in Tree
//
//  Created by Giriraj Saigal on 30/10/21.
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
//vector<vector<int>> dp;

//bool solve(int src, int parent, int dst, unordered_map<int, vector<int>> &mp) {
//        if(src == dst){
//            dp[src][dst] = 0;
//            dp[dst][src] = 0;
//            return true;
//        }
//
//        if(dp[src][dst] != -1 || dp[dst][src] != -1){
//            return true;
//        }
//
//        bool ans = false;
//
//        for(int v : mp[src]) {
//            if(v != parent) {
//                if(solve(v,src,dst,mp)) {
//                    ans = true;
//                    dp[src][dst] = dp[dst][src] = 1 + dp[v][dst];
//                }
//            }
//        }
//
//        return ans;
//    }
//
//    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> edges) {
//
//        dp = vector<vector<int>>(n, vector<int>(n, -1));
//        vector<int> ans(n, 0);
//        unordered_map<int, vector<int>> mp;
//
//        for(auto k : edges) {
//            mp[k[0]].push_back(k[1]);
//            mp[k[1]].push_back(k[0]);
//        }
//
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < n; j++) {
//                solve(i,-1,j,mp);
//                ans[i] += dp[i][j];
//            }
//        }
//
//        return ans;
//    }

//unordered_map<string, int> dp;
//
//int solve(int src, int parent, int dst, unordered_map<int, vector<int>> &mp) {
//        string key = to_string(src) + "|"  + to_string(parent) + "|" + to_string(dst);
//
//        if(src == dst){
//            return 0;
//        }
//
//        if(dp.count(key))
//            return dp[key];
//
//        int ans = -1;
//
//        for(int v : mp[src]) {
//            if(v != parent) {
//                int k = solve(v, src, dst, mp);
//                if(k != -1) {
//                    ans = 1 + k;
//                }
//            }
//        }
//
//        return dp[key] = ans;
//    }
//
//    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> edges) {
//
//        dp.clear();
//        vector<int> ans(n, 0);
//        unordered_map<int, vector<int>> mp;
//
//        for(auto k : edges) {
//            mp[k[0]].push_back(k[1]);
//            mp[k[1]].push_back(k[0]);
//        }
//
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < n; j++) {
//                ans[i] += solve(i,-1,j,mp);
//            }
//        }
//
//        return ans;
//    }

unordered_map<int, vector<int>> mp;
    int dfs1(int u, vector<bool> &seen, vector<int> &closer, vector<int> &ans) {
        int c = 1;
        
        for(int v : mp[u]) {
            if(seen[v] == false){
                seen[v] = true;
                int x = dfs1(v, seen, closer, ans);
                c += x;
                ans[0] += x;
            }
        }
        
        closer[u] = c;
        
        return c;
    }
    
    void dfs2(int u, vector<bool> &seen, vector<int> &closer, vector<int> &ans) {
        int n = ans.size();
        
        for(int v : mp[u]) {
            if(seen[v] == false) {
                seen[v] = true;
                ans[v] = ans[u] - closer[v] + (n - closer[v]);
                dfs2(v, seen, closer, ans);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> edges) {
        vector<int> ans(n, 0);
        vector<int> closer(n, 0);
        vector<bool> seen(n, false);
        mp.clear();
        
        for(auto k : edges) {
            mp[k[0]].push_back(k[1]);
            mp[k[1]].push_back(k[0]);
        }
        
        seen[0] = true;
        dfs1(0, seen, closer, ans);
        
        seen = vector<bool>(n, false);
        seen[0] = true;
        dfs2(0, seen, closer, ans);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    sumOfDistancesInTree(6,{{0,1},{0,2},{2,3},{2,4},{2,5}});
    return 0;
}

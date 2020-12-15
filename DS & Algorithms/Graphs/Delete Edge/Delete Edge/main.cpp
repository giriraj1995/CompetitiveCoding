//
//  main.cpp
//  Delete Edge
//
//  Created by Giriraj Saigal on 15/12/20.
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

//int find(int a, vector<int> parent) {
//    if(parent[a] == -1)
//        return a;
//    else
//        return parent[a] = find(parent[a], parent);
//}
//
//int deleteEdge(vector<int> A, vector<vector<int> > B) {
//
//    const int MOD = 1000000007;
//    int n = A.size();
//    vector<bool> visited(n, 0);
//
//    long long ans = 0;
//
//    for(int k = 0; k < B.size(); k++){
//        vector<vector<int>> adj(n);
//        vector<int> parent(n, -1);
//
//        for(int i = 0; i < B.size(); i++) {
//
//            if(i == k)
//                continue;
//
//            adj[B[i][0]-1].push_back(B[i][1] -1);
//            parent[B[i][1]-1] = B[i][0]-1;
//        }
//
//        unordered_map<int, int> mp;
//
//        for(int i = 0; i < n; i++){
//            int p = find(i, parent);
//
//            mp[p] += A[i];
//        }
//
//        int x = mp.begin()->second;
//        mp.erase(mp.begin());
//        int y = mp.begin()->second;
//        mp.erase(mp.begin());
//
//        long long prd = (x * y) % MOD;
//
//        ans = max(ans, prd);
//    }
//
//    return ans;
//}

long dfs(int u, vector<int> &A, vector<vector<int> > &adj, vector<bool > &visited,long total ,long &ans){
    
    visited[u] = true;
    long sum;
    long sum1 = 0;
    bool flag = false;
    long sumTotal = 0;
    for(auto v : adj[u]) {
        if(!visited[v]) {
            flag = true;
            sum = dfs(v, A, adj, visited, total, ans);
            sumTotal += sum;
            sum1 = max(sum, sum1);
        }
    }
    
    if(!flag) {
        return A[u];
    }
    ans = max(ans, (total - sum1) * sum1);
    return A[u] + sumTotal;
}

int deleteEdge(vector<int> A, vector<vector<int> > B) {
    
    long sum = 0;
    
    int n = A.size();
    
    for(int i = 0; i < n; i++) {
        sum += A[i];
    }
    
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0] - 1].push_back(B[i][1] - 1);
        adj[B[i][1] - 1].push_back(B[i][0] - 1);
    }
    
    vector<bool> visited(n, false);
    
    long ans = 0;
    
    dfs(0, A, adj, visited, sum ,ans);
    
    return ans;
}



int main(int argc, const char * argv[]) {
    deleteEdge({11, 12}, {
        {1, 2}});
    return 0;
}

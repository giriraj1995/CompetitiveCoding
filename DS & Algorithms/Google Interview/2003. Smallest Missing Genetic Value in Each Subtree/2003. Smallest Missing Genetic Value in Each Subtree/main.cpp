//
//  main.cpp
//  2003. Smallest Missing Genetic Value in Each Subtree
//
//  Created by Giriraj Saigal on 19/10/21.
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
#define N 100002

//int findMissing(vector<int> x) {
//        int i = 0;
//        int n = (int)x.size();
//
//        for(;i < n; i++) {
//            if(x[i] > n || x[i] <= 0)
//                x[i] = n+1;
//        }
//
//        for(i = 0; i < n; i++) {
//            if(x[i] == abs(n+1))
//                continue;
//            x[abs(x[i])-1] = -1 * abs(x[abs(x[i])-1]);
//        }
//
//        for(int i = 0; i < n; i++) {
//            if(x[i] > 0)
//                return i+1;
//        }
//
//        return n+1;
//    }
//
//bool solve(int u, unordered_map<int,vector<int>> &mp, vector<int> &temp, vector<int> &ans, vector<int> &nums) {
//        if(mp[u].size() == 0 ) {
//            temp.push_back(nums[u]);
//            if(nums[u] == 1){
//                ans[u] = 2;
//                return true;
//            }else{
//                return false;
//            }
//        }
//
//        int check = false;
//        vector<int> nowTemp;
//        if(nums[u] == 1)
//            check = true;
//
//        for(int v : mp[u]) {
//            check = check | solve(v, mp, nowTemp, ans, nums);
//        }
//
//        nowTemp.push_back(nums[u]);
//        for(int i : nowTemp)
//            temp.push_back(i);
//
//        if(!check){
//            return false;
//        }
//
//        ans[u] = findMissing(nowTemp);
//
//        return true;
//}
//
//vector<int> smallestMissingValueSubtree(vector<int> parents, vector<int> nums) {
//        int n = (int)parents.size();
//        vector<int> ans = vector<int>(n, 1);
//        int ind = -1;
//
//        for(int i = 0; i < n; i++) {
//            if(nums[i] == 1){
//                ind = i;
//                break;
//            }
//        }
//
//        if(ind == -1)
//            return ans;
//
//        unordered_map<int,vector<int>> mp;
//
//        for(int i = 0; i < n; i++) {
//            if(parents[i] == -1)
//                continue;
//
//            mp[parents[i]].push_back(i);
//        }
//
//        vector<int> temp;
//        solve(0, mp, temp, ans, nums);
//        return ans;
//    }

//void dfs(int u, vector<vector<int>>& adj_list, vector<bool>& subtree) {
//        if (subtree[u]) {
//            return;
//        }
//        subtree.at(u) = true;
//        for (int v: adj_list[u]) {
//            dfs(v, adj_list, subtree);
//        }
//    }
    
//    vector<int> smallestMissingValueSubtree(vector<int> parents, vector<int> nums) {
//        int n = parents.size();
//
//        // Finding adjacency list
//        vector<vector<int>> adj_list(n);
//        for (int i=0; i<n; i++) {
//            int u = parents[i];
//            if (u != -1) {
//                adj_list[u].push_back(i);
//            }
//        }
//
//        // Gives index_with_val[v] = index of a node with value = v
//        vector<int> index_with_val = vector<int>(N, -1);
//        for (int i=0; i<n; i++) {
//            index_with_val[nums[i]] = i;
//        }
//
//        vector<int> ans(n, 1);
//        int m = 1;
//        vector<bool> subtree(n, false);
//        // Move from node with value 1 towards node with value 0.
//        for (int u = index_with_val[1]; u != -1; u = parents.at(u)) {
//            dfs(u, adj_list, subtree);
//            // Invarient: subtree = subtree at node u
//
//            // Find the node with value m and check if that node is in the subtree. While it is in the subtree you keep increasing m
//            int x = index_with_val[m];
//            while (x != -1 && subtree.at(x)) {
//                m += 1;
//                x = index_with_val[m];
//            }
//
//            // m = Minimum value not present in the subtree rooted at u
//            ans[u] = m;
//        }
//
//        return ans;
//    }

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        if(visited[u] == true)
            return;
        
        visited[u] = true;
        
        for(int v : adj[u]) {
            dfs(v, adj, visited);
        }
    }
    
    vector<int> smallestMissingValueSubtree(vector<int> parents, vector<int> nums) {
        int n = (int)parents.size();
        vector<bool> visited(n,false);
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            int p = parents[i];
            if(p == -1)
                continue;
            adj[p].push_back(i);
        }
        
        vector<int> value_node = vector<int>(100005, -1);
        
        for(int i = 0; i < nums.size(); i++) {
            value_node[nums[i]] = i;
        }
        
        vector<int> ans(n,1);
        int m = 1;
        
        for(int u = value_node[1]; u != -1; u = parents[u]) {
            dfs(u, adj, visited);
            
            int x = value_node[m];
            while(x != -1 && visited[x] == true) {
                m+=1;
                x = value_node[m];
            }
            
            ans[u] = m;
        }
        
        return ans;
    }
int main(int argc, const char * argv[]) {
    smallestMissingValueSubtree({-1,0,4,1,3,4,3,5,1,7},
                                {9,8,5,4,10,6,2,1,7,3});
    return 0;
}

//
//  main.cpp
//  22
//
//  Created by Giriraj Saigal on 13/03/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> findKDistantIndices(vector<int> nums, int key, int k) {
        vector<int> ans;
        
        int j = 0;
        
        for(int i : nums) {
            if(i == key) {
                int l;
                if(ans.size() > 0)
                    l = max({j-k,0,ans[ans.size()-1]+1});
                else
                    l = max(j-k,0);

                int h = min((int)nums.size()-1,j+k);

                for(int f = l; f <= h; f++)
                    ans.push_back(f);
            }
            
            j++;
        }
        
        return ans;
    }

vector<long long> solve(long long n, unordered_map<long long, vector<pair<long long,long long>>> &mp, long long s) {
        vector<long long> dist(n, INT_MAX);
        dist[s] = 0;
        // min heap
        priority_queue<pair<int,int>> q;
        q.push({0,s});
        
        while(q.size() > 0) {
            int u = q.top().second;
            q.pop();
            
            for(auto k : mp[u]) {
                int v = k.first;
                int w = k.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    long long minimumWeight(int n, vector<vector<int>> edges, int src1, int src2, int dest) {
        unordered_map<long long, vector<pair<long long,long long>>> mp;
        for(auto k : edges) {
            mp[k[0]].push_back({k[1], k[2]});
        }
        
        vector<long long> x1 = solve(n, mp,src1);
        vector<long long> x2 = solve(n, mp,src2);
        
        long long ans1 = x1[dest] + x1[src2];
        long long ans2 = x2[dest] + x2[src1];
        long long ans3 = x1[dest] + x2[dest];
        
        if(x1[dest] == INT_MAX || x2[dest] == INT_MAX)
            return -1;
        
        return min({ans1,ans2,ans3});
    }

int main(int argc, const char * argv[]) {
    minimumWeight(5,{{0,2,1},{0,3,1},{2,4,1},{3,4,1},{1,2,1},{1,3,10}},
                  0,
                  1,
                  4);
    return 0;
}

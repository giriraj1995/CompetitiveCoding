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

class Solution {
public:
    vector<long long> solve(long long n, unordered_map<long long, vector<pair<long long,long long>>> &mp, long long s) {
        vector<long long> dist(n, LONG_MAX);
        dist[s] = 0;
        // min heap
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> q;
        q.push({0,s});
        
        while(q.size() > 0) {
            int u = q.top().second;
            int x = q.top().first;
            q.pop();
            
            if(x > dist[u])
                continue;
            
            for(auto k : mp[u]) {
                long long v = k.first;
                long long w = k.second;
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
        unordered_map<long long, vector<pair<long long,long long>>> mpR;
        
        for(auto k : edges) {
            mp[k[0]].push_back({k[1], k[2]});
            mpR[k[1]].push_back({k[0], k[2]});
        }
        
        vector<long long> x1 = solve(n, mp,src1);
        vector<long long> x2 = solve(n, mp,src2);
        vector<long long> y = solve(n, mpR, dest);
        
        if(y[src1] == LONG_MAX || y[src2] == LONG_MAX)
            return -1;
        
        long long ans = LONG_MAX;
        for(int i = 0; i < n ; i++) {
            if(x1[i] != LONG_MAX && x2[i] != LONG_MAX && y[i] != LONG_MAX)
                ans = min(ans,x1[i]+x2[i]+y[i]);
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    s.minimumWeight(5,{{0,2,1},{0,3,1},{2,4,1},{3,4,1},{1,2,1},{1,3,10}},
                  0,
                  1,
                  4);
    return 0;
}

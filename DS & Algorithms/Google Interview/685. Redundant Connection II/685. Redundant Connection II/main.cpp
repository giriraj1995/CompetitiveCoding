//
//  main.cpp
//  685. Redundant Connection II
//
//  Created by Giriraj Saigal on 15/10/21.
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

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent = vector<int>(n+1);
        for(int i = 0; i <= n; i++) parent[i]=i;
        size = vector<int>(n+1,1);
    }
    
    int find(int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    bool unionboth(int u, int v) {
        int x = find(u);
        int y = find(v);
        if(x == y) return false;
        if(size[x] < size[y]) {
            size[y] += size[x];
            parent[x] = y;
        }else{
            size[x] += size[y];
            parent[y] = x;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> detectCycle(vector<vector<int>>& edges, int skipEdge) {
        int n = (int)edges.size();
        DSU *x = new DSU(n);
        for(int i = 0; i < edges.size(); i++) {
            if(i == skipEdge)
                continue;
            if(!x->unionboth(edges[i][0],edges[i][1])) return edges[i];
        }
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
        int n = (int)edges.size();
        vector<int> indegree(n+1, 0);
        int indx = -1;
        for(int i = 0; i < edges.size(); i++) {
            indegree[edges[i][1]]++;
            if(indegree[edges[i][1]] == 2)
                indx = edges[i][1];
        }
        if(indx == -1) {
            return detectCycle(edges,-1);
        }
        else{
            for(int i = n-1; i >= 0; i--) {
                if(indegree[edges[i][1]] == 2) {
                    if(detectCycle(edges, i).size() == 0)
                        return edges[i];
                }
            }
        }
        
        return {};
    }
};

int main(int argc, const char * argv[]) {
    Solution *s = new Solution();
    s->findRedundantDirectedConnection({{2,1},{3,1},{4,2},{1,4}});
    return 0;
}

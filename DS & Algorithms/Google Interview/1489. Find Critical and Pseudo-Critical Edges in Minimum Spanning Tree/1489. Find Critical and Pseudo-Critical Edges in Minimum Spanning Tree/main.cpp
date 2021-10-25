//
//  main.cpp
//  1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
//
//  Created by Giriraj Saigal on 25/10/21.
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

class node {
        vector<int> parent;
        vector<int> size;
        public:
            node(int n) {
                size = vector<int>(n,1);
                parent = vector<int>(n);
                for(int i = 0; i < n; i++)
                    parent[i] = i;
            }
        
            int findParent(int x) {
                if(parent[x] == x)
                    return x;
                return parent[x] = findParent(parent[x]);
            }
    
            bool checkifhasoneparent(){
                int x = findParent(parent[0]);
                for(int i = 1; i < parent.size(); i++) {
                    if(findParent(parent[i]) != x)
                        return false;
                }
                return true;
            }
        
            bool unionByRank(int x, int y) {
                int i = findParent(x);
                int j = findParent(y);
                
                if(i == j)
                    return false;
                
                if(size[i] < size[j]) {
                    parent[i] = j;
                }else{
                    parent[j] = i;
                }
                
                return true;
            }
    };

bool cmp(vector<int> x1, vector<int> x2) {
    return x1[2] < x2[2];
}

int mst(int n, vector<vector<int>> edges, int include, int exclude) {
        
        int ans = 0;
        
        node* t = new node(n);
    
        if(include != -1){
            ans += edges[include][2];
            t->unionByRank(edges[include][0], edges[include][1]);
        }
    
        if(exclude != -1){
            edges.erase(edges.begin()+exclude);
        }
            
        for(int i = 0; i < edges.size(); i++) {
            if(t->unionByRank(edges[i][0], edges[i][1])){
                ans += edges[i][2];
            }
        }
        
    if(!t->checkifhasoneparent()) {
        return INT_MAX;
    }
    
        return ans;
    }
    
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> edges){
    
    for(int i = 0; i < edges.size(); i++){
        edges[i].push_back(i);
    }
    
    sort(edges.begin(), edges.end(), cmp);
    int oc = mst(n, edges, -1, -1);
    
    vector<int> cri;
    vector<int> pse;
    
    for(int i = 0; i < edges.size(); i++) {
        int ec = mst(n, edges, -1, i);
        
        if(ec > oc)
            cri.push_back(edges[i][3]);
        else{
            int ic = mst(n, edges, i, -1);
            if(ic == oc) {
                pse.push_back(edges[i][3]);
            }
        }
    }
    
    return {cri, pse};
}

double findArea(vector<int> x, vector<int> y, vector<int> z) {
    return 0.5 * (x[0]*(z[1] - y[1]) + y[0]*(z[1] - x[1]) + z[0]*(y[1] - x[1]));
}

double largestTriangleArea(vector<vector<int>>& points) {
    double x = 0;
    int n = points.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                x = max(x, findArea(points[i],points[j],points[k]));
            }
        }
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    findCriticalAndPseudoCriticalEdges(28,
    {{0,1,18},{1,2,18},{2,3,8},{2,4,12},{0,5,18},{2,6,19},{6,7,2},{3,8,1},{0,9,27},{7,10,1},{7,11,28},{2,12,24},{11,13,22},{7,14,9},{9,15,23},{10,16,19},{15,17,3},{17,18,8},{2,19,17},{9,20,27},{9,21,19},{9,22,13},{9,23,5},{5,24,13},{21,25,8},{2,26,27},{14,27,17},{19,23,3},{6,14,11},{0,10,4},{7,19,15},{8,23,14},{0,18,5},{17,25,15},{20,25,25},{15,18,26},{13,21,2},{13,20,4},{0,23,11},{0,13,26},{11,14,20},{16,17,9},{0,3,11},{7,8,16},{6,27,10},{3,12,7},{24,25,5},{3,9,25},{6,10,18},{1,17,22},{4,25,1},{11,23,26},{14,26,23},{4,18,16},{9,10,15},{7,21,18},{16,22,10},{3,26,24},{1,5,22},{11,22,22},{10,11,17},{7,23,12},{3,22,18},{19,21,1},{16,18,17},{1,8,7},{10,12,9},{5,18,1},{5,20,11},{4,6,16},{1,21,24},{18,20,8},{6,11,25},{3,10,1},{8,16,12},{8,13,22},{3,17,12},{1,19,13},{11,20,16},{17,23,6},{7,17,26},{22,23,15},{6,19,9},{1,6,27},{11,19,25},{3,20,8},{15,27,21},{18,25,27},{7,20,2},{5,9,21},{4,19,12},{21,26,16},{18,27,27},{6,15,15},{9,25,13},{16,26,24},{11,26,23},{2,16,6},{4,14,9},{5,11,7},{14,21,2},{16,19,3},{0,2,2},{24,26,21},{19,25,17},{2,23,8},{7,25,18},{7,18,17},{3,21,19},{10,23,25},{8,27,12},{13,27,3},{19,24,14},{3,14,10},{18,22,17},{23,24,25},{21,24,8},{10,22,15},{1,23,16},{23,25,2},{5,23,16},{9,14,27},{21,23,25},{4,8,5},{11,25,8},{3,19,10},{11,27,23},{0,27,24},{5,15,9},{8,18,6},{0,16,25},{6,13,9},{13,26,15},{0,6,25},{2,8,13},{14,15,8},{2,18,21},{2,20,20},{6,25,8},{9,27,13},{0,26,26},{14,25,19},{15,20,5},{5,7,8},{13,15,14},{26,27,26},{8,24,6},{5,21,8},{3,24,18},{11,16,6},{2,17,12},{14,18,5},{10,21,9},{1,25,18},{0,22,15},{15,22,17},{8,21,7},{8,26,9},{15,19,1},{0,4,17},{17,20,19},{14,24,7},{15,21,9},{11,15,1},{0,19,23},{6,26,27},{21,22,7},{9,24,5},{9,18,20},{4,12,21},{1,22,2},{7,24,9},{13,17,18},{6,22,17},{4,27,24},{18,24,18},{15,24,6},{16,23,9},{17,26,1},{3,7,27},{5,13,8},{20,21,25},{16,27,7},{22,25,20},{6,20,17},{17,27,25},{1,10,10},{9,19,6},{4,20,19},{10,20,14},{12,24,11},{23,26,25},{5,25,20},{12,25,9},{12,20,2},{16,25,11},{4,7,21},{6,8,18},{15,23,28},{7,15,20}});
    return 0;
}

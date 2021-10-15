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

int findP(int i, vector<int> parent) {
       if(parent[i] == i)
           return i;
       return parent[i] = findP(parent[i], parent);
   }
   
   vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
       int edgesCount = edges.size();
       if(edgesCount <= 1)
           return {};
       int n = -1;
       
       for(int i = 0; i < edgesCount; i++) {
           n = max(n, edges[i][0]);
           n = max(n, edges[i][1]);
       }
       
       vector<int> parent(n);
       
       for(int i = 0; i < n; i++)
           parent[i] = i;
       
       for(int i = 0; i < edgesCount; i++) {
           int x = findP(edges[i][0]-1, parent);
           int y = findP(edges[i][1]-1, parent);
           
           if(edges[i][1]-1 == y) {
               parent[y] = x;
           }else{
               return {edges[i][0], edges[i][1]};
           }
       }
       
       return {};
   }

int main(int argc, const char * argv[]) {
    findRedundantDirectedConnection({{1,2},{1,3},{2,3}});
    return 0;
}

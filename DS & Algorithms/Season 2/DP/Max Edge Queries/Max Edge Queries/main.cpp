//
//  main.cpp
//  Max Edge Queries
//
//  Created by Giriraj Saigal on 24/08/21.
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

void findMaxEdge(int i, int j, vector<vector<pair<int,int>>> x, vector<int> visited, vector<int> way, vector<vector<int>> &ways) {
    way.push_back(i);
    
    if(i == j) {
        ways.push_back(way);
        return;
    }
    
    visited[i] = 1;
    
    for(auto v : x[i]) {
        if(visited[v.first] == 0) {
            findMaxEdge(v.first, j, x, visited, way, ways);
        }
    }
    
    return;
}

vector<int> solve(vector<vector<int> > A, vector<vector<int> > B) {
    int n = 0;
    
    if(A.size() == 0)
        return {};
        
    for(int i = 0; i < A.size(); i++) {
        n = max(n, max(A[i][0], A[i][1]));
    }
    
    vector<int> visited(n, 0);
    vector<vector<pair<int,int>>> x = vector<vector<pair<int,int>>>(n);
    
    for(int i = 0; i < A.size(); i++) {
        x[A[i][0]-1].push_back({A[i][1]-1, A[i][2]});
        x[A[i][1]-1].push_back({A[i][0]-1, A[i][2]});
    }
    
    vector<vector<int>> t(n, vector<int>(n, INT_MIN));
    
    for(int i = 0; i < A.size(); i++) {
        t[A[i][0]-1][A[i][1]-1] = A[i][2];
        t[A[i][1]-1][A[i][0]-1] = A[i][2];
    }
    
    vector<int> ans;
    for(int i = 0; i < B.size(); i++) {
        vector<vector<int>> ways;
        findMaxEdge(B[i][0]-1, B[i][1]-1, x, visited, {}, ways);
        int maxo = INT_MIN;
        for(auto f : ways) {
            for(int i = 1; i < f.size(); i++) {
                maxo = max(maxo, t[f[i]][f[i-1]]);
            }
        }
        ans.push_back(maxo);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout << solve({
        {10, 6, 42},
        {3, 2, 18468},
        {12, 7, 6335},
        {9, 5, 26501},
        {2, 1, 19170},
        {8, 3, 15725},
        {7, 1, 11479},
        {4, 2, 29359},
        {6, 3, 26963},
        {11, 4, 24465},
        {5, 3, 5706},
        {13, 11, 28146},
      },
          {
            {13, 5}
          })[0] << endl;
    return 0;
}

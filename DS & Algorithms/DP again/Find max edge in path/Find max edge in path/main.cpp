//
//  main.cpp
//  Find max edge in path
//
//  Created by Giriraj Saigal on 31/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void findMaxEdge(int s, int d, vector<vector<int>> m, vector<int> &visited, int w, int &ans){
    
    int n = m.size()-1;
    visited[s] = 1;
    
    if(s == d){
        ans = w;
        return;
    }
    
    int g = w;
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0 && m[s][i] != 0){
            findMaxEdge(i, d, m, visited, max(w, m[s][i]), ans);
        }
    }
    
    w = g;
    visited[s] = 0;
    
}

vector<int> solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    int n = A.size()+1;
    vector<int> ans;
    
    if(n == 0)
        return ans;
        
    vector<vector<int>> m(n+1, vector<int>(n+1, 0));
        
    for(int i = 0; i < A.size(); i++) {
        m[A[i][0]][A[i][1]] = A[i][2];
        m[A[i][1]][A[i][0]] = A[i][2];
    }
    
    
    for(int i = 0; i < B.size(); i++) {
        vector<int> visited(n+1, 0);
        int w = 0;
        int x = 0;
        findMaxEdge(B[i][0], B[i][1], m, visited, w, x);
        ans.push_back(x);
    }
    
    return ans;
    
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> A = {   {8, 2, 23282},
        {6, 3, 16828},
        {5, 2, 9962},
        {3, 1, 492},
        {4, 2, 2996},
        {7, 2, 11943},
        {2, 1, 4828}};
    
    vector<vector<int>> B = {  {1, 3},
        {8, 4}, {2,4}
    };
    solve(A, B);
    
    return 0;
}

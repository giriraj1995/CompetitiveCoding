//
//  main.cpp
//  Useful Extra Edges
//
//  Created by Giriraj Saigal on 25/09/21.
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

int solve(int A, vector<vector<int> > B, int C, int D, vector<vector<int> > E) {
    
    unordered_map<int, vector<pair<int,int>>> mp;
    
    for(int i = 0; i < B.size(); i++) {
        mp[B[i][0]-1].push_back({B[i][1]-1, B[i][2]});
    }
    
    int ans = INT_MAX;
    
    for(int i = 0; i < E.size(); i++) {
        unordered_map<int, vector<pair<int,int>>> mp2 = mp;
        mp2[E[i][0]-1].push_back({E[i][1]-1, E[i][2]});
        mp2[E[i][1]-1].push_back({E[i][0]-1, E[i][2]});
        vector<int> visited(A, INT_MAX);
        visited[C-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,C-1});
        visited[C-1] = 0;
        
        while(q.size() > 0) {
            int u = q.top().second;
            int d = q.top().first;
            q.pop();
            for(pair<int,int> p : mp2[u]) {
                if(d+p.second < visited[p.first]) {
                    visited[p.first] = d+p.second;
                    q.push({d+p.second, p.first});
                }
            }
        }
        
        ans = min(ans, visited[D-1]);
    }
    
    return ans == INT_MAX ? -1 : ans;
}


int main(int argc, const char * argv[]) {
    cout << solve(5, {{1, 2, 2},{1, 3, 2},{2, 4, 1},{2, 5, 4}}, 3, 5, {{2,3,3}}) << endl;
    return 0;
}

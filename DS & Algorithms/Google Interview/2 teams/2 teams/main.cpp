//
//  main.cpp
//  2 teams
//
//  Created by Giriraj Saigal on 27/09/21.
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

bool setandcheck(int u, int team, unordered_map<int,vector<int>> &mp, vector<int> &visited) {
    visited[u] = team;
    
    for(int v : mp[u]) {
        if(visited[v] == team)
            return false;
        else if(visited[v] == -1){
            if(!setandcheck(v, (team+1)%2, mp, visited))
                return false;
        }
    }
    
    return true;
}

int solve(int A, vector<vector<int> > B) {
    if(A == 0 || A == 1)
        return 1;
    
    int ans = 0;
    unordered_map<int,vector<int>> mp;
    
    vector<int> visited(A, -1);
    for(auto k : B) {
        mp[k[0]-1].push_back(k[1]-1);
        mp[k[1]-1].push_back(k[0]-1);
    }
    
    return setandcheck(0,0,mp,visited);
}

int main(int argc, const char * argv[]) {
    cout << solve(4, {{1,4},{3,1},{4,3},{2,1}}) << endl;
    return 0;
}

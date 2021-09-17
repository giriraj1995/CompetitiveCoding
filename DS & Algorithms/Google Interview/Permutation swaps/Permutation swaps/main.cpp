//
//  main.cpp
//  Permutation swaps
//
//  Created by Giriraj Saigal on 17/09/21.
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

void isReachable(int src, vector<int> &visited, map<int, set<int>> &mp, int c) {
    visited[src-1] = c;
    
    for(int v : mp[src]){
        if(visited[v-1] == 0) {
            isReachable(v, visited, mp, c);
        }
    }
}

int solve(vector<int> A, vector<int> B, vector<vector<int> > C) {
    int n = A.size();
    map<int, set<int>> mp;

    for(auto i : C) {
        mp[A[i[0]-1]].insert(A[i[1]-1]);
        mp[A[i[1]-1]].insert(A[i[0]-1]);
    }

    vector<int> visited(n, 0);
    int c = 1;
    
    for(int i = 0; i < n; i++) {
        if(visited[A[i]-1] == 0){
            isReachable(A[i], visited, mp, c);
            c++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i] && visited[A[i]-1] != visited[B[i]-1])
            return false;
    }

    return true;
}


int main(int argc, const char * argv[]) {
    solve({1,2,3,4,5,6,7,8,9},{1,4,9,6,7,2,5,8,3},{{1,8},{2,3},{3,5},{4,5},{5,6},{7,9}
    });
    return 0;
}

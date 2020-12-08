//
//  main.cpp
//  Possibility of finishing all courses given pre-requisites
//
//  Created by Giriraj Saigal on 08/12/20.
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

//int solve2(int ele, vector<vector<int>> v, vector<int> visited) {
//
//    visited[ele] = 1;
//
//    vector<int> x = v[ele];
//    int flag = 0;
//
//    for(int i = 0; i < x.size(); i++) {
//        if(visited[x[i]] == 0) {
//            flag = 1;
//            break;
//        }
//    }
//
//    int ans = 0;
//
//    int flag2 = 0;
//    if(flag == 1) {
//        return 0;
//    }else{
//        for(int j = 1; j <= visited.size()-1; j++) {
//            if(visited[j] == 0) {
//                flag2 = 1;
//                ans = solve2(j, v, visited);
//                if(ans == 1) {
//                    return 1;
//                }
//            }
//        }
//    }
//
//    if(flag2 == 0) {
//        return 1;
//    }
//
//    return 0;
//}
//
//int solve(int A, vector<int> B, vector<int> C) {
//
//    vector<vector<int>> v(A+1);
//    for(int i = 0; i < C.size(); i++) {
//        v[C[i]].push_back(B[i]);
//    }
//
//    unordered_map<int, int> mp;
//
//    for(int i = 1; i <= A; i++) {
//        if(v[i].size() == 0){
//            mp[i] = 1;
//        }
//    }
//
//    vector<int> visited(A+1, 0);
//
//    int ans = 0;
//    for(auto m : mp) {
//        visited = vector<int> (A+1, 0);
//        ans = solve2(m.first, v, visited);
//        if(ans == 1)
//            return 1;
//    }
//
//    return 0;
//
//}

int find(int a, vector<int> &parent) {
    if(parent[a] < 0)
        return a;
    
    return parent[a] = find(parent[a], parent);
}

int solve2(int t, vector<vector<int>> edges, vector<int> visited) {
    
    queue<int> q;
    q.push(t);
    visited[t] = 0;
    
    while(q.size() > 0) {
        int k = q.front();
        q.pop();
        
        visited[k] = 1;
        vector<int> x = edges[k];
        
        for(int i = 0; i < x.size(); i++) {
            if(visited[x[i]] == -1) {
                visited[x[i]] = 0;
                q.push(x[i]);
            }else{
                return 0;
            }
        }
    }
    
    for(int i = 1; i <= visited.size()-1; i++) {
        if(visited[i] < 1) {
            return 0;
        }
    }
    
    return 1;
}

int solve(int A, vector<int> B, vector<int> C) {
    
    vector<int> parent(A+1, -1);
    
    vector<vector<int>> edges(A+1);
        
    for(int i = 0; i < C.size(); i++) {
        edges[B[i]].push_back(C[i]);
    }
    
    int ans = 0;
    vector<int> visited(A+1, -1);
    for (int i = 1; i <= A; i++) {
        ans = solve2(i, edges, visited);
        
        if(ans == 1)
            return 1;
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    solve(3, {1,2,3}, {2,3,1});
    return 0;
}

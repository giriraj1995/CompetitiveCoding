//
//  main.cpp
//  krushkals 2
//
//  Created by Giriraj Saigal on 07/12/20.
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

int find(int a, vector<int> &parent) {
    if(parent[a] < 0)
        return a;
    
    return parent[a] = find(parent[a], parent);
}

int solve(int A, vector<vector<int> > &B) {
    
    vector<pair<int, pair<int, int>>> mp;
    
    for(int i = 0; i < B.size(); i++) {
        mp.push_back({B[i][2], {B[i][0], B[i][1]}});
    }
    
    sort(mp.begin(), mp.end());
    
    vector<int> parent(A+1, -1);
    
    int sum = 0;
    
    for(int i = 0; i < mp.size(); i++) {
        int x = find(mp[i].second.first, parent);
        int y = find(mp[i].second.second, parent);
        
        if(x != y){
            parent[y] = x;
            sum += mp[i].first;
        }
    }
    
    return sum;
    
}

int main(int argc, const char * argv[]) {
    int n = 6;
    vector<vector<int>> edges = {
        {1,2,10},
        {1,2,5},
        {1,3,3},
        {1,6,7},
        {2,3,6},
        {2,4,2},
        {2,5,4},
        {3,6,1},
        {3,4,3},
        {4,5,2},
        {5,5,1}
    };
    
    solve(n, edges);
    return 0;
}

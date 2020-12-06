//
//  main.cpp
//  Min spanning tree - Krushkals
//
//  Created by Giriraj Saigal on 06/12/20.
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

int find(int a, vector<int> &parent){
    
    if(parent[a] < 0)
        return a;

    return parent[a] = find(parent[a], parent);
}

int kruskals(int n, vector<vector<int>> edges) {
    
    vector<pair<int, pair<int, int>>> mp;
    
    for(int i = 0; i < edges.size(); i++) {
        mp.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
    }
    
    sort(mp.begin(), mp.end());
    
    vector<int> parent(n+1, -1);
    
    int sum = 0;
    
    //disjoint sets
    for(int i = 0; i < mp.size(); i++) {
        int a = mp[i].second.first;
        int b = mp[i].second.second;
        int x = find(a, parent);
        int y = find(b, parent);
        
        if(x != y) {
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
    cout<<"Min Spanning tree weight : " <<kruskals(n,edges)<<endl;
    return 0;
}

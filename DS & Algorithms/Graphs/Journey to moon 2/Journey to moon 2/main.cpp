//
//  main.cpp
//  Journey to moon 2
//
//  Created by Giriraj Saigal on 19/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int find(int x, vector<int> &parent){
    if(parent[x] == x)
        return x;
        
    return parent[x] = find(parent[x], parent);
}

int journeyToMoon(int n, vector<vector<int>> A) {
    
    vector<int> parent(n);
    
    for(int i = 0; i < n; i++) {
        parent[i]=i;
    }
    
    vector<bool> visited(n, false);
    map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        int x = A[i][0];
        int y = A[i][1];
        
        int a = find(x, parent);
        int b = find(y, parent);
        
        if(a != b) {
            parent[b] = a;
        }
    }
    
    for(int i = 0; i < n; i++) {
        mp[find(i, parent)]++;
    }
    
    int ans = 0;
    int total = 0;
    
    for(auto i : mp) {
        ans += total * i.second;
        total += i.second;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    journeyToMoon(5, {{0,1},{2,3},{0,4}});
    return 0;
}

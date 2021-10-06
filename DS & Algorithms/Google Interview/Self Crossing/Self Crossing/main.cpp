//
//  main.cpp
//  Self Crossing
//
//  Created by Giriraj Saigal on 06/10/21.
//

#define pii pair<pair<int,int>,pair<int,int>>

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

bool checkForAdjacentRule(map<pii, int> &mp, pii x, pii y) {
    if(mp[x] == mp[y]+1 || mp[x]+1 == mp[y])
        return false;
    
    return true;
}

bool isSelfCrossing(vector<int> d) {
    int n = (int)d.size();
    
    vector<pii> verticles;
    vector<pii> horizontals;
    map<pii, int> mp;
    pair<int,int> s = {0,0};
    
    for(int i = 0; i < n; i++) {
        int k = i%4;
        pair<int,int> e;
        
        if(k == 0) {
            e = {s.first,s.second+d[i]};
            verticles.push_back({s,e});
        }
                            
        if(k == 1) {
            e = {s.first-d[i],s.second};
            horizontals.push_back({s,e});
        }
                            
        if(k == 2) {
            e = {s.first,s.second-d[i]};
            verticles.push_back({s,e});
        }
                            
        if(k == 3) {
            e = {s.first+d[i],s.second};
            horizontals.push_back({s,e});
        }
        
        mp[{s,e}] = i;
        s = e;
    }
    
    for(int p = 0; p < verticles.size(); p++) {
        
        int vx = verticles[p].first.first;
        int vymin = min(verticles[p].first.second, verticles[p].second.second);
        int vymax = max(verticles[p].first.second, verticles[p].second.second);
        
        for(int q = 0; q < horizontals.size(); q++) {
            int hy = horizontals[q].first.second;
            int hxmin = min(horizontals[q].first.first, horizontals[q].second.first);
            int hxmax = max(horizontals[q].first.first, horizontals[q].second.first);
            
            if(vx >= hxmin && vx <= hxmax && hy >= vymin && hy <= vymax && checkForAdjacentRule(mp,verticles[p],horizontals[q]))
                return true;
        }
    }
    
    for(int p = 0; p < verticles.size(); p++) {
        
        int v1x = verticles[p].first.first;
        int v1ymin = min(verticles[p].first.second, verticles[p].second.second);
        int v1ymax = max(verticles[p].first.second, verticles[p].second.second);
        
        for(int q = p+1; q < verticles.size(); q++) {
            int v2x = verticles[q].first.first;
            int v2ymin = min(verticles[q].first.second, verticles[q].second.second);
            int v2ymax = max(verticles[q].first.second, verticles[q].second.second);
            
            if(v1x == v2x && v1ymin <= v2ymax && v1ymax >= v2ymin)
                return true;
        }
    }
    
    for(int p = 0; p < horizontals.size(); p++) {
        
        int h1y = horizontals[p].first.second;
        int h1xmin = min(horizontals[p].first.first, horizontals[p].second.first);
        int h1xmax = max(horizontals[p].first.first, horizontals[p].second.first);
        
        for(int q = p+1; q < horizontals.size(); q++) {
            
            int h2y = horizontals[q].first.second;
            int h2xmin = min(horizontals[q].first.first, horizontals[q].second.first);
            int h2xmax = max(horizontals[q].first.first, horizontals[q].second.first);
            
            if(h1y == h2y && h1xmin <= h2xmax && h1xmax >= h2xmin)
                return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cout << isSelfCrossing({1,2,3,4}) << endl;
    return 0;
}

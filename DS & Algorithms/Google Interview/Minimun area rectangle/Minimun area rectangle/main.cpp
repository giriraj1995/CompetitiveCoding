//
//  main.cpp
//  Minimun area rectangle
//
//  Created by Giriraj Saigal on 26/10/21.
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

int minAreaRect(vector<vector<int>> points) {
        map<int, set<int>> mp;
        int n = points.size();
        
        for(int i = 0; i < n; i++) mp[points[i][0]].insert(points[i][1]);
        
        int ans = INT_MAX;
        
        for(auto i = mp.begin(); i != mp.end(); ++i) {
            if(i->second.size() < 2) continue;
            auto k = i;
            ++k;
            for(auto j = k; j != mp.end(); ++j) {
                if(j->second.size() < 2) continue;
                vector<int> v;
                
                set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(v));
                if(v.size() == 0)
                    continue;
                for(int t = 0; t < v.size()-1; t++) {
                    ans = min(ans, abs(j->first-i->first) * (v[t+1] - v[t]));
                }
            }
        }
        
         return ans == INT_MAX ? 0 : ans;
    }

int main(int argc, const char * argv[]) {
    cout << minAreaRect({{3,2},{3,1},{4,4},{1,1},{4,3},{0,3},{0,2},{4,0}}) << endl;
    return 0;
}

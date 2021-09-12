//
//  main.cpp
//  Max points in a line
//
//  Created by Giriraj Saigal on 12/09/21.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <limits>
#include <cfloat>

using namespace std;


int maxPoints(vector<vector<int>> points) {
    int n = points.size();
    
    if(n <= 2)
        return n;
    
    map<double, vector<set<pair<int,int>>>> mp;
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            
            double m;
            if((points[i][0] - points[j][0]) == 0) {
                m = DBL_MAX;
            }else{
                m = (points[i][1] - points[j][1]) / ((points[i][0] - points[j][0]) * 1.0);
                if(m == -0.0)
                    m = 0;
            }
            if(mp.find(m) != mp.end()) {
                
                int k;
                for( k = 0; k < mp[m].size(); k++) {
                    if(mp[m][k].find({points[i][0],points[i][1]}) != mp[m][k].end()
                      ||
                       mp[m][k].find({points[j][0],points[j][1]}) != mp[m][k].end()) {
                        mp[m][k].insert({points[i][0],points[i][1]});
                        mp[m][k].insert({points[j][0],points[j][1]});
                        ans = max(ans, (int)mp[m][k].size());
                        break;
                    }
                }
                
                if(k == mp[m].size()) {
                    set<pair<int,int>> s;
                    s.insert({points[i][0],points[i][1]});
                    s.insert({points[j][0],points[j][1]});
                    ans = max(ans, 2);
                    mp[m].push_back(s);
                }
                
            }else{
                set<pair<int,int>> s;
                s.insert({points[i][0],points[i][1]});
                s.insert({points[j][0],points[j][1]});
                mp[m].push_back(s);
                ans = max(ans, 2);
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    maxPoints({{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}});
    return 0;
}

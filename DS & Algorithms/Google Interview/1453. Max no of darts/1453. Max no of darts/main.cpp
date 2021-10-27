//
//  main.cpp
//  1453. Max no of darts
//
//  Created by Giriraj Saigal on 27/10/21.
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

int numPoints(vector<vector<int>>points, int r) {
        //sort(points.begin(), points.end(), cmp);
        map<int, set<int>> mp;
        
        for(int i = 0; i < points.size(); i++) {
            mp[points[i][0]].insert(points[i][1]);
        }
        
        int ans = 0;
        
        for(auto i = mp.begin(); i != mp.end(); ++i) {
            int x = i->first;
            for(int y : i->second) {
                int temp = 0;
                
                set<vector<int>> s;
                s.insert({x,y});
                
                for(int yn : i->second) {
                    bool check = true;
                    for(auto f : s) {
                        if(sqrt((f[0]-x)*(f[0]-x) + (f[1]-yn)*(f[1]-yn)) <= 2*r){
                            
                        }else{
                            check = false;
                        }
                    }
                    
                    if(check){
                        s.insert({x,yn});
                    }
                }
                
                auto k = i;
                ++k;
                
                for(auto j = k; j != mp.end() && j->first-x < 2*r; j++) {
                    int x2 = j->first;
                    for(int y2 : j->second) {
                        bool check = true;
                        for(auto f : s) {
                            if(sqrt((f[0]-x2)*(f[0]-x2) + (f[1]-y2)*(f[1]-y2)) <= 2*r){
                                
                            }else{
                                check = false;
                                break;
                            }
                        }
                        
                        if(check){
                            s.insert({x2,y2});
                        }
                    }
                }
                
                if(mp.count(x+2*r) && mp[x+2*r].count(y))
                    temp++;
                
                ans = max(ans, (int)s.size());
            }
        }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    numPoints({{1,2},{3,5},{1,-1},{2,3},{4,1},{1,3}},
              2);
    return 0;
}

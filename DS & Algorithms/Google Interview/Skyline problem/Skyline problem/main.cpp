//
//  main.cpp
//  Skyline problem
//
//  Created by Giriraj Saigal on 15/09/21.
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

vector<vector<int>> getSkyline(vector<vector<int>>& b) {
    map<int, set<pair<int,bool>>> mp;
    
    for(auto k : b) {
        mp[k[0]].insert({k[2], true});
        mp[k[1]].insert({k[2], false});
    }
    
    map<int, int> mapMap;
    vector<vector<int>> ans1;
    int prevheight = -1;
    
    for(auto j: mp) {
        for(auto g : j.second) {
            if(g.second == true){
                mapMap[g.first]++;
            }else{
                mapMap[g.first]--;
                if(mapMap[g.first] == 0)
                    mapMap.erase(g.first);
            }
        }
        
        if((mapMap.size() == 0 ? 0 : mapMap.rbegin()->first) != prevheight){
            ans1.push_back({j.first, mapMap.size() == 0 ? 0 : mapMap.rbegin()->first});
            prevheight = (mapMap.size() == 0 ? 0 : mapMap.rbegin()->first);
        }
         
    }
    
    return ans1;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> x = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    getSkyline(x);
    return 0;
}

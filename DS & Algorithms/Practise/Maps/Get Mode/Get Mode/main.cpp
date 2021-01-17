//
//  main.cpp
//  Get Mode
//
//  Created by Giriraj Saigal on 17/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

vector<int> getMode(vector<int> A, vector<vector<int> > B) {
    
    vector<int> ans;
       
       unordered_map<int, int> mp;
       map<int,set<int>,greater<>> se;

       for(int i : A) {
           mp[i]++;
       }
       
       for(auto k : mp) {
           se[k.second].insert(k.first);
       }
       
       for(auto arr : B) {
           int ind = arr[0]-1;
           int fr = A[ind];
           int to = arr[1];
           
           se[mp[fr]].erase(fr);
           
           if(se[mp[fr]].size() == 0) {
               se.erase(mp[fr]);
           }
           
           mp[fr]--;
           
           if(mp[fr] == 0)
               mp.erase(fr);
           else
               se[mp[fr]].insert(fr);
               
           
           se[mp[to]].erase(to);
           
           if(se[mp[to]].size() == 0) {
               se.erase(mp[to]);
           }
           
           mp[to]++;
           se[mp[to]].insert(to);
           
           A[ind] = to;
           
           ans.push_back(*(se.begin()->second.begin()));
       }
       
       return ans;
}


int main(int argc, const char * argv[]) {
    getMode({2, 2, 2, 3, 3}, {{1,3},{5,4},{2,4}});
    return 0;
}

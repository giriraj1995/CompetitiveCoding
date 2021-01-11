//
//  main.cpp
//  Two out of 3
//
//  Created by Giriraj Saigal on 11/01/21.
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

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    map<int, set<int>> mp;
    
    for(int i : A) {
        mp[i].insert(1);
    }
    
    for(int i : B) {
        mp[i].insert(2);
    }
    
    for(int i : C) {
        mp[i].insert(3);
    }
    
    vector<int> ans;
    
    for(auto k : mp) {
        if(k.second.size() >= 2) {
            ans.push_back(k.first);
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

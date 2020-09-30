//
//  main.cpp
//  Hotel Reviews
//
//  Created by Giriraj Saigal on 30/09/20.
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

vector<int> solve(string A, vector<string> &B) {
    
    map<string, bool> mp;
    string x;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == '_'){
            mp[x] = true;
            x = "";
            continue;
        }
        x += A[i];
    }
    
    mp[x] = true;
    map<int, vector<int>, greater<int>> u;
    
    for(int i = 0; i < B.size(); i++){
        
        x = B[i];
        string k;
        int c = 0;
        for(int j = 0; j < x.size(); j++){
        
            if(x[j] == '_'){
                
                if(mp.find(k) != mp.end()){
                    c++;
                }
                
                k = "";
                continue;
            }
            
            k+=x[j];
        }
        
        if(mp.find(k) != mp.end()){
            c++;
        }
        
        u[c].push_back(i);
    }
    
    vector<int> ans;
    for(auto it : u)
    {
        vector<int> temp = it.second;
        for(int i : temp)
            ans.push_back(i);
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    vector<string> x = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    solve("cool_ice_wifi", x);
    return 0;
}

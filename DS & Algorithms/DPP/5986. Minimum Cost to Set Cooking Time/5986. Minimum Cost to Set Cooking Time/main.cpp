//
//  main.cpp
//  5986. Minimum Cost to Set Cooking Time
//
//  Created by Giriraj Saigal on 05/02/22.
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

vector<string> solve(int targetSeconds) {
    if(targetSeconds < 60) {
        
        string x = to_string(targetSeconds);
        vector<string> ans;
        while(x.size() <= 4) {
            ans.push_back(x);
            x.insert(x.begin(), '0');
        }
        
        return ans;
    }
    
    int minutes = targetSeconds/60;
    int seconds = targetSeconds%60;
    
    string s = to_string(seconds);
    
    if(seconds < 10)
        s = "0" + to_string(seconds);
    
    vector<string> ans;
    
    string x = to_string(minutes) + s;
    
    while(x.size() <= 4) {
        ans.push_back(x);
        x.insert(x.begin(), '0');
    }
    
    if(seconds + 60 < 100) {
        
        string t = "";
        
        if(minutes-1 == 0) {
            t = to_string(seconds+60);
        }else{
            t = to_string(minutes-1) + to_string(seconds+60);
        }
        
        while(t.size() <= 4) {
            ans.push_back(t);
            t.insert(t.begin(), '0');
        }
    }
    
    return ans;
}
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        vector<string> x = solve(targetSeconds);
        
        int ans = INT_MAX;
        for(int i = 0; i < x.size(); i++) {
            string v = x[i];
            int value = 0;
            char prev = startAt+'0';
            
            for(int j = 0; j < v.size(); j++) {
                if(prev != v[j]) {
                    value += moveCost;
                }
                value += pushCost;
                prev = v[j];
            }
            
            ans = min(ans, value);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    minCostSetTime(5,1,3,301);
    return 0;
}

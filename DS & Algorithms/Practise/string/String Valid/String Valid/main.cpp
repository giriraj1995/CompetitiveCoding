//
//  main.cpp
//  String Valid
//
//  Created by Giriraj Saigal on 10/01/21.
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

string isValid(string s) {
    unordered_map<char, int> mp;
    map<int, int> mp2;

    int n = s.size();

    for(char c : s) {
        if(mp[c] != 0)
            mp2[mp[c]]--;
        
        if(mp2[mp[c]] == 0)
            mp2.erase(mp[c]);
            
        mp[c]++;
        mp2[mp[c]]++;
    }
    
    if(mp2.size() == 1)
        return "YES";
    else if(mp2.size() == 2) {
        pair<int, int> x,y;
        
        int k = 0;
        for(auto i : mp2) {
            if(k == 0)
            x = {i.first, i.second};
            
            if(k == 1)
            y = {i.first, i.second};
            
            k++;
        }
        
        
        if(abs(y.first - x.first) != 1)
            return "NO";
        
        if(y.second != 1)
            return "NO";
        
        else
            return "YES";
        
    }else{
        return "NO";
    }
}

int main(int argc, const char * argv[]) {
    isValid("abcdefghhgfedecba");
    return 0;
}

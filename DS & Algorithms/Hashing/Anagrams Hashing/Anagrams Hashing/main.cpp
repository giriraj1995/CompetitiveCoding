//
//  main.cpp
//  Anagrams Hashing
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    
    vector<vector<int> > ans;
    unordered_map<string, vector<int>> mp;
    vector<string> v;
    
    for(string i : A){
        sort(i.begin(), i.end());
        v.push_back(i);
    }
    
    for(int i = 0; i < v.size(); i++){
        mp[v[i]].push_back(i+1);
    }
    
    for(auto i : mp)
        ans.push_back(i.second);
        
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<string> x = {"cat", "dog", "god", "tca"};
    anagrams(x);
    return 0;
}

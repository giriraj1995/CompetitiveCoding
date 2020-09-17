//
//  main.cpp
//  Sparse Array
//
//  Created by Giriraj Saigal on 17/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> matchingStrings(vector<string> s, vector<string> q) {
    vector<int> ans;
    unordered_map<string, int> u;

    for(int i = 0; i < s.size() ; i++){
        if(u.find(s[i]) == u.end()){
            u.insert(make_pair(s[i], 1));
        }else{
            int x = u.find(s[i])->second;
            u.erase(u.find(s[i]));
            u.insert(make_pair(s[i], x+1));
        }
    }

    for(string i : q){
        if(u.find(i) != u.end()){
            ans.push_back(u.find(i)->second);
        }else
            ans.push_back(0);
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    matchingStrings({"aba","baba","aba",
        "xzxb"}, {"aba",
                    "xzxb",
            "ab"});
    return 0;
}

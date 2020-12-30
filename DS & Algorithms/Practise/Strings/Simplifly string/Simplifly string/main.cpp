//
//  main.cpp
//  Simplifly string
//
//  Created by Giriraj Saigal on 30/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

string solve(string A){
    vector<string> s;
    
    bool flag = false;
    string k = "";
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '/' && flag == false){
            flag = true;
        }else if(A[i] == '/' && flag == true){
            
            if(k.compare(".") == 0){
                k = "";
            }else if(k.compare("..") == 0) {
                if(s.size() > 0)
                    s.pop_back();
            }else{
                if(k.compare("") != 0)
                    s.push_back(k);
            }
            
            k = "";
        }else{
            k.push_back(A[i]);
        }
    }
    
    if(k.compare(".") == 0){
        k = "";
    }else if(k.compare("..") == 0) {
        if(s.size() > 0)
            s.pop_back();
    }else{
        if(k.compare("") != 0)
            s.push_back(k);
    }
    
    string ans = "/";
    
    if(s.size() > 0)
    {    for(int i = 0; i < s.size()-1; i++) {
            ans += s[i];
            ans += "/";
        }
    }
    
    if(s.size() > 0)
        ans += s[s.size()-1];
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve("/home//foo/");
    return 0;
}

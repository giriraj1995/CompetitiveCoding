//
//  main.cpp
//  Length of last word
//
//  Created by Giriraj Saigal on 25/02/21.
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

int lengthOfLastWord(const string A) {
    vector<string> v;
    string x = "";
    
    for(char c : A) {
        if(c == ' ' && x.compare("") != 0) {
            v.push_back(x);
            x = "";
        }else if(c != ' '){
            x += c;
        }
    }
        
    if(x.compare("") != 0) {
        return x.size();
    }
    
    if(v.size() == 0)
        return 0;
    
    return v[v.size()-1].size();
}

int main(int argc, const char * argv[]) {
    lengthOfLastWord("d");
    return 0;
}

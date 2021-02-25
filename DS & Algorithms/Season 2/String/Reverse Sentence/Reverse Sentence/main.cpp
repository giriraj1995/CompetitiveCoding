//
//  main.cpp
//  Reverse Sentence
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

string solve(string A) {
    string x = "";
    vector<string> v;
    
    for(char c : A)
    {
        if(c == ' ' && x.compare("") != 0) {
            v.push_back(x);
            x = "";
        }else if(c != ' ') {
            x += c;
        }
        
    }
    
    if(x.compare("") != 0) {
        v.push_back(x);
    }
    
    string y = "";
    
    for(int i = v.size()-1; i >= 0; i--) {
        if(i != 0){
            y += v[i] + " ";
            continue;
        }
        
        y += v[i];
    }
    
    return y;
}

int main(int argc, const char * argv[]) {
    cout<<solve("this is ib");
    return 0;
}

//
//  main.cpp
//  Count and say
//
//  Created by Giriraj Saigal on 07/04/21.
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

string countAndSay(int n) {
    //count & say
    string x = "1";
    
    if(n == 1)
        return "1";
    
    while(--n) {
        string k = "";
        char prev = x[0];
        int count = 1;
        
        for(int i = 1; i < x.size(); i++) {
            if(x[i] == prev) {
                count++;
            }else{
                k = k + to_string(count) + (prev);
                prev = x[i];
                count = 1;
            }
        }
        
        k = k + to_string(count) + prev;
        x = k;
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    cout<<countAndSay(56)<<endl;
    return 0;
}

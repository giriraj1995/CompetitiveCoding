//
//  main.cpp
//  Power of 2
//
//  Created by Giriraj Saigal on 14/01/21.
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

int solve(string A) {
        
    if(A.compare("0") == 0)
        return 0;
        
    if(A.compare("2") == 0)
        return 1;
    
    string divv = "";
    int rem = 0;
    
    for(char c : A) {
        int ele = c - '0';
        ele = rem * 10 + ele;
        int d = ele/2;
        rem = ele % 2;
        
        if(d != 0)
            divv += to_string(d);
    }
    
    if(rem > 0) {
        return 0;
    }else{
        return solve(divv);
    }
}

int power(string A) {
    
    if(A.size() == 0)
        return 0;
        
    return solve(A);
}


int main(int argc, const char * argv[]) {
    cout<<power("147573952589676412928");
    return 0;
}

//
//  main.cpp
//  check palindrom
//
//  Created by Giriraj Saigal on 18/12/20.
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

int solve(string A) {
    
    map<char, int> mp;
    
    int flag = 0;
    
    for(char i : A)
        mp[i]++;
        
    for(auto i : mp){
        if(i.second & 1 && flag == 0) {
            flag = 1;
        }else if(i.second & 1 && flag == 1){
            return 0;
        }
    }
    
    return 1;
}


int main(int argc, const char * argv[]) {

    return 0;
}

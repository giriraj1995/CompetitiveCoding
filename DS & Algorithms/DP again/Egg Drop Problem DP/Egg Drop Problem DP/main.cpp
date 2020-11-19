//
//  main.cpp
//  Egg Drop Problem DP
//
//  Created by Giriraj Saigal on 19/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int solve(int floors, int eggs) {
    
    if(eggs == 1){
        return floors;
    }
    
    if(floors == 0 || floors == 1){
        return floors;
    }
    
    int ans = INT_MAX;
    
    for(int x = 1 ; x <= floors; x++) {
        
        ans = min(ans, 1 + max(solve(x-1, eggs-1), solve(floors - x, eggs)));
        
    }
    
    return ans;
    
}
int main(int argc, const char * argv[]) {
    int floors = 9;
    int eggs = 3;
    return 0;
}

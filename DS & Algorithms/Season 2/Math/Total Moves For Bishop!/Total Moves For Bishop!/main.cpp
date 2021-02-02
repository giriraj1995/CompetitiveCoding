//
//  main.cpp
//  Total Moves For Bishop!
//
//  Created by Giriraj Saigal on 02/02/21.
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

int solve(int A, int B) {
    
    int ans = 0;
    
    int x = A + 1;
    int y = B + 1;
    
    while(x <= 8 && y <= 8) {
        ans++;
        x++;
        y++;
    }
    
    x = A - 1;
    y = B + 1;
    
    while(x >= 1 && y <= 8) {
        ans++;
        x--;
        y++;
    }
    
    x = A + 1;
    y = B - 1;
    
    while(x <= 8 && y >= 1) {
        ans++;
        x++;
        y--;
    }
    
    x = A - 1;
    y = B - 1;
    
    while(x >= 1 && y >= 1) {
        ans++;
        x--;
        y--;
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

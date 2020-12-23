//
//  main.cpp
//  Min steps in Infinite Grid
//
//  Created by Giriraj Saigal on 23/12/20.
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

int coverPoints(vector<int> &A, vector<int> &B) {
    
    int steps = 0;
    
    if(A.size() == 0)
        return 0;
        
    int x = A[0];
    int y = B[0];
    
    for(int i = 1; i < A.size(); i++) {
        
        int xd = A[i];
        int yd = B[i];
        
        int dx = abs(xd - x);
        int dy = abs(yd - y);
        
        steps += min(dx, dy);
        steps += abs(dx - dy);
        
        x = A[i];
        y = B[i];
    }
    
    return steps;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

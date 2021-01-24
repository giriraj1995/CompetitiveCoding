//
//  main.cpp
//  Min Steps in Infinite Grid
//
//  Created by Giriraj Saigal on 24/01/21.
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

int coverPoints(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    
    if(n <= 1)
        return 0;
        
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int x = A[i];
        int y = B[i];
        
        int dx = abs(x - A[i-1]);
        int dy = abs(y - B[i-1]);
        
        ans += min(dx, dy);
        ans += abs(dx - dy);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    return 0;
}

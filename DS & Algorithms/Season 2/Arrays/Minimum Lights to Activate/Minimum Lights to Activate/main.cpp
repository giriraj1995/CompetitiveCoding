//
//  main.cpp
//  Minimum Lights to Activate
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

int solve(vector<int> A, int B) {
    int n = (int)A.size();
    int ind = 0;
    int ans = 0;
    
    while(ind < n) {
        int r = ind + B - 1;
        if(r >= n) {
            r = n-1;
        }
        
        while(r >= 0 && A[r] == 0 && r >= (ind - B + 1)) {
            r--;
        }
        
        if(r == -1 || r < (ind - B + 1)) {
            return -1;
        }
        
        ans++;
        ind = r + B;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({0, 0, 1, 1, 1, 0, 0, 1}, 3);
    return 0;
}

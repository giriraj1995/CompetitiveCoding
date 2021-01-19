//
//  main.cpp
//  Min jumps Linear
//
//  Created by Giriraj Saigal on 19/01/21.
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

int jumps(vector<int> arr) {
    int n = arr.size();
    int maxReach = 0;
    int stop = 0;
    int jumps = 0;
    for(int i = 0; i < n-1; i++) {
        maxReach = max(maxReach, i + arr[i]);
        
        if(i == stop) {
            jumps++;
            stop = maxReach;
        }
        
        if(stop >= n-1) {
            break;
        }
    }
    
    if(stop < n-1) return -1;
    return jumps;
    
}

int main(int argc, const char * argv[]) {
    cout<<jumps({1 ,3, 5, 8, 9, 2, 6, 7, 6, 8, 9})<<endl;
    return 0;
}

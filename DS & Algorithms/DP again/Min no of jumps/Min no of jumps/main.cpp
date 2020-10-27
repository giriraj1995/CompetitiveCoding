//
//  main.cpp
//  Min no of jumps
//
//  Created by Giriraj Saigal on 27/10/20.
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

int jump(vector<int> A) {
    
     int jumps = 0, current_range = 0, next_range = 0;
    
    for(int i = 0; i <= current_range; i++) {
        if(i == A.size() - 1) {
            return jumps;
        }
        
        next_range = max(next_range, A[i] + i);
        
        if(i == current_range) {
            jumps++;
            current_range = next_range;
        }
    }
    return -1;
    
}

int main(int argc, const char * argv[]) {
    cout<<jump({2,3,1,1,4})<<endl;
    return 0;
}

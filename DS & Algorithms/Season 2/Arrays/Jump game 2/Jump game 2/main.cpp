//
//  main.cpp
//  Jump game 2
//
//  Created by Giriraj Saigal on 24/04/21.
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

int jump(vector<int> nums) {
    
    if(nums.size() <= 1)
        return 0;
    
    int jumps = 0;
    int till = nums[0];
    int next_max = nums[0];
    
    if(nums.size()-1 <= next_max)
        return 1;
    
    for(int i = 0; i < nums.size(); i++) {
        next_max = max(next_max, i+nums[i]);
        if(till == i) {
            jumps++;
            till = next_max;
            
            if(i == nums.size()-1)
                return jumps;
            
            if(till >= nums.size()-1)
                return jumps+1;
        }
    }
    
    return jumps;
}

int main(int argc, const char * argv[]) {
    cout<<jump({2,1});
    return 0;
}

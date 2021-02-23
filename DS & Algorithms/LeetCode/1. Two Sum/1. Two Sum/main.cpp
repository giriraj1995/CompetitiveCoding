//
//  main.cpp
//  1. Two Sum
//
//  Created by Giriraj Saigal on 23/02/21.
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

vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++) {
        
        if(map.find(target-nums[i]) != map.end()) {
            return {map[target-nums[i]], i};
        }
        
        map[nums[i]] = i;
    }
    
    return {};
}

int main(int argc, const char * argv[]) {
    twoSum({3,2,4},6);
    return 0;
}

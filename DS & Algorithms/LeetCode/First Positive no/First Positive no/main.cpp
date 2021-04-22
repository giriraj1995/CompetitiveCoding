//
//  main.cpp
//  First Positive no
//
//  Created by Giriraj Saigal on 21/04/21.
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

int firstMissingPositive(vector<int> nums) {
    int n = nums.size();
    bool isone = false;
    if(n == 0)
        return 1;
    if(n == 1) {
        if(nums[0] == 1)
            return 2;
        else
            return 1;
    }
    for(int i = 0; i < n; i++) {
        if(nums[i] == 1)
            isone = true;
    }
    
    if(!isone)
        return 1;
    
     for(int i = 0; i < n; i++) {
        if(nums[i] <= 0 || nums[i] > n)
            nums[i] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        if(abs(nums[i]) == n){
            nums[0] = -1 * abs(nums[0]);
        }else{
            nums[abs(nums[i])] = -1 * abs(nums[abs(nums[i])]);
        }
    }
    
    for(int i = 1; i < n; i++) {
        if(nums[i] > 0)
            return i;
    }
    
    if(nums[0] > 0)
        return n;
    
    return n+1;
}

int main(int argc, const char * argv[]) {
    cout<<firstMissingPositive({1,2,3,4,5,6,7,8,9,10,11,12,23,20});
    return 0;
}

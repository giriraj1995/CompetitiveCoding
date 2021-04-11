//
//  main.cpp
//  kanedes algo
//
//  Created by Giriraj Saigal on 09/04/21.
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

int maxSubArray(vector<int> nums) {
    int sum = nums[0];
    int m = nums[0];
    int maxsumsofar = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        if(sum + nums[i] >= nums[i]) {
            sum += nums[i];
        }else{
            sum = nums[i];
        }
        
        maxsumsofar = max(maxsumsofar, sum);
    }
    
    return maxsumsofar;
}

double myPow(double x, int n) {
    if(n == 0)
        return 1;
    
    if(n == 1)
        return x;
    
    if(x == 1)
        return x;
    
    if(x == -1)
        return n % 2 == 0 ? 1 : -1;
    
    bool neg = false;
    if(n < 0) {
        neg = true;
        n = abs(n);
    }
    
    double t = x;
    
    long long power = 1;
    
    while(power*2 < n) {
        x = x*x;
        power = power * 2;
    }
    
    while(power < n) {
        x = x*t;
        power = power+1;
    }
    
    if(neg) {
        return (double)(1/x);
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    //maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    myPow(0.00001, 2147483647);
    return 0;
}

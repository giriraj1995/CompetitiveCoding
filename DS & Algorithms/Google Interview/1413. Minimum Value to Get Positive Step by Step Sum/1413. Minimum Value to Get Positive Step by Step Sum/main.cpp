//
//  main.cpp
//  1413. Minimum Value to Get Positive Step by Step Sum
//
//  Created by Giriraj Saigal on 11/11/21.
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

int minStartValue(vector<int> nums) {
    int sum = 0;
    int ans = INT_MAX;
    
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        ans = min(ans, sum);
    }
    
    if(ans > 0)
        return 1;
    
    return abs(ans)+1;
}

int main(int argc, const char * argv[]) {
    cout << minStartValue({1,-23,43,55,-100,-2,-9,34}) << endl;
    return 0;
}

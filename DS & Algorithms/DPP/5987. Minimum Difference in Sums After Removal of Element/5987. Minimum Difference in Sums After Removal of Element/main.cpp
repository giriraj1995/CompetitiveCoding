//
//  main.cpp
//  5987. Minimum Difference in Sums After Removal of Element
//
//  Created by Giriraj Saigal on 05/02/22.
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

int solve(long long i, long long sum1, long long t, long long n, vector<int> &nums) {
    if(i == nums.size()) {
        return sum1 - (t-sum1);
    }
    
    if(n == 0) {
        //not remove
        return solve(i+1, sum1+nums[i], t, n, nums);
    }
    
    // remove
    int x = solve(i+1, sum1, t-nums[i], n-1, nums);
    
    //not remove
    int y = solve(i+1, sum1+nums[i], t, n, nums);
    
    return min(x,y);
}

long long minimumDifference(vector<int> nums) {
    long long sum = 0;
    for(int i : nums)
        sum += i;
    
    long long n = nums.size();
    return solve(0, 0, sum, n/3, nums);
}

int main(int argc, const char * argv[]) {
    minimumDifference({7,9,5,8,1,3});
    return 0;
}

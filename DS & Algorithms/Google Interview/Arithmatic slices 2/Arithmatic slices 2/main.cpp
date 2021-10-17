//
//  main.cpp
//  Arithmatic slices 2
//
//  Created by Giriraj Saigal on 15/10/21.
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

int numberOfArithmeticSlices(vector<int> nums) {
        int n = nums.size();
        
        if(n <= 2)
            return 0;
        
        int ans = 0;
        map<pair<int, long long>, int> dp;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long d = nums[i] - nums[j];
                ans += dp[{j,d}];
                dp[{i,d}] += dp[{j,d}]+1;
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    numberOfArithmeticSlices({2,4,6,8,10});
    return 0;
}

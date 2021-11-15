//
//  main.cpp
//  368. Largest Divisible Subset
//
//  Created by Giriraj Saigal on 15/11/21.
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

vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n);
    
        for(int i = 0; i < n; i++) {
            dp[i] = {};
            dp[i].push_back(nums[i]);
        }
        
        int len = 0;
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                int next = nums[i];
                int last = nums[j];
                
                if(next % last == 0 && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(next);
                }
                
                if(dp[i].size() > len) {
                    ans = dp[i];
                    len = dp[i].size();
                }
            }
        }
        
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    largestDivisibleSubset({1,2,4,8});
    return 0;
}

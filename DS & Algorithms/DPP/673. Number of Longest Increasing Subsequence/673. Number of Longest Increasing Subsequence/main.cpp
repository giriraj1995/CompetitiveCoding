//
//  main.cpp
//  673. Number of Longest Increasing Subsequence
//
//  Created by Giriraj Saigal on 20/02/22.
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

int findNumberOfLIS(vector<int> nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n, {1,1});
        int maxLen = 1;
        int maxCount = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
               if(nums[j] < nums[i] && dp[i].first <= dp[j].first+1) {
                   dp[i].first = dp[j].first+1;
                   if(dp[i].first > maxLen){
                       maxLen = dp[i].first;
                       dp[i].second = dp[j].second;
                       maxCount = dp[i].second;
                   }else if(dp[i].first == maxLen){
                       dp[i].second += 1;
                       maxCount = dp[i].second;
                   }
               }
            }
        }
        
        return maxLen == 1 ? nums.size() : maxCount;
    }

int main(int argc, const char * argv[]) {
    findNumberOfLIS({1,3,5,4,7,10,12,13,14,15,16,20,22,100,234,2,3,4,52,3,42,1000});
    return 0;
}

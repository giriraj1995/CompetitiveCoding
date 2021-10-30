//
//  main.cpp
//  673. Number of Longest Increasing Subsequence
//
//  Created by Giriraj Saigal on 30/10/21.
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
    int n = (int)nums.size();
    vector<int> lcs(n, 1);
    vector<int> count(n, 1);
    int max_len = 0;
    int max_count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            //if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
            //if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
            if(lcs[j]+1 == lcs[i] && nums[j] < nums[i]) {
                count[i] += count[j];
            }else
            if(lcs[j]+1 > lcs[i] && nums[j] < nums[i]) {
                lcs[i] = lcs[j]+1;
                count[i] = count[j];
            }
        }
        
        if(lcs[i] == max_len) {
            max_count += count[i];
        }
        
        if(lcs[i] > max_len) {
            max_len = lcs[i];
            max_count = count[i];
        }
    }

    return max_count;
}

int findNumberOfLIS2(vector<int> nums) {
        int n = nums.size(), res = 0, max_len = 0;
        vector<pair<int,int>> dp(n,{1,1});            //dp[i]: {length, number of LIS which ends with nums[i]}
        for(int i = 0; i<n; i++){
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            
            if(max_len == dp[i].first)
                res += dp[i].second;
            
            if(max_len < dp[i].first){
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
int main(int argc, const char * argv[]) {
    cout << findNumberOfLIS({1,2,4,3,5,4,7,2}) << endl;
    return 0;
}

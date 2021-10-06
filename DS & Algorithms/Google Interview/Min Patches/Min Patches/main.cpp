//
//  main.cpp
//  Min Patches
//
//  Created by Giriraj Saigal on 06/10/21.
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

int minPatches(vector<int> nums, int n) {
        int k = (int)nums.size();
        vector<vector<bool>> dp(k+1, vector<bool>(n+1, false));
        
        for(int i = 0; i <= k; i++) {
            dp[i][0] = true;
        }
        
        vector<int> lastcheck;
        
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
                if(i == k && !dp[i][j]){
                    lastcheck.push_back(j);
                }
            }
        }
        
        int ans = 0;
        int i = k;
        
        while(lastcheck.size() != 0) {
            
            dp.push_back(vector<bool>(n, true));
            nums.push_back(lastcheck[0]);
            i++;
            int temp = lastcheck[0];
            lastcheck = {};
            ans++;
            
            for(int j = temp; j <= n; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
                if(!dp[i][j]){
                    lastcheck.push_back(j);
                }
            }
        }
        
        return ans;
    }

int minPatches1(vector<int> nums, int n) {
    int cost = 0;
                long long upper = 0;
                int i = 0;
                int k = nums.size();

                while(upper < n) {
                    if(i < k && nums[i] <= upper+1){
                        upper += nums[i];
                        i++;
                    }else{
                        upper += upper+1;
                        cost++;
                    }
                }

                return cost;
}
int main(int argc, const char * argv[]) {
    minPatches1({10},20);
    return 0;
}

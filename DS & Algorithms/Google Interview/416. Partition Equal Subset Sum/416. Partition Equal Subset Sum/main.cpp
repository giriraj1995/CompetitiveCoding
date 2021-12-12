//
//  main.cpp
//  416. Partition Equal Subset Sum
//
//  Created by Giriraj Saigal on 12/12/21.
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

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum += i;
        
        if(sum % 2 != 0)
            return false;
        
        sum = sum/2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        
        for(int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= sum; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size()][sum];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

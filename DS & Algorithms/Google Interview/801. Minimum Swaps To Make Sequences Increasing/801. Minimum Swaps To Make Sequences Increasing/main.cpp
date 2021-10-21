//
//  main.cpp
//  801. Minimum Swaps To Make Sequences Increasing
//
//  Created by Giriraj Saigal on 19/10/21.
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

unordered_map<string, int> dp;
    int solve(bool swaped, int i, vector<int>& nums1, vector<int>& nums2) {
        string key = to_string(swaped) + "|" + to_string(i);
        
        if(i == nums1.size())
            return 0;
        
        if(dp.count(key))
            return dp[key];
        
        if(i == 0) {
            //swap
            int x = 1 + solve(true,i+1,nums1,nums2);
            //notswap
            int y = solve(false,i+1,nums1,nums2);
            
            return dp[key] = min(x,y);
        }else{
            int x1,x2;
            
            if(swaped) {
                x1 = nums2[i];
                x2 = nums1[i];
            }else{
                x1 = nums1[i];
                x2 = nums2[i];
            }
            
            if(nums1[i] > x1 && nums2[i] > x2 && nums1[i] > x2 && nums2[i] > x1){
                //swap
                int x = 1 + solve(true,i+1,nums1,nums2);
                //notswap
                int y = solve(false,i+1,nums1,nums2);
                
                return dp[key] = min(x,y);
            }else if(nums1[i] > x2 && nums2[i] > x1) {
                //swap
                int x = 1 + solve(true,i+1,nums1,nums2);
                return dp[key] = x;
            }else if(nums1[i] > x1 && nums2[i] > x2) {
                //not swap
                int y = solve(false,i+1,nums1,nums2);
                return dp[key] = y;
            }else{
                return dp[key] = 0;
            }
        }
    }
    int minSwap(vector<int> nums1, vector<int> nums2) {
        dp.clear();
        return solve(false,0,nums1,nums2);
    }

int main(int argc, const char * argv[]) {
    cout << minSwap({0,3,5,8,9},
                    {2,1,4,6,9}) << endl;
    return 0;
}

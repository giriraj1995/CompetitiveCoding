//
//  main.cpp
//  2025. Maximum Number of Ways to Partition an Array
//
//  Created by Giriraj Saigal on 08/10/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <numeric>
using namespace std;

    int waysToPartition(vector<int>nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int ans = 0;
        int sumleft = nums[0];

        //evaluate with no change first
        for(int i = 1; i < n; i++) {
            int sumright = sum-sumleft;
            if(sumleft == sumright)
                ans++;
            sumleft += nums[i];
        }
        
        // -nums[i] + k
        // sum1 != sum2
        // some difference
        
        //from left
        map<int,vector<int>> mp;
        mp[k-nums[0]].push_back(0);
        sumleft = nums[0];
        
        for(int i = 1; i < n; i++) {
            int sumright = sum-sumleft;
            if(sumleft != sumright) {
                int d = sumleft - sumright;
                d = -d;
                if(mp.count(d))
                    ans += mp[d].size();
            }
            sumleft+=nums[i];
            mp[k-nums[i]].push_back(i);
        }
        
        mp.clear();
        int sumright = 0;
        
        for(int i = n-1; i > 0; i--) {
            sumright += nums[i];
            sumleft = sum-sumright;
            mp[k-nums[i]].push_back(i);

            if(sumleft != sumright) {
                int d = sumright - sumleft;
                d = -d;
                if(mp.count(d))
                    ans += mp[d].size();
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    waysToPartition({2,-1,2},3);
    return 0;
}

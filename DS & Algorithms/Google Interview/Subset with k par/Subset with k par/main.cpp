//
//  main.cpp
//  Subset with k par
//
//  Created by Giriraj Saigal on 01/10/21.
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

bool check(vector<int> par, int tot) {
        for(int i : par)
            if(i != tot)
                return false;
        
        return true;
    }
    
    bool solve(int i, vector<int> &nums, vector<int> par, int tot) {
        if(i == nums.size()){
            if(check(par, tot))
                return true;
            else
                return false;
        }
        
        if(nums[i] > tot)
            return false;
        
        
        for(int k = 0; k < par.size(); k++) {
            if(par[k]+nums[i] <= tot) {
                par[k] += nums[i];
                if(solve(i+1,nums,par,tot))
                    return true;
                par[k] -= nums[i];
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int> nums, int k) {
        int sum = 0;
        
        for(int i : nums){
            sum += i;
        }
        
        if(sum % k != 0)
            return false;
        
        vector<int> par(k, 0);
        return solve(0, nums, par, sum/k);
    }

int main(int argc, const char * argv[]) {
    cout << canPartitionKSubsets({1,1,1,1,2,2,2,2},4) << endl;
    return 0;
}

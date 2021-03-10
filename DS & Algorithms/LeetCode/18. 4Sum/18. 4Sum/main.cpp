//
//  main.cpp
//  18. 4Sum
//
//  Created by Giriraj Saigal on 10/03/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

vector<vector<int>> fourSum(vector<int> nums, int target) {
    int n = nums.size();
    
    if(n < 4) {
        return {};
    }
    
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    
    for(int i = 0; i < nums.size()-3; i++) {
        for(int j = i+1; j < nums.size()-2; j++) {
            int low = j+1;
            int high = n-1;
            while(low < high) {
                int x = nums[low] + nums[high] + nums[i] + nums[j];
                if(x == target) {
                    s.insert({nums[i], nums[j], nums[low], nums[high]});
                    high--;
                }else if(x < target) {
                    low++;
                }else{
                    high--;
                }
            }
        }
    }
    
    vector<vector<int>> ans;
    
    for(auto k : s) {
        ans.push_back(k);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    fourSum({1,0,-1,0,-2,2}, 0);
    return 0;
}

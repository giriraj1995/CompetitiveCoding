//
//  main.cpp
//  Max Product sum
//
//  Created by Giriraj Saigal on 03/09/21.
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

int maxProduct(vector<int> nums) {
    int ans = nums[0];
    
    for(int i = 0; i < nums.size(); i++){
        ans = max(ans, nums[i]);
    }
    
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        
        if(nums[i] == 0){
            min_so_far = 1;
            max_so_far = 1;
            continue;
        }
        
        min_so_far = min(nums[i], min(nums[i]*min_so_far,nums[i]*max_so_far));
        max_so_far = max(nums[i], max(nums[i]*min_so_far,nums[i]*max_so_far));
        ans = max(ans, max_so_far);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << maxProduct({2,3,-2,4});
    return 0;
}

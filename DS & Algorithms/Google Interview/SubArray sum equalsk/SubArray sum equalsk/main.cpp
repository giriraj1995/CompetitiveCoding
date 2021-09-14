//
//  main.cpp
//  SubArray sum equalsk
//
//  Created by Giriraj Saigal on 14/09/21.
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

int subarraySum(vector<int> nums, int k) {
    int n = (int)nums.size();
    
    int ans = 0;
    int sum = 0;
    map<int, int> mp;
    mp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        
        if(mp.find(sum-k) != mp.end()){
            ans += mp[sum-k];
        }
        
        mp[sum] = mp[sum] + 1;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << subarraySum({1,2,3}, 3) << endl;
    return 0;
}

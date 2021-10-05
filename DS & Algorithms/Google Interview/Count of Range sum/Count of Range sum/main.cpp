//
//  main.cpp
//  Count of Range sum
//
//  Created by Giriraj Saigal on 05/10/21.
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

int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> s;
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        if(n == 1){
            if(nums[0] <= upper && nums[0] >= lower)
                return 1;
            else
                return 0;
        }
        
        long long sum = 0;
        s.insert(sum);
        int ans = 0;
        
        for(int k : nums) {
            sum += k;
            cout<<*(s.lower_bound(sum-upper))<<*(s.upper_bound(sum-lower))<<endl;
            ans += distance(s.lower_bound(sum-upper),s.upper_bound(sum-upper));
            s.insert(sum);
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<int> x={-2,5,-1};
    cout << countRangeSum(x,-2,2) << endl;
    return 0;
}

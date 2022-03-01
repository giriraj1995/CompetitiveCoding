//
//  main.cpp
//  228. Summary Ranges
//
//  Created by Giriraj Saigal on 01/03/22.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size() == 0)
            return {};
        
        if(nums.size() == 1)
            return {to_string(nums[0])};
        
        int prev = nums[0];
        vector<string> ans;
        string cur = to_string(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == prev+1) {
                prev = nums[i];
                continue;
            }else{
                if(cur.compare(to_string(prev)) != 0)
                    cur += "->" + to_string(prev);
                ans.push_back(cur);
                prev = nums[i];
                cur = to_string(nums[i]);
            }
        }
        
        if(cur.compare(to_string(prev)) != 0)
            cur += "->" + to_string(prev);
        ans.push_back(cur);
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

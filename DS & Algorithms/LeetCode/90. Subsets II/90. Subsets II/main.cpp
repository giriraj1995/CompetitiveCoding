//
//  main.cpp
//  90. Subsets II
//
//  Created by Giriraj Saigal on 06/06/21.
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


void solve(set<vector<int>> &s, vector<int> inp, vector<int> nums, int i) {
    if(i == nums.size())
    {
        s.insert(inp);
        return;
    }
    
    for(int k = i; k < nums.size(); k++) {
        inp.push_back(nums[k]);
        solve(s,inp,nums,k+1);
        inp.pop_back();
        solve(s,inp,nums,k+1);
    }
}
vector<vector<int>> subsetsWithDup(vector<int> nums) {
    set<vector<int>> s;
    vector<int> inp;
    vector<vector<int>> ans;
    
    solve(s,inp,nums,0);
    
    for(auto k : s){
        ans.push_back(k);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    subsetsWithDup({1,2,2});
    return 0;
}

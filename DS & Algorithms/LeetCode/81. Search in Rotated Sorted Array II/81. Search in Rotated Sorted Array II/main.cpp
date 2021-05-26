//
//  main.cpp
//  81. Search in Rotated Sorted Array II
//
//  Created by Giriraj Saigal on 26/05/21.
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


int minInd(vector<int>& nums) {
    int i = 0;
    int j = (int)nums.size()-1;
    int res = -1;
    int st = i;
    int ed = j;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(m > st && m < ed) {
            if(nums[m] <= nums[m+1] && nums[m] < nums[m-1]) {
                res = m;
                i = m+1;
            }else if(nums[m] >= nums[st]){
                i = m+1;
            }else{
                j = m-1;
            }
        }else if(m == st){
            if(nums[m] <= nums[m+1])
                res = m;
            
            i = m+1;
        }else if(m == ed){
            if(nums[m] < nums[m-1])
                res = m;
            
            i = m+1;
        }
    }
    
    return res;
}

bool search(vector<int>& nums, int i, int j, int t) {
    while(i <= j) {
        int m = i + (j-i)/2;
        if(nums[m] == t)
            return true;
        else if(t < nums[m]){
            j = m-1;
        }else if(t > nums[m]){
            i = m+1;
        }
    }
    return false;
}

bool search(vector<int> nums, int target) {
    if(nums.size() == 0){
        return false;
    }
    if(nums.size() == 1){
        return nums[0] == target;
    }
    int ind = minInd(nums);
    bool x = search(nums, 0, ind-1, target);
    bool y = search(nums, ind, (int)nums.size()-1, target);
    return x||y;
}

int main(int argc, const char * argv[]) {
    int fl = 7;
    int ce = 7;
    
    vector<vector<char>> vec(fl, vector<char>(ce,'.'));

    vector<int> x = {2,2,2,3,2,2,2};
    cout<<search(x,3)<<endl;
    return 0;
}

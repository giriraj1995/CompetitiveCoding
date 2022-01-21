#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        
        if(i == j)
            return nums[0];
        
        while(i < j) {
            int m = i + (j-i)/2;
            
            if(nums[m] > nums[nums.size()-1]){
                i = m+1;
            }else{
                j = m;
            }
            
        }
        
        return nums[i];
    }
};

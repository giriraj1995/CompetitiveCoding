//
//  main.cpp
//  540. Single Element in a Sorted Array
//
//  Created by Giriraj Saigal on 20/11/21.
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

int singleNonDuplicate(vector<int> nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int res = -1;
        int i = 0;
        int j = nums.size()-1;
        
        while(i <= j) {
            int m = i + (j-i)/2;
            
            if(m % 2 == 0) {
                if(m != nums.size()-1 && nums[m] == nums[m+1]){
                    i = m+1;
                }else{
                    j = m-1;
                    res = nums[m];
                }
            }else{
                if(nums[m] == nums[m-1])
                    i = m+1;
                else{
                    j = m-1;
                    res = nums[m];
                }
            }
        }
        
        return res;
    }
int main(int argc, const char * argv[]) {
    cout << singleNonDuplicate({1,1,2}) << endl;
    return 0;
}

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

int solve(vector<int> x, int i, int j) {
    if(i > j)
        return -1;
    
    int m = i + (j-i)/2;
    
    if(m > 0 && m < x.size()-1) {
        if(x[m] == x[m-1] || x[m+1] == x[m]){
            int r = solve(x, m+1, j);
            
            if(r!=-1)
                return r;
            
            int l = solve(x, i, m-1);
            
            if(l!=-1)
                return l;
            
            return -1;
        }else{
            return x[m];
        }
    }else{
        if(m == 0) {
            if(x[m] == x[m+1])
                return solve(x, m+1, j);
            else
                return x[m];
        }else{
            if(x[m-1] == x[m])
                return solve(x, i, m-1);
            else
                return x[m];
        }
    }
    
    return -1;
}
int singleNonDuplicate(vector<int> nums) {
    int n = nums.size();
    if(n == 1)
        return nums[0];
    
    int i = 0;
    int j = nums.size()-1;

    return solve(nums, i, j);
}

int main(int argc, const char * argv[]) {
    cout << singleNonDuplicate({1,1,2}) << endl;
    return 0;
}

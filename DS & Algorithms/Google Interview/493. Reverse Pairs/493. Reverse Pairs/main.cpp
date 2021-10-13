//
//  main.cpp
//  493. Reverse Pairs
//
//  Created by Giriraj Saigal on 13/10/21.
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

int merge(int i, int m, int j, vector<int>&nums) {
        int l = i;
        int h = m+1;
        int ans = 0;
        
        vector<int> temp;
        int k = 0;
        
        int q = h;
        for(int d = l; d <= m; d++) {
            while(q <= j && nums[d] > nums[q]*2) {
                q++;
            }
            ans += q-h;
        }
    
        while(l <= m && h <= j) {
            if(nums[l] < nums[h]) {
                temp.push_back(nums[l]);
                l++;
                k++;
            }else{
                temp.push_back(nums[h]);
                h++;
                k++;
            }
        }
        
        while(l <= m) {
            temp.push_back(nums[l]);
            l++;
            k++;
        }
        
        while(h <= j) {
            temp.push_back(nums[h]);
            h++;
            k++;
        }
        
        for(int g = 0; g < k; g++) {
            nums[i+g] = temp[g];
        }
        
        return ans;
    }
    
    int mergeSort(int i, int j, vector<int>&nums) {
        if(i >= j)
            return 0;
        
        int ans = 0;
        int m = i + (j-i)/2;
        ans += mergeSort(i,m,nums);
        ans += mergeSort(m+1,j,nums);
        ans += merge(i,m,j,nums);
        
        return ans;
    }
    
    int reversePairs(vector<int> nums) {
        int n = nums.size();
        int ans = 0;
        ans = mergeSort(0, nums.size()-1, nums);
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << reversePairs({1,3,2,3,1}) << endl;
    return 0;
}

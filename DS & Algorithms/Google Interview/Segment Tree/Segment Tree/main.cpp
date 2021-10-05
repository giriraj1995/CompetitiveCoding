//
//  main.cpp
//  Segment Tree
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

class NumArray {
public:
    vector<int> seg;
    vector<int> x;
    
    int build(int ind, int low, int high) {
        if(low == high){
            seg[ind] = x[low];
            return seg[ind];
        }
        
        int m = low+(high-low)/2;
        seg[ind] = build(2*ind+1, low, m) + build(2*ind+2, m+1,high);
        return seg[ind];
    }
    
    bool updateTree(int ind, int idx, int val, int left, int right) {
        if(left == right && left == idx){
            seg[ind] = val;
            return true;
        }
        
        if(idx < left || idx > right)
            return false;
        
        int m = left + (right-left)/2;
        
        if(updateTree(2*ind+1, idx, val, left, m)
           || updateTree(2*ind+2, idx, val, m+1, right)){
            seg[ind] = seg[2*ind+1] + seg[2*ind+2];
            return true;
        }
        
        return false;
    }
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        x = nums;
        seg = vector<int>(n*4+1);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateTree(0, index, val, 0, x.size()-1);
    }
    
    int sumCal(int ind, int left, int right, int low, int high) {
        if(low >= left && high <= right){
            return seg[ind];
        }
        
        if(left > high || right < low){
            return 0;
        }
        
        int m = low + (high-low)/2;
        int p = sumCal(2*ind+1,left,right,low,m);
        int q = sumCal(2*ind+2,left,right,m+1,high);
        
        return p+q;
    }
    
    int sumRange(int left, int right) {
        return sumCal(0,left,right,0,x.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 3, 5,5,6,7,8,3};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(0,2);
    obj->update(1,2);
    int param_2 = obj->sumRange(0,2);
    return 0;
}

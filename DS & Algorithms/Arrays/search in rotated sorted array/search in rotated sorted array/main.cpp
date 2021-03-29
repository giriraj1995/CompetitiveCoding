//
//  main.cpp
//  search in rotated sorted array
//
//  Created by Giriraj Saigal on 29/03/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

int solve_min_no_BS(vector<int> &A, int n) {
    if(n == 0)
        return -1;
    
    if(n == 1)
        return 0;
    
    int res = -1;
    int i = 0;
    int j = n-1;
    int st = 0;
    int en = n-1;
    while(i <= j) {
        int m = i + (j-i)/2;
        if(m != st && m != en) {
            if(A[m] < A[m+1] && A[m] < A[m-1]) {
                return m;
            }else{
                if(A[m] > A[st]) {
                    i = m+1;
                }else if(A[m] < A[st]){
                    j = m-1;
                }
            }
        }else{
            if(m == st) {
                if(A[m] < A[m+1])
                    return st;
                else
                    break;
            }else{
                if(A[m] < A[m-1]){
                    return en;
                }
                else
                    break;
            }
        }
    }
        
    return res+1;
}
    
int search1(vector<int> x, int i, int j, int t) {
    while(i <= j) {
        int m = i + (j-i)/2;
        if(x[m] == t)
            return m;
        else if(t < x[m]) {
            j = m - 1;
        }else if(t > x[m]) {
            i = m + 1;
        }
    }
    
    return -1;
}
    
    int search(vector<int> nums, int target) {
        int m = solve_min_no_BS(nums, nums.size());
        int left = search1(nums, 0, m-, target);
        
        if(left != -1)
            return left;
        
        int right = search1(nums, m, nums.size()-1, target);
        
        if(right != -1)
            return right;
        
        return -1;
        
    }

int main(int argc, const char * argv[]) {
    search({3,1},1);
    return 0;
}

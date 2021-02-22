//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by Giriraj Saigal on 22/02/21.
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

int getmin(vector<int> x, int p){
    if(p == 0) {
        return INT_MIN;
    }else{
        return x[p-1];
    }
}

int getmax(vector<int> x, int p){
    if(p == x.size()){
        return INT_MAX;
    }else{
        return x[p];
    }
}

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    int n = (int)nums1.size();
    int m = (int)nums2.size();
    
    if(n > m) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int l = 0;
    int h = n;
    
    while(l <= h) {
        int partX = (l + h) / 2;
        int partY = ((m + n + 1) / 2) - partX;

        int leftx = getmin(nums1, partX);
        int rightx = getmax(nums1, partX);
        int lefty = getmin(nums2, partY);
        int righty = getmax(nums2, partY);

        if(leftx <= righty && lefty <= rightx) {
            if((n+m) % 2 == 0) {
                return (max(leftx,lefty) + min(rightx,righty)) / 2.0;
            }else{
                return max(leftx,lefty) * 1.0;
            }
        }

        if(leftx > righty) {
            h = partX - 1;
        }else{
            l = partX + 1;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    findMedianSortedArrays({1,3},{2});
    return 0;
}

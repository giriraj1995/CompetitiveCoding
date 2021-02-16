//
//  main.cpp
//  Median of Array
//
//  Created by Giriraj Saigal on 16/02/21.
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

double findMedianSortedArrays(const vector<int> nums1, const vector<int> nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n > m) return findMedianSortedArrays(nums2, nums1);
        
    int l = 0, h = n;
    
    while(l <= h)
    {
        int cut1 = (l + h) / 2;
        int cut2 = ((m + n) / 2) - cut1;
        
        
        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
        
        int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
        
        if(l1 > r2) h = cut1 - 1;
        else if(l2 > r1) l = cut1 + 1;
        else
        {
            if((m + n) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / (2.0);
            }
            else
            {
                return min(r1, r2) * 1.0;
            }
            break;
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    cout<<findMedianSortedArrays({1,4,5}, {2,3})<<endl;
    return 0;
}

//
//  main.cpp
//  Medium of a matrix
//
//  Created by Giriraj Saigal on 12/02/21.
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

int findMedian(vector<vector<int> > A) {
    int l = INT_MAX;
    int h = INT_MIN;
    int n = (int)A.size();
    int m = (int)A[0].size();
    
    for(auto k : A) {
        l = min(l, k[0]);
        h = max(h, k[m-1]);
    }
    
    int total = n*m;
    
    while(l <= h) {
        int m = l + (h-l)/2;
        int x = (total-1)/2;
        int count = 0;
        int low = INT_MAX;

        for(auto k : A) {
            for(auto ele : k) {
                if(ele < m) {
                    count++;
                }else{
                    low = min(low, ele);
                    break;
                }
            }
        }
        
        if(count == x) {
            return low;
        }else if(count > x) {
            h = m-1;
        }else if(count < x) {
            l = m+1;
        }
    }
    
    int count = 0;
    int low = INT_MAX;
    for(auto k : A) {
        for(auto ele : k) {
            if(ele < h) {
                count++;
            }else{
                low = min(low, ele);
                break;
            }
        }
    }
    
    return low;
}


int main(int argc, const char * argv[]) {
    cout<<findMedian({
        {1, 1, 1},{1,3,10},{10,10,10}});
    return 0;
}

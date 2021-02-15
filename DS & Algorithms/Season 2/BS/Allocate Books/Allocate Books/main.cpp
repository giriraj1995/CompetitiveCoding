//
//  main.cpp
//  Allocate Books
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

bool allocate(int x, vector<int> A, int B, long long &lowestSum) {
    long long sum = 0;
    int y = 1;
    int i;
    for(i = 0; i < A.size(); i++) {
        sum += A[i];
        if(sum > x) {
            y++;
            
            if(y > B) {
                return false;
            }
            
            lowestSum = max(lowestSum, sum-A[i]);
            sum = A[i];
            if(sum > x) {
                return false;
            }
        }
    }
    
    lowestSum = max(lowestSum, sum);
    
    return true;
}

int books(vector<int> A, int B) {
    long long high = 0;
    int low = INT_MAX;
    
    for(int i : A) {
        high += i;
        low = min(low, i);
    }
    
    long long lowestSum = INT_MIN;
    
    while(low <= high) {
        int m = low + (high-low)/2;
        if(allocate(m,A,B,lowestSum)) {
            high = m-1;
        }else{
            low = m+1;
        }
    }
    
    lowestSum = INT_MIN;
    if(allocate(high, A, B, lowestSum))
        return lowestSum;
    
    lowestSum = INT_MIN;
    if(allocate(low, A, B, lowestSum))
        return lowestSum;
    
    return -1;
}


int main(int argc, const char * argv[]) {
    cout<<books({31, 14, 19, 75},12);
    return 0;
}

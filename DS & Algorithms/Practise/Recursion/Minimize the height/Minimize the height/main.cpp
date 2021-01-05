//
//  main.cpp
//  Minimize the height
//
//  Created by Giriraj Saigal on 05/01/21.
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

void getMin(int i, int arr[], int n, int k, map<int, int> mp, int &ans) {
    
    ans = min((--mp.end())->first - mp.begin()->first, ans);
    
    if(i == n)
        return;
    
    mp[arr[i]]--;
    if(mp[arr[i]] == 0)
        mp.erase(arr[i]);
    
    if(arr[i] - k >= 0) {
        map<int, int> mp2 = mp;
        mp2[arr[i] - k]++;
        getMin(i+1, arr, n, k, mp2, ans);
    }
    
    if(arr[i] + k >= 0) {
        map<int, int> mp2 = mp;
        mp2[arr[i] + k]++;
        getMin(i+1, arr, n, k, mp2, ans);
    }
}

//int getMinDiff(int arr[], int n, int k) {
//    map<int, int> mp;
//
//    for(int i =0; i < n; i++) {
//        mp[arr[i]]++;
//    }
//
//    int ans = INT_MAX;
//
//    getMin(0, arr, n, k, mp, ans);
//
//    return ans;
//}

int getMinDiff(int arr[], int n, int k) {
    int low = INT_MAX;
    int high = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }
    
    if(high == low)
        return 0;
        
    int mid = low + (high - low)/2;
    
    int low1 = INT_MAX;
    int high1 = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] < mid) {
            arr[i] += k;
        }
        
        else
        if(arr[i] > mid) {
            arr[i] -= k;
        }
        
        low1 = min(low1, arr[i]);
        high1 = max(high1, arr[i]);
    }
    
    return high1 - low1;
}

int main(int argc, const char * argv[]) {
    int arr[] = {2,6,3,4,7,2,10,3,2,1};
    cout<<getMinDiff(arr, 10, 5);
    return 0;
}

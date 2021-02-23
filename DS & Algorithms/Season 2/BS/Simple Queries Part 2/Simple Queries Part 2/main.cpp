//
//  main.cpp
//  Simple Queries Part 2
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
#define mod 1000000007

int getdivisor(int x) {
    int ans = 1;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(x / i == i) {
                ans = (ans*i) % mod;
            }else{
                ans = (ans*i) % mod;
                ans = (ans*x/i) % mod;
            }
        }
    }
    
    return ans;
}

bool cmd(pair<int,long long> x, pair<int,long long> y) {
    return x.first > y.first;
}

vector<int> solve(vector<int> A, vector<int> B) {
    int n = (int)A.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    
    for(int i = 1; i < n; i++) {
        int prev = i-1;
        while(prev >= 0 && A[prev] <= A[i]) {
            left[i] += left[prev];
            prev -= left[prev];
        }
    }
    
    for(int i = n-2; i >= 0; i--) {
        int next = i+1;
        while(next < n && A[next] <= A[i]) {
            right[i] += right[next];
            next += right[next];
        }
    }
    
    vector<pair<int,long long>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back({getdivisor(A[i]), left[i] * right[i]});
    }
    
    sort(v.begin(), v.end(), cmd);
    
    vector<int> currFreq(n);
    currFreq[0] = v[0].second;
    
    for(int i = 1; i < A.size(); i++) {
        currFreq[i] = v[i].second + currFreq[i-1];
    }
    
    vector<int> ans;
    for(int i = 0; i < B.size(); i++) {
        auto id = lower_bound(currFreq.begin(), currFreq.end(), B[i]) - currFreq.begin();
        ans.push_back(v[id].first);
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    solve({39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45 }, {1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838});
    return 0;
}

//
//  main.cpp
//  Simple Queries Part 2
//
//  Created by Giriraj Saigal on 22/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>

int getdivisor(int x) {
    int ans = 1;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            if(x / i == i) {
                ans *= i;
            }else{
                ans *= i;
                ans *= x/i;
            }
        }
    }
    
    return ans;
}

bool cmd(pair<int,long long> x, pair<int,long long> y) {
    x.first > y.first;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
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
        int next = n+1;
        while(next < n && A[next] <= A[i]) {
            right[i] += right[next];
            next += right[next];
        }
    }
    
    vetor<pair<int,long long>> v;
    
    for(int i = 0; i < n; i++) {
        v.push_back(getdivisor(A[i]), left[i] * right[i]);
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
        ans.push_back(currFreq[ans].first);
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

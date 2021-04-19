//
//  main.cpp
//  Water Trapped
//
//  Created by Giriraj Saigal on 19/04/21.
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

vector<int> maxleft(vector<int> A) {
    vector<int> ans;
    ans.push_back(0);
    for(int i = 1; i < A.size(); i++) {
        if(A[i] > A[ans[i-1]])
            ans.push_back(i);
        else
            ans.push_back(ans[i-1]);
    }
    return ans;
}

vector<int> maxright(vector<int> A) {
    vector<int> ans(A.size());
    int n = A.size();
    ans[n-1] = n-1;
    for(int i = n-2; i >= 0; i--) {
        if(A[i] > A[ans[i+1]])
            ans[i] = i;
        else
            ans[i] = ans[i+1];
    }
    return ans;
}

int trap(const vector<int> A) {
    int n = A.size();
    if(n == 0)
        return 0;
    int ans = 0;
    
    vector<int> left = maxleft(A);
    vector<int> right = maxright(A);
    
    for(int i = 1; i < n-1; i++) {
        int height = min(A[left[i]], A[right[i]]);
        ans += (height-A[i]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    return 0;
}

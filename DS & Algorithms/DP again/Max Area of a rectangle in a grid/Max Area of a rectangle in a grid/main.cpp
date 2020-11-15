//
//  main.cpp
//  Max Area of a rectangle in a grid
//
//  Created by Giriraj Saigal on 14/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> minLeft(vector<int> x) {
    
    vector<int> ans(x.size(), 0);
    
    stack<int> s;
    int n = x.size();
    
    for(int i = 0; i < n; i++) {
        
        if(s.size() == 0){
            ans[i] = -1;
        }else if(x[s.top()] < x[i]){
            ans[i] = s.top();
        }else if(x[s.top()] >= x[i]){
            while(s.size() > 0 && x[s.top()] >= x[i]){
                s.pop();
            }
            if(s.size() == 0) {
                ans[i] = -1;
            }else{
                ans[i] = s.top();
            }
        }
        
        s.push(i);
    }
    
    return ans;
    
}

vector<int> minright(vector<int> x) {
    
    vector<int> ans(x.size(), 0);
    
    stack<int> s;
    int n = x.size();
    
    for(int i = n-1; i >=0; i--) {
        
        if(s.size() == 0){
            ans[i] = n;
        }else if(x[s.top()] < x[i]){
            ans[i] = s.top();
        }else if(x[s.top()] >= x[i]){
            while(s.size() > 0 && x[s.top()] >= x[i]){
                s.pop();
            }
            if(s.size() == 0) {
                ans[i] = n;
            }else{
                ans[i] = s.top();
            }
        }
        
        s.push(i);
    }
    
    return ans;
}

int maximalRectangle(vector<vector<int> > A) {
    
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    if(m == 0)
        return 0;
        
    vector<vector<int> > dp(n, vector<int>(m, 0));

    dp[0] = A[0];
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 1) {
                dp[i][j] = dp[i-1][j] + 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
    
        vector<int> left = minLeft(dp[i]);
        vector<int> right = minright(dp[i]);
        
        for(int j = 0; j < m; j++) {
            int rr = right[j];
            int ll = left[j];
            int area = (rr - ll - 1) * dp[i][j];
            ans = max(ans, area);
        }

    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<maximalRectangle({
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}})<<endl;
    return 0;
}



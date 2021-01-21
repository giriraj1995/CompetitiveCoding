//
//  main.cpp
//  min jumps
//
//  Created by Giriraj Saigal on 21/01/21.
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

vector<int> minJumps(vector<int> &A, int B) {
    int n = (int)A.size();
    
    if(n == 0) {
        return {};
    }
    
    if(n == 1) {
        return {1};
    }
    
    vector<int> parent(n, -1);
    vector<int> dp(n);
    
    for(int i = 0; i <= n; i++)
        dp[i] = INT_MAX;
        
    dp[0] = A[0];
    
    for(int i = 1; i < n; i++) {
        
        if(A[i-1] == -1 || dp[i-1] == INT_MAX) {
            continue;
        }
        
        int j = i;
        int temp = B;
        
        while(temp-- && j < n) {
            if((dp[i-1] + A[j] < dp[j]) && (A[j] != -1)) {
                parent[j] = i-1;
                dp[j] = dp[i-1] + A[j];
            }
            j++;
        }
    }
    
    if((dp[n-1] < 0) || (dp[n-1] == INT_MAX)) {
        return {};
    }
    
    dp.clear();
    vector<int> ans;
    int x = n-1;
    while(x != 0) {
        ans.push_back(x+1);
        x = parent[x];
    }
    
    parent.clear();
    ans.push_back(1);

    vector<int> ans2;
    for(int i = ans.size()-1; i >= 0; i--)
        ans2.push_back(ans[i]);
    return ans2;
}


int main(int argc, const char * argv[]) {
    vector<int> A ={618, 653, 805, 445, 105, 596, 266, 895, 620, 287, 203, 745, 804, 547, 222, 207, 209, 556, 896, 681 };
    vector<int> k = minJumps(A,16);
    return 0;
}

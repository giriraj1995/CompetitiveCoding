//
//  main.cpp
//  Sherlock and Cost
//
//  Created by Giriraj Saigal on 28/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int solve(vector<int> B, int curr, int ele) {
    
    if(curr == 1) {
        return max(abs(ele - 1), abs(ele - B[0]));
    }
    
    int left = solve(B, curr - 1, 1);
    int right = solve(B, curr - 1, B[curr-1]);
    
    return max(abs(ele - 1) + left, abs(ele - B[curr - 1]) + right);
}

//int cost(vector<int> B) {
//    int ans = INT_MIN;
//    vector<int> A,C;
//
//    int prev = B[0];
//    A.push_back(prev);
//
//    long sum1 = 0;
//    for(int i = 1; i < B.size(); i++) {
//
//        if(abs(B[i] - prev) > abs(1 - prev)) {
//            prev = B[i];
//            sum1 += abs(B[i] - prev);
//            A.push_back(B[i]);
//        }else{
//           prev = 1;
//            sum1 += abs(1 - prev);
//            A.push_back(1);
//        }
//    }
//
//    prev = 1;
//    long sum2 = 0;
//    for(int i = 1; i < B.size(); i++) {
//        if(abs(B[i] - prev) > abs(1 - prev)) {
//            prev = B[i];
//            sum2 += abs(B[i] - prev);
//            C.push_back(B[i]);
//        }else{
//           prev = 1;
//            sum2 += abs(1 - prev);
//            C.push_back(1);
//        }
//    }
//
//    return max(sum1, sum2);
//}

int solve2(vector<int> B) {
    int n = B.size();
    
    int high = INT_MIN;
    
    for(int i : B) {
        high = max(high, i);
    }
    
    vector<vector<int>> dp(n+1, vector<int>(high + 1, 0));
    
    int i = 0;
    
//    for(int j = 1; j <= high; j++) {
//        dp[1][j] = max(abs(j - 1), abs(j - B[0]));
//    }
    
    dp[1][1] = max(abs(1 - 1), abs(1 - B[0]));
    dp[1][B[1]] = max(abs(B[1] - 1), abs(B[1] - B[0]));
    
    for(int i = 2; i < n; i++) {
        int left = abs(1 - 1) + dp[i-1][1];
        int right = abs(1 - B[i-1]) + dp[i-1][B[i-1]];
        dp[i][1] = max(left,right);
        left = abs(B[i] - 1) + dp[i-1][1];
        right = abs(B[i] - B[i-1]) + dp[i-1][B[i-1]];
        dp[i][B[i]] = max(left,right);
    }
    
    return max(dp[n-1][1], dp[n-1][B[n-1]]);
    
}

int main(int argc, const char * argv[]) {
    //cout<<max(solve({1,2,3}, 2, 1), solve({1,2,3}, 2, 3));
    solve2({3 ,15 ,4 ,12 ,10});
    return 0;
}

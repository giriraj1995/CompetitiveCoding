//
//  main.cpp
//  Tushars BP
//
//  Created by Giriraj Saigal on 15/10/20.
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

//int knapsack(int c, vector<int> val, vector<int> wt){
//
//    int n = (int)val.size();
//    vector<vector<bool>> dp(n+1, vector<bool>(c+1));
//    vector<vector<int>> sum(n+1, vector<int>(c+1));
//
//
//    for(int j = 0; j <= c; j++){
//        dp[0][j] = false;
//        sum[0][j] = 0;
//    }
//
//    for(int i = 0; i <= n; i++){
//        dp[i][0] = true;
//        sum[i][0] = 0;
//    }
//
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j<= c; j++){
//
//            if(wt[i-1] <= j){
//
//                dp[i][j] = dp[i][j-wt[i-1]] | dp[i-1][j];
//
//                if(dp[i][j-wt[i-1]] && dp[i-1][j]){
//                    sum[i][j] = min(val[i-1] + sum[i-1][j-wt[i-1]], sum[i-1][j]);
//                }else if(dp[i-1][j-wt[i-1]]){
//                    sum[i][j] = sum[i-1][j - wt[i-1]];
//                }else if(dp[i-1][j]){
//                    sum[i][j] = sum[i-1][j];
//                }else
//                    sum[i][j] = 0;
//
//            } else {
//
//                dp[i][j] = dp[i-1][j];
//                sum[i][j] = sum[i-1][j];
//
//            }
//
//        }
//    }
//
//    return sum[n][c];
//
//
//}
//
//int solve(const vector<int> A, const vector<int> B, const vector<int> C) {
//
//    int ans = 0;
//
//    for(int i = 0; i < A.size(); i++){
//
//        ans += knapsack(A[i], C, B);
//
//    }
//
//    return ans;
//}
int solve(const vector<int> A, const vector<int> B, const vector<int> C) {
    vector<int> A1;
    vector<int> B1;
    vector<int> C1;
    A1=A;
    B1=B;
    C1=C;
    sort(A1.begin(), A1.end());
    int n = B1.size();
    int w = A1[A1.size()-1];
    int t[n+1][w+1];
    int sum=0;
    
//    for(int i = 0; i <= n; i++){
//        for(int j = 0; j <= w; j++){
//            cout<<t[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for(int i=0; i<n+1; i++) {
        t[i][0] = 0;
    }

    for(int j=0; j<w+1; j++) {
        t[0][j] = INT_MAX/2;
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<w+1; j++) {
            if(B1[i-1]<=j) {
                t[i][j] = min(C1[i-1] + t[i][j-B1[i-1]], t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
            
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= w; j++){
                    cout<<t[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }

    for(int i=0; i<A1.size(); i++) {
        sum = sum + t[n][A1[i]];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cout<<solve({2,4,6}, {2,1,3}, {2,5,3});
    return 0;
}

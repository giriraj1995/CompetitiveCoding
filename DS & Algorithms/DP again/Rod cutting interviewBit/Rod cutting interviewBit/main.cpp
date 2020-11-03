//
//  main.cpp
//  Rod cutting interviewBit
//
//  Created by Giriraj Saigal on 03/11/20.
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

//long long solve(long long s,long long e,vector<int> B,vector<vector<int>> &dp){
//
//    if(B.size()==0||s>=e){
//        dp[s][e]=0;
//        return 0;
//    }
//
//    if(dp[s][e]!=-1){
//        return dp[s][e];
//    }
//
//    long long ans=e-s,a=INT_MAX;
//
//    vector<int> v;
//
//    while(B.size()>0){
//        long long k=B[0];
//        B.erase(B.begin());
//        a=min(a,solve(s,k,v,dp)+solve(k,e,B,dp));
//        v.push_back(k);
//    }
//
//    dp[s][e]=ans+a;
//    return dp[s][e];
//}
//void so(long long s,long long e,vector<int> &v1,vector<int> B,vector<vector<int>> &dp){
//
//     if(B.size()==0||s>=e){
//        return;
//    }
//
//    long long ans=e-s;
//    vector<int> v;
//
//    while(B.size()>0){
//        long long k=B[0];
//        B.erase(B.begin());
//
//        if(dp[s][e]==ans+dp[s][k]+dp[k][e]){
//            v1.push_back(k);
//            so(s,k,v1,v,dp);
//            so(k,e,v1,B,dp);
//        }
//        v.push_back(k);
//    }
//
//    return;
//}
//
//vector<int> rodCut(int A, vector<int> B) {
//
//    vector<vector<int> > dp(A+1,vector<int>(A+1,-1));
//    long long ans=solve(0,A,B,dp);
//    vector<int> v1,v2;
//    so(0,A,v1,B,dp);
//
//    unordered_map<int,int> m;
//
//    for(int i=0;i<v1.size();i++){
//        if(m.find(v1[i])==m.end()){
//            v2.push_back(v1[i]);
//            m[v1[i]]++;
//        }
//    }
//
//    return v2;
//}

int solve(int i, int j, vector<int> x, vector<vector<int>> &dp)
{
    if(x.size() == 0 || i >= j) {
        dp[i][j] = 0;
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    vector<int> v;
    int ans = j - i;
    int a = INT_MAX;
    
    while(x.size() > 0) {
        
        int m = x[0];
        x.erase(x.begin());
        a = min(a, solve(i, m, v, dp) + solve(m, j, x, dp));
        v.push_back(m);
    }
    
    return dp[i][j] = ans = ans + a;
}

void so(int i ,int j, vector<int> &v, vector<int> B,vector<vector<int>> &dp) {
    
    if(B.size() == 0 || i >= j)
        return;
        
    vector<int> e;
    int ans = j - i;
        
    while(B.size() > 0) {
        
        int k = B[0];
        B.erase(B.begin());
        
        if(dp[i][j] == ans + dp[i][k] + dp[k][j]) {
            v.push_back(k);
            so(i, k, v, e, dp);
            so(k, j, v, B, dp);
        }
        
        e.push_back(k);
    }
    
    return;
    
}

vector<int> rodCut(int A, vector<int> B) {
    vector<vector<int>> dp(A+1, vector<int>(A+1, -1));
    vector<int> v;
    int k = solve(0, A, B, dp);
    so(0, A, v, B, dp);
    vector<int> v1;
    
    unordered_map<int,int> m;
    
    for(int i=0;i<v.size();i++){
        
        if(m.find(v[i])==m.end()){
            v1.push_back(v[i]);
            m[v1[i]]++;
        }
    }
    
    return v1;
}

int main(int argc, const char * argv[]) {
    rodCut(6, {1,2,5});
    return 0;
}

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

long long solve(long long s,long long e,vector<int> B,vector<vector<int>> &dp){
    
    if(B.size()==0||s>=e){
        dp[s][e]=0;
        return 0;
    }
    
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    
    long long ans=e-s,a=INT_MAX;
    
    vector<int> v;
    
    while(B.size()>0){
        long long k=B[0];
        B.erase(B.begin());
        a=min(a,solve(s,k,v,dp)+solve(k,e,B,dp));
        v.push_back(k);
    }
    
    dp[s][e]=ans+a;
    return dp[s][e];
}
void so(long long s,long long e,vector<int> &v1,vector<int> B,vector<vector<int>> &dp){

     if(B.size()==0||s>=e){
        return;
    }
    
    long long ans=e-s;
    vector<int> v;
    
    while(B.size()>0){
        long long k=B[0];
        B.erase(B.begin());
        
        if(dp[s][e]==ans+dp[s][k]+dp[k][e]){
            v1.push_back(k);
            so(s,k,v1,v,dp);
            so(k,e,v1,B,dp);
        }
        v.push_back(k);
    }

    return;
}

vector<int> rodCut(int A, vector<int> B) {
    
    vector<vector<int> > dp(A+1,vector<int>(A+1,-1));
    long long ans=solve(0,A,B,dp);
    vector<int> v1,v2;
    so(0,A,v1,B,dp);
    
    unordered_map<int,int> m;
    
    for(int i=0;i<v1.size();i++){
        if(m.find(v1[i])==m.end()){
            v2.push_back(v1[i]);
            m[v1[i]]++;
        }
    }

    return v2;
}

int main(int argc, const char * argv[]) {
    rodCut(6, {1,2,5});
    return 0;
}

//
//  main.cpp
//  Knapsack01
//
//
//  Created by Giriraj Saigal on 11/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int max(int i, int j){return i>j?i:j;}
int calls=0;
int t[1002][1002];
int knapsack_bup(vector<int> wt, vector<int> val, int W, int n){
    calls++;
    if(n == 0 || W == 0)
        return 0;
    
    if(t[n][W] != -1)
        return t[n][W];
    
    if(wt[n-1] <= W){
        return t[n][W] = max(val[n-1] + knapsack_bup(wt, val, W-wt[n-1], n-1),
                   knapsack_bup(wt, val, W, n-1));
    } else {
        return t[n][W] = knapsack_bup(wt, val, W, n-1);
    }
}

void show(int n, int w, int *dp){
    cout<<endl;
    for(int i = 0; i<= n; i++){
        for(int j = 0; j<= w; j++)
        {
            cout<<dp[n*i+j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int knapsack_td(vector<int> wt, vector<int> val, int W, int n){
    calls++;
    int dp[n+1][W+1];
    
    for(int i = 0; i<= n; i++){
        for(int j = 0; j<= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(i!= 0 && j!= 0)
                dp[i][j] = -1;
        }
//        show(n, W, (int *)dp);
    }
    
//    show(n, W, (int *)dp);
    
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= W; j++)
        {
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],
                              dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
//        show(n, W, (int *)dp);
    }
    
    return dp[n][W];
}

int main(int argc, const char * argv[]) {
    memset(t, -1, sizeof(t));
    vector<int> wt;
    wt.push_back(4);
    wt.push_back(3);
    wt.push_back(5);
    wt.push_back(7);
    
    vector<int> val;
    val.push_back(1);
    val.push_back(1);
    val.push_back(11);
    val.push_back(7);
    
    int n = wt.size();
    int W = 13;
    
    cout<<"Max Profit : "<<knapsack_td(wt, val, W, n)<<endl;
    cout<<"Calls : "<<calls<<endl;
    
    return 0;
}

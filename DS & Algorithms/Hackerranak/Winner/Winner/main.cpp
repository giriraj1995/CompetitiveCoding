//
//  main.cpp
//  Winner
//
//  Created by Giriraj Saigal on 11/10/20.
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

string solve(int turn, map<int, int> mp){
    
    vector<int> x;
    
    for(auto i : mp){
        int c = i.second;
        while(c > 0){
            x.push_back(i.first);
            c--;
        }
    }
    
    int n = x.size();
    int dp[n];
    
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    
    int j = 0;
    int i;
    int ma = 1;
    
    for(i = 1; i < n; i++){
        for(j = 0; j < i ; j++){
            if(x[i] > x[j] && dp[j] >= dp[i]){
                dp[i] = dp[j]+1;
                ma = max(ma, dp[i]);
            }
        }
    }
    
    if(ma == n){
        if(turn == 0){
            return "First";
        }else{
            return "Second";
        }
    }else{
        
        for(auto i : mp){
            mp[i.first]--;
        }
        
        if(ma & 1)
            return solve((turn+1)%2, mp);
        else
            return solve(turn, mp);
        
    }
    
}

string whoIsTheWinner(vector<int> arr) {
    
    map<int, int> mp;

    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
    }
        
    return solve(0, mp);
    
    
}


int main(int argc, const char * argv[]) {
    cout<<whoIsTheWinner({3,1,2,2,4,5,6,7,8,8,6,6,6,3,5,4})<<endl;
    return 0;
}

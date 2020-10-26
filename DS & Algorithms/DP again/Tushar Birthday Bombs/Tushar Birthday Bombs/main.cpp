//
//  main.cpp
//  Tushar Birthday Bombs
//
//  Created by Giriraj Saigal on 26/10/20.
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

vector<int> solve(int S, vector<int> wt) {
    int n=(int)wt.size();
    
    vector<int> dp(S+1, -1), back(S+1);

    for(int i=0;i<=S;i++){ // in normal unbounded we iterate over every Sum by including item one by one
        
        for(int j=0;j<n;j++){//this order is changed for lexographically minimum
            
            if(i>=wt[j] && dp[i]<dp[i-wt[j]]+1){
                dp[i]=dp[i-wt[j]]+1;
                back[i]=j;
            }
            
        }
    }

    vector<int> r;
    while(S>=0 && S-wt[back[S]]>=0){
        r.push_back(back[S]);
        S-= wt[back[S]];
    }
    return r;

}


int main(int argc, const char * argv[]) {
    solve(11, {6,8,5,4,7});
    return 0;
}

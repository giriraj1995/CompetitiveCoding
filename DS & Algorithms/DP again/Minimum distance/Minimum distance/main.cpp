//
//  main.cpp
//  Minimum distance
//
//  Created by Giriraj Saigal on 09/10/20.
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

int solve(string a, string b){
    
    int n = a.size();
    int m = b.size();
    
    vector<int> x(m+1, 0);
    vector<vector<int>> dp(n+1, x);
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    
    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= n; i++){
        int same = 0;
        int flag = 0;
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                same++;
                
                if(same == i){
                    flag = 1;
                }
                
                dp[i][j] = dp[i-1][j-1];
                
            }else{
                
                if(flag == 1){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i-1][j-1] = 1 + dp[i-1][j-1];
                }
                
                
            }
        }
    }
    
    return dp[n][m];
    
}

int main(int argc, const char * argv[]) {
    cout<<solve("b", "a")<<endl;
    return 0;
}

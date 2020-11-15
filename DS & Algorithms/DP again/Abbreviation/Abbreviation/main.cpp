//
//  main.cpp
//  Abbreviation
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

string abbreviation(string a, string b) {
            
        int n = a.size();
        int m = b.size();
        
        vector<bool> x(m+1, false);
        vector<vector<bool>> dp(n+1, x);
        
        dp[0][0] = true;
        
        for(int i = 1 ; i < n; i++) {
            if(islower(a[i-1])) {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = false;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                
                char x = a[i-1];
                int x1 = a[i-1];
                char y = b[j-1];
                int y1 = b[j-1];
                if(x == y || (x - 32) == y) {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    if(islower(x))
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m] ? "YES" : "NO";

}

int main(int argc, const char * argv[]) {
    cout<<abbreviation("daBcd", "ABC");
    return 0;
}

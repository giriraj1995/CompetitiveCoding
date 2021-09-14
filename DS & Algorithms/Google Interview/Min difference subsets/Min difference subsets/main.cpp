//
//  main.cpp
//  Min difference subsets
//
//  Created by Giriraj Saigal on 14/09/21.
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

vector<int> find(vector<int> a, int w) {
    int n = a.size();
    
    vector<vector<bool>> dp(n+1, vector<bool>(w+1, false));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = 0;
            else if(j == 0)
                dp[i][j] = 1;
            else{
                if(a[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    vector<int> ans;
    for(int j = 0; j <= w; j++) {
        if(dp[n][j] == 1){
            ans.push_back(j);
        }
    }
    
    return ans;
}

int solve(vector<int> A) {
    int ans = INT_MAX;
    int sum = 0;
    
    for(int i : A)
        sum += i;
    
    vector<int> all = find(A, sum);
    
    for(int x : all) {
        ans = min(ans, abs(sum - 2*x));
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({5});
    return 0;
}

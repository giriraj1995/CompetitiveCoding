//
//  main.cpp
//  N digit numbers with digit sum S
//
//  Created by Giriraj Saigal on 01/07/21.
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

vector<int> x;
long long solve1(int left, int sum, int B, vector<vector<int>> &dp) {
    
    if(dp[left][sum] != -1)
        return dp[left][sum];
        
    if(sum == 0 && left == 0)
        return dp[left][sum] = 1;
    
    if(sum == 0 && left > 0)
        return dp[left][sum] = 1;
    
    if(sum != 0 && left == 0)
        return dp[left][sum] = 0;
    
    long long ways = 0;
    
    if(sum == B){
        for(int i = 1; i <= 9; i++){
            if(sum - i >= 0){
                ways = (ways + solve1(left-1,sum-i, B, dp)) % 1000000007;
            }else
                break;
        }
    }else{
        for(int i = 0; i <= 9; i++){
            if(sum - i >= 0){
                ways = (ways + solve1(left-1,sum-i, B, dp)) % 1000000007;
            }else
                break;
        }
    }
    
    return dp[left][sum] = ways;
}

int solve(int A, int B) {
    if(B == 0)
        return 1;
        
    vector<vector<int>> dp(A+1, vector<int>(B+1, -1));
    x = {0,1,2,3,4,5,6,7,8,9};
    return solve1(A, B, B, dp);
}


int main(int argc, const char * argv[]) {
    solve(2,4);
    return 0;
}

//
//  main.cpp
//  Coins in a Line
//
//  Created by Giriraj Saigal on 05/07/21.
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

long long ans;
vector<vector<vector<int>>> dp;

int solve(int i, int j, vector<int>& A, bool now) {
    if(i > j){
        return 0;
    }
    
    if(dp[i][j][now] != -1)
        return dp[i][j][now];
    
    int a,b;
    if(now) {
        a = A[i] + solve(i+1,j,A,!now);
        b = A[j] + solve(i,j-1,A,!now);
        return dp[i][j][now] = max(a,b);
    }else{
        a = solve(i+1,j,A,!now);
        b = solve(i,j-1,A,!now);
        return dp[i][j][now] = min(a,b);
    }
    
    
}

int maxcoin(vector<int> A) {
    int i = 0;
    ans = 0;
    int j = A.size()-1;
    
    dp = vector<vector<vector<int>>>(A.size()+1, vector<vector<int>>(A.size()+1, vector<int>(2, -1)));
    bool now = true;
    
    return solve(i,j,A,now);
}


int main(int argc, const char * argv[]) {
    cout << maxcoin({1,2,3,4}) << endl;
    return 0;
}

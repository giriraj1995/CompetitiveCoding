//
//  main.cpp
//  Sum Of Fibonacci Numbers
//
//  Created by Giriraj Saigal on 24/09/21.
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
vector<int> dp;

int findInd(int x, int i, int j) {
    int ans = 0;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(dp[m] == x)
            return m;
        else{
            if(x < dp[m]){
                j = m-1;
            }else{
                ans = m;
                i = m+1;
            }
        }
    }
    
    return ans;
}

int solve(int A, int k) {
    
    if(A == 0 || A == 1)
        return A;
        
    A -= dp[k];
    return 1+solve(A, findInd(A, 0, k));
}

int fibsum(int A) {
    
    if(A == 0 || A == 1)
        return A;
    
    dp = {};
    dp.push_back(1);
    dp.push_back(1);
    int i = 2;
    
    while(dp[i-1]+dp[i-2] <= A) {
        dp.push_back(dp[i-1]+dp[i-2]);
        i++;
    }
    
    return solve(A, dp.size()-1);
}



int main(int argc, const char * argv[]) {
    cout << fibsum(100) << endl;
    return 0;
}

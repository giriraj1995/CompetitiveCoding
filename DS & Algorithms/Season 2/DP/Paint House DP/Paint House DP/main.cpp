//
//  main.cpp
//  Paint House DP
//
//  Created by Giriraj Saigal on 11/08/21.
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

vector<vector<int>> dp;
int solve1(int i, int j, vector<vector<int> > &A) {
    if(i == A.size()){
        return 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int a = solve1(i+1,(j+1)%3,A);
    int b = solve1(i+1,(j+2)%3,A);

    return dp[i][j] = A[i][j] + min(a,b);
}

int solve(vector<vector<int> > A) {
    vector<vector<int>> x(A.size(), vector<int>(A[0].size()));
    x[0] = A[0];
    
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < 3; j++) {
            x[i][j] = A[i][j] + min(x[i-1][(j+1)%3], x[i-1][(j+2)%3]);
        }
    }
    
    int f = x[A.size()-1][0];
    int y = x[A.size()-1][1];
    int z = x[A.size()-1][2];
    
    return min(f, min(y,z));
}
                          

int main(int argc, const char * argv[]) {
    cout << solve({  {1, 2, 3},
        {10, 11, 12}
    }) << endl;
    return 0;
}

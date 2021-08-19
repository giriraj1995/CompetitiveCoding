//
//  main.cpp
//  Egg Drop problem
//
//  Created by Giriraj Saigal on 18/08/21.
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
int eggdrop(int eggs, int floors) {
    if(eggs == 1)
        return dp[eggs][floors] = floors;
    
    if(floors == 1)
        return dp[eggs][floors] = 1;
    
    if(dp[eggs][floors] != -1){
        return dp[eggs][floors];
    }
        
    int tempans = floors;
    for(int i = 1; i <= floors; i++) {
        //breaks
        int whenbreaks = dp[eggs-1][i-1] = eggdrop(eggs-1, i-1);
        //does not break
        int whendoesntbreak = dp[eggs][floors-i] = eggdrop(eggs, floors-i);
        
        tempans = min(tempans, 1 + max(whenbreaks,whendoesntbreak));
    }
    
    return dp[eggs][floors] = tempans;
}

int solve(int A, int B) {
    dp = vector<vector<int>>(A+1, vector<int>(B+1, -1));
    return eggdrop(A,B);
}

int main(int argc, const char * argv[]) {
    cout << solve(2, 100);
    return 0;
}

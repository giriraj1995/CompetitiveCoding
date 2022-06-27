//
//  main.cpp
//  2209. Minimum White Tiles After Covering With Carpets
//
//  Created by Giriraj Saigal on 18/06/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
vector<vector<int>> dp;

int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
//         dp = vector<vector<int>>(floor.size()+1, vector<int>(numCarpets+1,-1));
//         return solve(0, numCarpets, floor, carpetLen);
        
        dp = vector<vector<int>>(floor.size()+1, vector<int>(numCarpets+1,0));
        //find dp[0][numCarpets]
        
        int white = 0;
        for(int i = (int)floor.size()-1; i >= 0; i--) {
            if(floor[i] == '1')
                white++;
            dp[i][0] = white;
        }
        
        for(int j = 0; j <= numCarpets; j++) {
            dp[floor.size()][j] = 0;
        }
        
        for(int j = 1; j <= numCarpets; j++) {
            for(int i = (int)floor.size()-1; i >= 0; i--) {
                if(i+carpetLen <= floor.size()) {
                    dp[i][j] = min(dp[i+carpetLen][j-1], (floor[i] =='1'?1:0) + dp[i+1][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][numCarpets];
    }

int main(int argc, const char * argv[]) {
    minimumWhiteTiles("11111",
                      2,
                      3);
    return 0;
}

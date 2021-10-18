//
//  main.cpp
//  552. Student Attendance Record II
//
//  Created by Giriraj Saigal on 18/10/21.
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

vector<vector<vector<vector<int>>>> dp;
int mod;
    long long solve(bool absent, bool lastLate, bool lastTwoLate, int i, int n) {
        if(i == n)
            return 1;
        
        if(dp[absent][lastLate][lastTwoLate][i] != -1)
            return dp[absent][lastLate][lastTwoLate][i];
        
        long long x = 0,y = 0,z = 0;
        if(absent) {
            if(lastTwoLate){
                //present
                x = solve(true, false, false, i+1, n);
            }else{
                //late
                    if(lastLate) {
                        x = solve(true, true, true, i+1, n);
                    }else{
                        x = solve(true, true, false, i+1, n);
                    }
                
                //present
                y = solve(true, false, false, i+1, n);
            }
        }else{
            if(lastTwoLate){
                //present
                x = solve(false, false, false, i+1, n);
                
                //absent
                y = solve(true, false, false, i+1, n);
            }else{
                //late
                    if(lastLate) {
                        x = solve(false, true, true, i+1, n);
                    }else{
                        x = solve(false, true, false, i+1, n);
                    }
                
                //present
                y = solve(false, false, false, i+1, n);
                
                //absent
                z = solve(true, false, false, i+1, n);
            }
        }
        
        return dp[absent][lastLate][lastTwoLate][i] = (x+y+z) % mod;
    }
    
    int checkRecord(int n) {
        dp = vector<vector<vector<vector<int>>>>(2,vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(n+1, -1))));
        mod = 1000000007;
        if(n == 1)
            return 3;
        
        //absent
        long long x = solve(true, false, false, 1, n);
        
        //late
        long long y = solve(false, false, false, 1, n);
        
        //present
        //long long z = solve(false, false, 0, n);
        
        return (x+y*2)%mod;
    }

int main(int argc, const char * argv[]) {
    cout << checkRecord(2) << endl;
    return 0;
}

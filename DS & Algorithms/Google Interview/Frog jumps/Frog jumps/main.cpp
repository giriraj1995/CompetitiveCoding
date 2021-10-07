//
//  main.cpp
//  Frog jumps
//
//  Created by Giriraj Saigal on 07/10/21.
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

vector<vector<bool>> dp;
int search(vector<int> &stones, int val, int i, int j) {
        while(i <= j) {
            int m = i + (j-i)/2;
            if(stones[m] == val)
                return m;
            else if(val < stones[m])
                j = m-1;
            else
                i = m+1;
        }
        return -1;
    }
    
    bool solve(int prev, int i, vector<int> stones) {
        
        if(dp[prev][i] == false)
            return false;
        
        if(i == stones.size()-1) {
            return true;
        }
        
        set<int> jumps;
        if(i == 0) {
            jumps.insert(1);
        }else{
            jumps.insert(prev-1);
            jumps.insert(prev);
            jumps.insert(prev+1);
        }
        
        jumps.erase(0);
        
        for(int k : jumps) {
            int nextStone = stones[i]+k;
            int ind = search(stones, nextStone, i+1, stones.size()-1);
            if(ind != -1) {
                if(solve(k, ind, stones))
                    return true;
            }
        }
        
        return dp[prev][i] = false;
    }
    
    bool canCross(vector<int> stones) {
        dp = vector<vector<bool>>(2005, vector<bool>(stones.size()+1, true));
        return solve(0, 0, stones);
    }

int main(int argc, const char * argv[]) {
    solve(0,0,{0,1,3,5,6,8,12,17});
    return 0;
}

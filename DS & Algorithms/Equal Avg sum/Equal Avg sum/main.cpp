//
//  main.cpp
//  Equal Avg sum
//
//  Created by Giriraj Saigal on 17/10/20.
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

bool check(int ind, int sum, vector<int> &res, int ele, vector<int> A, vector<int> &g,
vector<vector<vector<bool>>> &dp){
    
    if(ele == 0)
        return dp[ind][sum][ele] = (sum == 0);
    
    if(ind >= A.size())
        return dp[ind][sum][ele] = false;
        
    if(dp[ind][sum][ele] == false)
        return false;
    
    if(A[ind] <= sum){
        res.push_back(A[ind]);
        g[ind] = 1;
        if(check(ind+1, sum-A[ind], res, ele-1, A, g, dp))
            return dp[ind][sum][ele] = true;
        res.pop_back();
        g[ind] = 0;
    }
    
    if(check(ind+1, sum, res, ele, A, g, dp))
        return dp[ind][sum][ele] = true;
    
    return dp[ind][sum][ele] = false;
}

vector<vector<int> > avgset(vector<int> A) {
    
    int sum = 0;
    int n = A.size();
    vector<int> g(A.size(), 0);
    vector<vector<int> > ans;
    vector<int> res;
    sort(A.begin(), A.end());
    
    for(int i : A)
        sum += i;
    
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(sum+1, vector<bool>(n+1, true)));
        
    for(int i = 1; i < A.size()-1; i++){
        
        if((sum * i) % n == 0){
            
            int ss = sum*i;
            ss/=n;
            
            if(check(0, ss, res, i, A, g, dp)){
                
                ans.push_back(res);
                vector<int> t;
                for(int i = 0; i < g.size(); i++){
                    if(g[i] == 0)
                        t.push_back(A[i]);
                }
                ans.push_back(t);
                return ans;
                
            }
            
        }
        
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    avgset({1, 7, 15, 29, 11, 9});
    return 0;
}

//
//  main.cpp
//  Equal Avg Partition
//
//  Created by Giriraj Saigal on 02/10/21.
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

bool solve(int i, int sum, int ele, vector<int> &A, vector<int> &ans,
vector<vector<vector<bool>>> &dp) {
    if(ele == 0 && sum == 0){
        return true;
    }
    
    if(sum == 0)
        return false;
        
    if(i == A.size())
        return false;
        
    if(ele == 0)
        return false;
    
    if(dp[i][sum][ele] == false)
        return false;
        
    if(sum - A[i] >= 0){
        ans.push_back(A[i]);
        if(solve(i+1, sum-A[i],ele-1,A,ans,dp))
            return dp[i][sum][ele] = true;
        ans.pop_back();
   
        if(solve(i+1,sum,ele,A,ans,dp))
            return dp[i][sum][ele] = true;
    }else{
        if(solve(i+1,sum,ele,A,ans,dp))
            return dp[i][sum][ele] = true;
    }
    
    return dp[i][sum][ele] = false;
}

vector<vector<int> > avgset(vector<int> A) {
    sort(A.begin(), A.end());
    int sum = 0;
    for(int i : A)
        sum += i;
    int n = A.size();
    
    if(n == 0)
        return {};
    
    vector<int> ans;
    vector<int> ans_next;

    int avg = sum/n;
    
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(sum+1, vector<bool>(n+1, true)));
    for(int i = 1; i < n; i++) {
        if((sum * i)%n == 0) {
            if(solve(0,(sum * i)/n,i,A,ans,dp)){
                int k = 0;
                for(int t : A){
                    if(t == ans[k]){
                        k++;
                        continue;
                    }
                    ans_next.push_back(t);
                }
                break;
            }
        }
    }
    
    return {ans,ans_next};
}



int main(int argc, const char * argv[]) {
    vector<vector<int>> x = avgset({1, 7, 15, 29, 11, 9});
    return 0;
}

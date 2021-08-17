//
//  main.cpp
//  Buy and sell 4
//
//  Created by Giriraj Saigal on 12/08/21.
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

vector<vector<vector<int>>> dp;
int buysell(int i, vector<int> A, bool x, int t, int B) {
    
    if(i == A.size())
        return 0;
        
    if(t == B)
        return 0;
    
    if(dp[i][t][x] != -1)
        return dp[i][t][x];
        
    if(x) {
        int buy = buysell(i+1,A,!x,t,B)-A[i];
        int noth = buysell(i+1,A,x,t,B);
        
        return dp[i][t][x] = max(buy, noth);
    }else{
        int sell = A[i] + buysell(i+1,A,!x,t+1,B);
        int noth = buysell(i+1,A,x,t,B);
        
        return dp[i][t][x] = max(sell, noth);
    }
}

int bulbs(vector<int> &A) {
    int res = 0;
    int n = A.size();
    int count = 0;
    
    for(int i = 0;i < n;i++){
        if(count==0){
            if(A[i]==0){
                res++;
                count=1;
            }
        }
        else{
            if(A[i]==1){
                res++;
                count=0;
            }
        }
    }
    return res;
}

int solve(vector<int> A, int B) {
    dp = vector<vector<vector<int>>>(A.size()+1, vector<vector<int>>(B+1, vector<int>(2, -1)));
    return buysell(0, A, true, 0, B);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

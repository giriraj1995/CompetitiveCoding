//
//  main.cpp
//  Unique ways in a grid
//
//  Created by Giriraj Saigal on 26/06/21.
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

bool isPalindrome(string s) {
    string k = "";
    
    for(char c : s){
        if((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))             {
            k += c;
            }
    }
    
    int i = 0;
    int j = k.size()-1;
    while(i < j){
        if(k[i] == k[j]){
            i++;
            j--;
            continue;
        }else if(k[i]+32 == k[j] || k[i]-32 == k[j]) {
            if(((k[i] >= 65 && k[i] <= 90) || (k[i] >= 97 && k[i] <= 122)) &&
               ((k[j] >= 65 && k[j] <= 90) || (k[j] >= 97 && k[j] <= 122))){
                i++;
                j--;
                continue;
            }else{
                return false;
            }
        }else
               return false;
    }
    
    return true;
}

int solve(int i, int j, vector<vector<int> > &A, vector<vector<int> > &dp) {
    if(i == A.size()-1 && j == A[0].size()-1)
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(A[i][j] == 1)
        return dp[i][j] = 0;
    
    if(i+1 < A.size() && j+1 < A[0].size()){
        return dp[i][j] = solve(i+1,j,A,dp) + solve(i,j+1,A,dp);
    }else if(i+1 < A.size()){
        return dp[i][j] = solve(i+1,j,A,dp);
    }else{
        return dp[i][j] = solve(i,j+1,A,dp);
    }
}

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size()==0)
        return 0;
        
    if(A[0].size() == 0)
        return 0;
        
    if(A[A.size()-1][A[0].size()-1] == 1)
        return 0;
    
    if(A[0][0] == 1)
        return 0;
        
    vector<vector<int> > dp(A.size(), vector<int>(A[0].size(), -1));
    return solve(0,0,A,dp);
}


int main(int argc, const char * argv[]) {
    isPalindrome("0P");
    return 0;
}

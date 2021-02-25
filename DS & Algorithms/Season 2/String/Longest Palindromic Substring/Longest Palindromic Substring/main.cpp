//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by Giriraj Saigal on 25/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

bool isPalindrom(string x, int i, int j) {
    while(i < j) {
        if(x[i] != x[j])
            return false;
        i++;
        j--;
    }
    
    return true;
}

int longest(string a, int i, int j, int &s, int &e, int &ans, vector<vector<int>> &dp) {
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(i > j) {
        return dp[i][j] = 0;
    }
    
    if(i == j) {
        return dp[i][j] = 1;
    }
    
    if(isPalindrom(a, i, j)) {
        if(j-i+1 > ans) {
            s = i;
            e = j;
            ans = j - i + 1;
        }
        return dp[i][j] = j - i + 1;
    }
    
    int left = longest(a,i,j-1,s,e,ans,dp);
    int right = longest(a,i+1,j,s,e,ans,dp);

    if(left > ans) {
        s = i;
        e = j-1;
        ans = left;
    }

    if(right > ans) {
        s = i+1;
        e = j;
        ans = right;
    }

    return dp[i][j] = max(left,right);
}

string longestPalindrome(string A) {
    if(A.size() <= 1)
        return A;
    int start,end;
    int ans = 0;
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    longest(A,0,A.size()-1,start,end,ans,dp);
    return A.substr(start,ans);
}


int main(int argc, const char * argv[]) {
    cout<<longestPalindrome("ab");
    return 0;
}

//
//int x = i;
//int y = j;
//
//while(a[i] == a[j]) {
//    i++;
//    j--;
//}
//
//if(i > j) {
//    return dp[x][y] = y - x + 1;
//}
//
//if(i == x && j == y) {
//    int left = longest(a,i,j-1,s,e,ans,dp);
//    int right = longest(a,i+1,j,s,e,ans,dp);
//
//    if(left > ans) {
//        s = x;
//        e = y-1;
//        ans = left;
//    }
//
//    if(right > ans) {
//        s = x+1;
//        e = y;
//        ans = right;
//    }
//
//    return dp[x][y] = max(left,right);
//}
//
//int left = longest(a,x,j,s,e,ans,dp);
//int right = longest(a,i,y,s,e,ans,dp);
//
//if(left > ans) {
//    s = x;
//    e = j;
//    ans = left;
//}
//
//if(right > ans) {
//    s = i;
//    e = y;
//    ans = right;
//}
//
//return dp[x][y] = max(left,right);

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

//bool isPalindrom(string x, int i, int j) {
//    while(i < j) {
//        if(x[i] != x[j])
//            return false;
//        i++;
//        j--;
//    }
//
//    return true;
//}
//
//int longest(string a, int i, int j, int &s, int &e, int &ans, vector<vector<int>> &dp) {
//
//    if(dp[i][j] != -1)
//        return dp[i][j];
//
//    if(i > j) {
//        return dp[i][j] = 0;
//    }
//
//    if(i == j) {
//        return dp[i][j] = 1;
//    }
//
//    if(isPalindrom(a, i, j)) {
//        if(j-i+1 > ans) {
//            s = i;
//            e = j;
//            ans = j - i + 1;
//        }
//        return dp[i][j] = j - i + 1;
//    }
//
//    int left = longest(a,i,j-1,s,e,ans,dp);
//    int right = longest(a,i+1,j,s,e,ans,dp);
//
//    if(left > ans) {
//        s = i;
//        e = j-1;
//        ans = left;
//    }
//
//    if(right > ans) {
//        s = i+1;
//        e = j;
//        ans = right;
//    }
//
//    return dp[i][j] = max(left,right);
//}

void findCount(string A, int i, int j, int count, int &pos, int &maxLen) {
    while(i >= 0 && j < A.size() && A[i] == A[j]) {
        i--;
        j++;
        count += 2;
    }
    
    if(count > maxLen) {
        pos = i + 1;
        maxLen = count;
    }
}

string longestPalindrome(string A) {
    if(A.size() == 1)
        return A;
    
    int maxLen = 1;
    int pos = 0;
    for(int i = 0; i < A.size(); i++) {
        findCount(A, i-1, i+1, 1, pos, maxLen);
        findCount(A, i, i+1, 0, pos, maxLen);
    }
    
    return A.substr(pos,maxLen);
}


int main(int argc, const char * argv[]) {
    cout<<longestPalindrome("giri");
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

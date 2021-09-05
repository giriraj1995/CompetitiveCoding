//
//  main.cpp
//  longestCommonSuperString
//
//  Created by Giriraj Saigal on 06/09/21.
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
    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        string x = "";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        int i = n;
        int j = m;
        int s= dp[text1.size()][text2.size()];
        
        while(i != 0 && j != 0) {
            if(text1[i-1] == text2[j-1])
            {
                x+=text1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1])
                {
                    i--;
                }else{
                    j--;
                }
            }
        }
        
        reverse(x.begin(), x.end());
        return x;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string x = longestCommonSubsequence(str1,str2);
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        string ans = "";
        while(k < x.size() && i < str1.size() && j < str2.size()) {
            while(str1[i] != x[k]){
                ans += str1[i];
                i++;
            }
            
            while(str2[j] != x[k]){
                ans += str2[j];
                j++;
            }
                
            ans += x[k];
            
            i++;
            j++;
            k++;
        }
        
        if(i != str1.size())
        ans += str1.substr(i);
        
        if(j != str2.size())
        ans += str2.substr(j);
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << shortestCommonSupersequence("aggtabj","gxtxayb") <<endl;
    return 0;
}

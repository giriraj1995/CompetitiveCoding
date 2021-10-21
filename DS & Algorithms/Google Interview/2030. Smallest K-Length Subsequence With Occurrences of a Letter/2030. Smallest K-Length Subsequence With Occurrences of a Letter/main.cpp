//
//  main.cpp
//  2030. Smallest K-Length Subsequence With Occurrences of a Letter
//
//  Created by Giriraj Saigal on 20/10/21.
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

unordered_map<string, string> dp;
    bool solve(string s, int k, char letter, int r, int n) {
        string key = to_string(k) + "|" + to_string(r) + "|"  + to_string(n);
        if(n >= 0 && k == 0 && r == 0){
            dp[key] = "";
            return true;
        }
        
        if(k == 0 && r != 0)
            return false;
        
        if(n == 0 && (k != 0 || r != 0))
            return false;
        
        if(r > k)
            return false;
        
        bool x = false,y = false;
        string notake = to_string(k) + "|" + to_string(r) + "|"  + to_string(n-1);
        string lettertake = to_string(k-1) + "|" + to_string(r-1 < 0 ? 0 : r-1) + "|"  + to_string(n-1);
        string take = to_string(k-1) + "|" + to_string(r) + "|"  + to_string(n-1);

        //later
        if(s[n-1] == letter) {
            //take
            x = solve(s, k-1, letter, r-1 < 0 ? 0 : r-1, n-1);
            //not take
            y = solve(s, k, letter, r, n-1);
            
            if(x && y) {
                dp[key] = dp[lettertake]+letter < dp[notake] ? dp[lettertake]+letter : dp[notake];
                return true;
            }else if(x) {
                dp[key] = dp[lettertake]+letter;
                return true;
            }else if(y){
                dp[key] = dp[notake];
                return true;
            }else{
                return false;
            }
        }else{
            //take
            x = solve(s, k-1, letter, r, n-1);
            //not take
            y = solve(s, k, letter, r, n-1);
            
            if(x && y) {
                dp[key] = dp[take]+s[n-1] < dp[notake] ? dp[take]+s[n-1] : dp[notake];
                return true;
            }else if(x) {
                dp[key] = dp[take]+s[n-1];
                return true;
            }else if(y){
                dp[key] = dp[notake];
                return true;
            }else{
                return false;
            }
        }
    }
    string smallestSubsequence1(string s, int k, char letter, int repetition) {
        int n = s.size();
        if(k == n)
            return s;
        dp.clear();
        solve(s,k,letter,repetition,n);
        return dp[to_string(k) + "|" + to_string(repetition) + "|"  + to_string(n)];
    }

string smallestSubsequence(string s, int k, char letter, int repetition) {
        int count = 0;
        for(char c : s){
            if(c == letter)
                count++;
        }
        int n = s.size();
        stack<char> st;
    int leftR = repetition;
        for(int i = 0; i < s.size(); i++) {
            char curr = s[i];
            int f = k - st.size();
            while(st.size() > 0
               && (
                   ((curr < st.top())
                   &&
                   (st.size() + n - i > k)
                   &&
                   ((st.top() != letter) || (count > leftR)))
                    || ((k - st.size()) < leftR))) {
                char poped = st.top();
                st.pop();
                if(poped == letter) {
                    leftR++;
                }
            }
            
            if(st.size() < k) {
                st.push(s[i]);
                if(s[i] == letter) {
                    leftR--;
                }
            }
            
            if(s[i] == letter){
                count--;
            }
        }
        
        string ans = string(k, 'd');
        int i = k-1;
        
        while(st.size() > 0){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << smallestSubsequence("leet",
                                3,
                                'e',
                                1) << endl;
    return 0;
}

//
//  main.cpp
//  140. Word Break II
//
//  Created by Giriraj Saigal on 07/11/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

unordered_map<string, vector<string>> dp;
bool solve(string s, unordered_set<string> dic) {
    int n = s.size();
    
    if(n == 0){
        dp[s] = {};
        return true;;
    }
    
    if(dp.count(s)){
        return true;
    }
    
    vector<string> ans;
    bool isPossible = false;
    
    for(int k = 1; k <= n; k++) {
        string prev = s.substr(0, k);
        
        if(dic.count(prev)) {
            bool nextPossible = solve(s.substr(k), dic);
            
            if(nextPossible) {
                isPossible = true;
                vector<string> next = dp[s.substr(k)];

                if(next.size() == 0) {
                    ans.push_back(prev);
                }

                for(int i = 0; i < next.size(); i++) {
                    ans.push_back(prev + " " + next[i]);
                }
            }
        }
    }
    
    
    if(isPossible){
        dp[s] = ans;
        return true;
    }
    
    return false;
}

vector<string> wordBreak(string s, vector<string> wordDict) {
    unordered_set<string> dic;
    dp.clear();
    
    for(string k : wordDict)
        dic.insert(k);
    
    solve(s, dic);
    
    return dp[s];
}
int main(int argc, const char * argv[]) {
    wordBreak("aaaaaaa",
              {"aaaa","aa","a"});
    return 0;
}

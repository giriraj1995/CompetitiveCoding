//
//  main.cpp
//  Eliminate Parenthese
//
//  Created by Giriraj Saigal on 05/10/21.
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


    int lowest;
    void solve(int i, string s, int stB, int enB, int deletions, string inp, vector<string> &ans) {
        if(i == s.size()) {
            if(stB != enB)
                return;
            
            if(deletions < lowest) {
                ans.clear();
                lowest = deletions;
                ans.push_back(inp);
            }else if(deletions == lowest) {
                ans.push_back(inp);
            }
            
            return;
        }
        
        if(s[i] != '(' && s[i] != ')')
        {
            solve(i+1,s,stB,enB,deletions,inp+s[i],ans);
            return;
        }
        
        if(stB == enB) {
            if(s[i] == '(') {
                solve(i+1,s,stB+1,enB,deletions,inp+s[i],ans);
            }
        }else if(stB > enB) {
            if(s[i] == ')') {
                solve(i+1,s,stB,enB+1,deletions,inp+s[i],ans);
            }else{
                solve(i+1,s,stB+1,enB,deletions,inp+s[i],ans);
            }
        }else{
            return;
        }
        
        if(deletions >= lowest)
            return;
        
        solve(i+1,s,stB,enB,deletions+1,inp,ans);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        lowest = INT_MAX;
        solve(0, s, 0, 0, 0, "", ans);
        return ans;
    }

int main(int argc, const char * argv[]) {
    removeInvalidParentheses("()())()");
    return 0;
}

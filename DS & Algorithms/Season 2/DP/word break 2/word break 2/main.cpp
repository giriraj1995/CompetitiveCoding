//
//  main.cpp
//  word break 2
//
//  Created by Giriraj Saigal on 25/07/21.
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

set<string> mp;
set<string> ans;

void solve(string A, int n, string t) {
    if(n == A.size()) {
        if(t != ""){
            ans.insert(t.substr(0,t.size()-1));
        }
        return;
    }
    
    int c = A.size();
    int p = min(c, n+20);
    
    for(int k = n; k < p; k++) {
        string a = A.substr(n, k-n+1);
        
        if(mp.find(a) != mp.end()) {
            solve(A, k+1, t+a+" ");
        }
    }
    
    return;
}

vector<string> wordBreak(string A, vector<string> B) {
    mp.clear();
    ans.clear();
    for(string k : B){
        mp.insert(k);
    }
    solve(A, 0, "");
    vector<string> gg;
    
    for(auto j : ans) {
        gg.push_back(j);
    }
    return gg;
}


int main(int argc, const char * argv[]) {
    wordBreak("baababbbbabbbbbbbbabbbbbabbbb", {"abb", "aab", "b", "a", "ab", "abaabbaa"});
    return 0;
}

//
//  main.cpp
//  943. Find the Shortest Superstring
//
//  Created by Giriraj Saigal on 11/10/21.
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
vector<vector<string>> graph;
string find(string x, string y) {
        int n = (int)x.size();
        int m = (int)y.size();

        for(int i = n; i >= 1; i--) {
            string xd = x.substr(n-i,i);
            if(xd.size() > m)
                continue;
            string yd = y.substr(0,i);
            if(xd == yd)
                return x.substr(0,n-i) + y;
        }
        return x+y;
    }
    
    unordered_map<int, vector<string>> dp;

vector<string> solve(int mask, vector<string>& words) {
    if(dp.count(mask)){
        return dp[mask];
    }
    
    if(mask == 0)
        return dp[mask] = {""};
    
    int len = INT_MAX;
    vector<string> ans;
    for(int i = 0; i < words.size(); i++) {
        if((1 << i) & mask) {
            mask = (1<<i) ^ mask;
            string x = words[i];
            vector<string> Y = solve(mask, words);
            for(string y : Y){
                string z = find(x,y);
                if(z.size() < len) {
                    ans.clear();
                    ans.push_back(z);
                    len = (int)z.size();
                }else if(z.size() == len){
                    ans.push_back(z);
                }
            }
            mask = (1<<i) ^ mask;
        }
    }
    
    return dp[mask] = ans;
}

string shortestSuperstring(vector<string> words) {
    int n = (int)words.size();
    int mask = 0;

    graph = vector<vector<string>>(n,vector<string>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = find(words[i],words[j]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        mask = mask | (1<<i);
    }
    
    vector<string> ans;
    ans = solve(mask, words);
    return ans[0];
}

int main(int argc, const char * argv[]) {
    cout << shortestSuperstring({"giriraj","rajsakshi"}) << endl;
    return 0;
}

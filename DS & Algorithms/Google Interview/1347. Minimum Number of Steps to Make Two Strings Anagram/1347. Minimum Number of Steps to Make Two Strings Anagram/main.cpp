//
//  main.cpp
//  1347. Minimum Number of Steps to Make Two Strings Anagram
//
//  Created by Giriraj Saigal on 03/11/21.
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

int minSteps(string s, string t) {
        map<char, int> S;
        map<char, int> T;
        
        for(char c : s)
            S[c]++;
        
        for(char c : t)
            T[c]++;
        
        // if intT > intS - deletion
        // if intS > intT - insertion
        
        int ans = 0;
        int ops = 0;
        
        for(auto k : T) {
            char c = k.first;
            int v = k.second;
            int prev = ops;
            
            if(v > S[c]) { // deletion
                ops += v - S[c];
            }
            
            if(v < S[c]) {
                ops -= S[c] - v;
            }
            
            if(prev == 0) {
                ans += abs(ops);
            }else if((prev < 0 && ops < prev) || (prev > 0 && ops > prev)) {
                ans += abs(prev-ops);
            }else if((prev < 0 && ops > 0) || (prev > 0 && ops < 0)) {
                ans += abs(ops);
            }
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    minSteps("leetcode",
             "practice");
    return 0;
}

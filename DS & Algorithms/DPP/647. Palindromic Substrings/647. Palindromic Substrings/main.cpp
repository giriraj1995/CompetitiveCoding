//
//  main.cpp
//  647. Palindromic Substrings
//
//  Created by Giriraj Saigal on 10/02/22.
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

int countSubstrings(string s) {
        vector<vector<bool>> palinDp(vector<vector<bool>>(s.size(), vector<bool>(s.size(), false)));
        
        for(int i = 0; i < s.size(); i++) {
            palinDp[i][i] = true;
            
            int prev = i-1;
            int next = i+1;
            
            while(prev >= 0 && next < s.size()) {
                if(palinDp[prev+1][next-1] && s[prev] == s[next]) {
                    palinDp[prev][next] = true;
                }
                
                prev--;
                next++;
            }
            
            prev = i;
            next = i+1;
            
            while(prev >= 0 && next < s.size()) {
                if((prev+1 > next-1 || palinDp[prev+1][next-1]) && s[prev] == s[next]) {
                    palinDp[prev][next] = true;
                }
                
                prev--;
                next++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(palinDp[i][j])
                    ans++;
            }
        }
        return ans;

    }

int main(int argc, const char * argv[]) {
    countSubstrings("daa");
    return 0;
}

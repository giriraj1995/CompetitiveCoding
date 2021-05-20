//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by Giriraj Saigal on 18/05/21.
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


    string minWindow(string s, string t) {
        map<int,int> mp;
        
        for(int i = 0; i < 128; i++) {
            mp[i] = 0;
        }
        
        for(char c : t) {
            mp[c]++;
        }
        
        int i = 0;
        int j = 0;
        int com = (int)t.size();
        int st = -1;
        int len = INT_MAX;
        
        while(j < (int)s.size()) {
            if(mp[s[j]]-- > 0) {
                com--;
            }
            
            while(com == 0) {
                if(j-i+1 < len) {
                    len = j-i+1;
                    st = i;
                }
                
                if(mp[s[i]]++ >= 0) {
                    com++;
                }
                
                i++;
            }
            
            j++;
        }
        
        return len == INT_MAX ? "" : s.substr(st,len);
    }


int main(int argc, const char * argv[]) {
    cout<<minWindow("ADOBECODEBANC", "ABC")<<endl;
    return 0;
}

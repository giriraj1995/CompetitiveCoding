//
//  main.cpp
//  Day 1 may Leetcode
//
//  Created by Giriraj Saigal on 01/05/21.
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

class WordFilter {
public:
    map<string, int> mp;
    WordFilter(vector<string> words) {
        vector<string> prefix;
        vector<string> suffix;
        
        for(int i = (int)words.size()-1; i >= 0; i--) {
            string x = words[i];
            
            for(int j = 0; j <= (int)x.size(); j++) {
                prefix.push_back(x.substr(0,j));
                suffix.push_back(x.substr(j));
            }
            
            for(string p : prefix) {
                for(string s : suffix) {
                    string k = p + "#" + s;
                    if(mp.find(k) == mp.end())
                    {
                        mp[k] = i;
                    }
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string k = prefix + "#" + suffix;
        if(mp.find(k) != mp.end())
            return mp[k];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(int argc, const char * argv[]) {
    WordFilter *x = new WordFilter({"bccbacbcba"});
    cout<<x->f("bccbacbcba","a");
    return 0;
}

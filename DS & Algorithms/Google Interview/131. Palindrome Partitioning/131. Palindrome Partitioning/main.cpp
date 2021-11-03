//
//  main.cpp
//  131. Palindrome Partitioning
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

unordered_map<string, vector<vector<string>>> mp;
    unordered_map<string, bool> ispal;
    
    bool isPalin(string s) {
        
        if(ispal.count(s)) {
            return ispal[s];
        }
        
        int i = 0;
        int j = s.size()-1;
        
        while(i < j) {
            if(s[i++] != s[j--])
                return ispal[s] = false;
        }
        
        return ispal[s] = true;
    }
    
    vector<vector<string>> solve(string s) {
        int n = s.size();
        
        if(s.size() == 1)
            return {{s}};
        
        if(s.size() == 0){
            return {};
        }
        
        if(mp.count(s))
            return mp[s];
        
        vector<vector<string>> ans;
        
        for(int i = 1; i <= n; i++) {
            string prev = s.substr(0,i);
            
            if(isPalin(prev)) {
                vector<vector<string>> tempans = solve(s.substr(i));
                
                if(tempans.size() == 0) {
                    ans.push_back({{prev}});
                }
                
                for(auto f : tempans) {
                    f.push_back(prev);
                    ans.push_back(f);
                }
            }
        }
        
        return mp[s] = ans;
        
    }
    
    
    vector<vector<string>> partition(string s) {
        ispal.clear();
        mp.clear();
        
        vector<vector<string>> ans = solve(s);
        
        for(int i = 0; i < ans.size(); i++) {
            vector<string> temp = ans[i];
            vector<string> x = vector<string>(temp.rbegin(), temp.rend());
            ans[i] = x;
        }
        
        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<vector<string>> ans = partition("abb");
    return 0;
}

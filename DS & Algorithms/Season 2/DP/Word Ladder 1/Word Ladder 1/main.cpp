//
//  main.cpp
//  Word Ladder 1
//
//  Created by Giriraj Saigal on 11/08/21.
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

long long solve(string beginWord, string endWord, set<string> s) {
        if(beginWord == endWord)
            return 1;
        
        long long ans = INT_MAX;
        string x = beginWord;
        for(int i = 0; i < beginWord.size(); i++) {
            for(int j = 0; j < 26; j++) {
                char c = 'a' + j;
                char t = beginWord[i];
                beginWord[i] = c;
                
                if(s.find(beginWord) != s.end() && beginWord != x) {
                    s.erase(beginWord);
                    ans = min(solve(beginWord, endWord, s), ans);
                    s.insert(beginWord);
                }
                
                beginWord[i] = t;
            }
        }
        
        return ans+1;
}
    
int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    set<string> s;
    
    for(auto k : wordList){
        s.insert(k);
    }

    if(s.find(endWord) == s.end())
        return 0;
    
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    
    map<string, int> mp;
    
    for(int i = 0; i < wordList.size(); i++) {
        mp[wordList[i]] = 1000000;
    }
    
    while(q.size() > 0) {
        string x = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if(x == endWord)
            return mp[x];
        
        string f = x;
        for(char c = 'a'; c <= 'z'; c++) {
            for(int i = 0; i < x.size(); i++) {
                char t = x[i];
                x[i] = c;
                
                if(s.find(x) != s.end() && x!=f) {
                    if(level+1 < mp[x]) {
                        mp[x] = level+1;
                        q.push({x,level+1});
                    }
                }
                x[i] = t;
            }
        }
    }
    
    return 0;
    
}

int main(int argc, const char * argv[]) {
    cout << ladderLength("hit",
                         "cog",
                         {"hot","dot","tog","cog"}) <<endl;
    return 0;
}

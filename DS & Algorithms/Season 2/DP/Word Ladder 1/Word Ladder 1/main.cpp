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
    
    long long ans = solve(beginWord, endWord, s);
    
    if(ans == (long long)INT_MAX + (long long)1)
        return 0;
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << ladderLength("hot", "dog", {"hot","dog"}) <<endl;
    return 0;
}

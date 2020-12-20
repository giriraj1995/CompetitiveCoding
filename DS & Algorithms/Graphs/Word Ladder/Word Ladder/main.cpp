//
//  main.cpp
//  Word Ladder
//
//  Created by Giriraj Saigal on 20/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

int ladder(string a, string b, unordered_set<string> dic) {
    
    if(a == b)
        return 0;
    
    unordered_map<string, int> s;
    
    queue<string> q;
    s[a] = 1;;
    q.push(a);
    
    while(q.size() > 0) {
        string inter = q.front();
        int level = s.find(inter)->second;
        q.pop();
        
        for(int i = 0; i < 26; i++) {
            char c = i + 'a';
            string check = inter;
            for(int j = 0; j < inter.size(); j++) {
                check = inter;
                check[j] = c;
                
                if(check == b)
                    return level + 1;
                
                if(dic.find(check) != dic.end() && s.find(check) == s.end()){
                    q.push(check);
                    s.insert({check,level+1});
                }else if(s.find(check) != s.end()) {
                    if(level + 1 < s.find(check)->second) {
                        s.find(check)->second = level+1;
                    }
                }
            }
        }
    }
    
    return 0;
}

int solve(string A, string B, vector<string> C) {
    
    unordered_set<string> dic;
    
    for(string s : C) {
        dic.insert(s);
    }
    
    return ladder(A, B, dic);
}


int main(int argc, const char * argv[]) {
    cout<<solve("hit", "cog", {"hot", "dot", "dog", "lot", "log"})<<endl;
    return 0;
}

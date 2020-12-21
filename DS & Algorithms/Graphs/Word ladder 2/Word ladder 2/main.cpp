//
//  main.cpp
//  Word ladder 2
//
//  Created by Giriraj Saigal on 21/12/20.
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

void solve(string start, string end, unordered_set<string> dic, vector<string> seq,
    vector<vector<string>> &ans) {
        
    if(start == end) {
        //seq.push_back(end);
        
        if(ans.size() == 0)
            ans.push_back(seq);
        else{
            
            int curr = seq.size();
            if(ans.begin()->size() > curr) {
                ans.clear();
                ans.push_back(seq);
            }else if(ans.begin()->size() == curr){
                ans.push_back(seq);
            }
        }
        
        return;
    }
    
    for(char c = 'a'; c <= 'z'; c++) {
        
        for(int i = 0; i < start.size(); i++) {
            string temp = start;
            temp[i] = c;
            
            if(temp == start)
                continue;
            
            if(dic.find(temp) == dic.end())
                continue;
            
            dic.erase(temp);
            seq.push_back(temp);
            
            //dfs
            solve(temp, end, dic, seq, ans);
            
            seq.pop_back();
            //dic.insert(temp);
            
        }
    }
}

vector<vector<string> > findLadders(string start, string end, vector<string> dict) {
    vector<string> seq;
    vector<vector<string>> ans;
    unordered_set<string> dic;
    
    for(int i = 0; i < dict.size(); i++) {
        dic.insert(dict[i]);
    }
    
    dic.insert(end);
    
    seq.push_back(start);
    solve(start, end, dic, seq, ans);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<vector<string> > ans = findLadders("hit", "cog", {"hot","dot","dog","lot","log"});
    return 0;
}

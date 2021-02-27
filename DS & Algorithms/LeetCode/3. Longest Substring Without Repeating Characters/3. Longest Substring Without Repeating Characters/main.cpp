//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by Giriraj Saigal on 26/02/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n <= 1)
        return n;
    
    int i = 0;
    int j = 1;
    map<char,int> db;
    db[s[0]] = 0;
    int len = 1;
    
    while(j < n){
        if(db.find(s[j]) == db.end()) {
            db[s[j]] = j;
        }else{
            int x = db[s[j]]+1;
            while(i < x) {
                db.erase(s[i]);
                i++;
            }
            continue;
        }
        
        if(j-i+1 > len) {
            len = j-i+1;
        }
        
        j++;
    }
    
    if(j-i > len) {
        len = j-i;
    }
    
    return len;
}

int main(int argc, const char * argv[]) {
    lengthOfLongestSubstring("abba");
    return 0;
}

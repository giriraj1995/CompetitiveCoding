//
//  main.cpp
//  Scrambled String 2
//
//  Created by Giriraj Saigal on 24/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

bool solve(string A, string B) {
    
    if(A.size() != B.size())
        return false;
    
    if(A.compare(B) == 0)
    {
        return true;
    }

    if(A.size() <= 1){
        return false;
    }
    
    bool ans = false;
    int n = (int)A.length();
    for(int i = 1; i < A.size(); i++) {
        
        bool first = solve(A.substr(0, i), B.substr(n-i, i));
        bool second = solve(A.substr(i, n-i), B.substr(0, n-i));
        bool cond1 = first && second;
        
        first = solve(A.substr(0,i), B.substr(0,i));
        second = solve(A.substr(i,n-i), B.substr(i,n-i));
        bool cond2 = first && second;;
        
        if(cond1 || cond2)
            return true;
        
    }
    
    return ans;
    
}
    
    
int t[1002][1002];

map<pair<string,string>, bool> store;
int solve2(const string A, const string B)
{
    pair<string, string> pt = make_pair(A,B);
    if(store.find(pt) != store.end())
        return store[pt];
   
    if(A.compare(B) == 0)
    {
        return true;
    }
    
    if(A.size() <= 1)
    {
        return false;
    }
    
    int n = (int)A.length();
    bool flag = false;
    
    for (int i = 1; i < n; i++) {
        
        bool first = solve2(A.substr(0,i), B.substr(n-i,i));
        bool second = solve2(A.substr(i,n-i), B.substr(0,n-i));
        bool cond1 = first && second;
        
        first = solve2(A.substr(0,i), B.substr(0,i));
        second = solve2(A.substr(i,n-i), B.substr(i,n-i));
        bool cond2 = first && second;;
        
        if(cond1 || cond2)
            return store[pt] = true;
    }
    return store[pt] = flag;
}


int isScramble(const string A, const string B) {
    
    if(A.length() != B.length())
        return 0;
        
    if(A.length() == 0 && B.length() == 0)
        return 1;
        
    return solve2(A,B);
}


int main(int argc, const char * argv[]) {
    string A = "abbbcbaaccacaacc";
    string B = "acaaaccabcabcbcb";
    
    solve(A, B);
    
    cout<<endl;
    return 0;
}

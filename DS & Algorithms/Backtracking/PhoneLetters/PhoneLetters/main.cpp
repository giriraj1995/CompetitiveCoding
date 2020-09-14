//
//  main.cpp
//  PhoneLetters
//
//  Created by Giriraj Saigal on 11/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(string i, string o, map<string,char> &u){
    
    if(i.size() == 0)
    {
        u.insert(make_pair(o, '9'));
        return;
    }
    
    char c = i[0];
    i.erase(i.begin());
    int t = (c) - '0';
    
    if(c == '0' || c == '1'){
        solve(i,o+c,u);
    }else if(c == '2' ||c == '3' ||c == '4' ||c == '5' ||c == '6'){
        solve(i,o+(char)('a' + (t-2)*3), u);
        solve(i,o+(char)('a' + (t-2)*3 + 1), u);
        solve(i,o+(char)('a' + (t-2)*3 + 2), u);
    }else if(c == '7'){
        solve(i,o+(char)('a' + (t-2)*3), u);
        solve(i,o+(char)('a' + (t-2)*3 + 1), u);
        solve(i,o+(char)('a' + (t-2)*3 + 2), u);
        solve(i,o+(char)('a' + (t-2)*3 + 3), u);
    }else if(c == '8'){
        solve(i,o+(char)('a' + (t-2)*3 + 1), u);
        solve(i,o+(char)('a' + (t-2)*3 + 2), u);
        solve(i,o+(char)('a' + (t-2)*3 + 3), u);
    }else if(c == '9'){
        solve(i,o+(char)('a' + (t-2)*3 + 1), u);
        solve(i,o+(char)('a' + (t-2)*3 + 2), u);
        solve(i,o+(char)('a' + (t-2)*3 + 3), u);
        solve(i,o+(char)('a' + (t-2)*3 + 4), u);
    }
}

vector<string> letterCombinations(string A) {
    map<string, char> u;
    vector<string> ans;
    string o = "";
    
    solve(A, o, u);
    
    map<string, char>::iterator itr;
    
    for(itr = u.begin(); itr != u.end(); itr++){
        ans.push_back(itr->first);
    }

    return ans;
    
}
int main(int argc, const char * argv[]) {
    vector<string> y = letterCombinations("98050");
    return 0;
}

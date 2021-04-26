//
//  main.cpp
//  Generate all Parentheses II
//
//  Created by Giriraj Saigal on 26/04/21.
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

void solve(int x, int y, string inp, vector<string> &ans) {
    if(x == y && x == 0) {
        ans.push_back(inp);
        return;
    }
    
    if(x < y && x != 0) {
        inp.push_back('(');
        solve(x-1, y, inp, ans);
        inp.pop_back();
        inp.push_back(')');
        solve(x, y-1, inp, ans);
        inp.pop_back();
        return;
    }
    
    if(x == y && x != 0) {
        inp.push_back('(');
        solve(x-1, y, inp, ans);
        inp.pop_back();
        return;
    }
    
    if(x < y && x == 0) {
        inp.push_back(')');
        solve(x, y-1, inp, ans);
        inp.pop_back();
        return;
    }
}

vector<string> generateParenthesis(int A) {
    int inB = A;
    int ouB = A;
    string inp = "";
    vector<string> ans;
    solve(inB, ouB, inp, ans);
    sort(ans.begin(), ans.end());
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

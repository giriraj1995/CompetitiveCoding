//
//  main.cpp
//  Longest Valid Parenthesis
//
//  Created by Giriraj Saigal on 08/11/20.
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

bool isValid(int i, int j, string exp) {
    
    stack<char> s;
    
    for(int k = i ; k <= j; k++) {
        
        if(exp[k] == '(')
            s.push(exp[k]);
        else{
            
            if(s.size() == 0)
                return false;
            
            s.pop();
        }
    }
    
    return s.size() == 0 ? true : false;
    
}

int solve(int i, int j, string exp) {
    
    if(i >= j)
        return 0;
    
    if(isValid(i, j, exp)) {
        return j - i + 1;
    }
    
    int length = 0;
    for(int k = i+1; k <= j ; k++) {
        length = max(length, max(solve(i, k-1, exp), solve(k, j, exp)));
    }
    
    return length;
}

int main(int argc, const char * argv[]) {
    string exp = ")()()()()())";
    cout<<solve(0, exp.size()-1, exp);

    return 0;
}

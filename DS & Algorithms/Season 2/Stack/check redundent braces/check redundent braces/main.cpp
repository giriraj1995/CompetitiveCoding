//
//  main.cpp
//  check redundent braces
//
//  Created by Giriraj Saigal on 16/04/21.
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

int braces(string A) {
    stack<pair<int,int>> s;
    int n = A.size();
    bool check = false;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(' && i == 0) {
            s.push({1,i});
        }else if(A[i] == '(' && i != 0) {
            if(A[i-1] == '(') {
                check = true;
            }
            s.push({1,i});
        }else if(A[i] == ')') {
            if(i < n-1 && A[i+1] == ')' && check) {
                return 1;
            }
            
            if(s.top().second == i-2)
                return 1;
            
            if(A[i+1] != ')')
                check = false;
            
            s.pop();
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    braces("(a)");
    return 0;
}

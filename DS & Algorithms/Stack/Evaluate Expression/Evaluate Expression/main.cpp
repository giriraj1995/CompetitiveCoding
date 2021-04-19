//
//  main.cpp
//  Evaluate Expression
//
//  Created by Giriraj Saigal on 19/04/21.
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

int evalRPN(vector<string> A) {
    stack<int> s;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i].compare("+") == 0
        || A[i].compare("-") == 0
        || A[i].compare("*") == 0
        || A[i].compare("/") == 0) {
            if(A[i].compare("+") == 0) {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x+y);
            }
            if(A[i].compare("-") == 0) {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y-x);
            }
            if(A[i].compare("*") == 0) {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x*y);
            }
            if(A[i].compare("/") == 0) {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y/x);
            }
        }else{
            s.push(stoi(A[i]));
        }
    }
    
    return s.top();
}


int main(int argc, const char * argv[]) {
    cout<<evalRPN({"4", "13", "5", "/", "+"})<<endl;
    return 0;
}

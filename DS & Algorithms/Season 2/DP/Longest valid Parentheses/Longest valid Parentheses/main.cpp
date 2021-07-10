//
//  main.cpp
//  Longest valid Parentheses
//
//  Created by Giriraj Saigal on 10/07/21.
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

int longestValidParentheses(string A) {
    if(A.size() <= 1)
        return 0;
    
    stack<int> s;
    s.push(-1);
    int len = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(')
            s.push(i);
        else{
            s.pop();
            if(s.size() == 0)
                s.push(i);
            else
                len = max(len, i - s.top());
        }
    }
    
    return len;
}


int main(int argc, const char * argv[]) {
    cout<<longestValidParentheses(")()))(())((())))))())()(((((())())((()())(())((((())))())((()()))(()(((()()(()((()()))(())()))(((") <<endl;
    cout<<longestValidParentheses(")()())") <<endl;
    return 0;
}

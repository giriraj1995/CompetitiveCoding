//
//  main.cpp
//  Balanced Parenthese
//
//  Created by Giriraj Saigal on 12/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

string isBalanced(string st) {
    stack<char> s;
    string Y = "YES";
    string N = "NO";

    for(char c : st){
        if(c == '{' || c == '(' || c == '['){
            s.push(c);
        }else if(c == '}'){

            if(s.size() == 0)
                return N;

            char ch = s.top();
            s.pop();
            if(ch != '{'){
                return N;
            }
        }else if(c == ')'){

            if(s.size() == 0)
                return N;

            char ch = s.top();
            s.pop();
            if(ch != '('){
                return N;
            }
        }else if(c == ']'){

            if(s.size() == 0)
                return N;

            char ch = s.top();
            s.pop();

            if(ch != '['){
                return N;
            }
        }
    }

    return (s.size() == 0)?Y:N;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

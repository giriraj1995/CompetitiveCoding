//
//  main.cpp
//  Redundent Braces
//
//  Created by Giriraj Saigal on 10/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int prec(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else
        return 0;
}

int braces(string A) {
    
    int flag = 0;
    stack<char> s;
    s.push('N');
    string ans;
    
    for(int i = 0; i < A.size(); i++)
    {
        char c = A[i];
        
        if(isdigit(c) || isalpha(c)){
            ans += c;
        }
        
        else if(c == '(')
            s.push(c);
            
        else if(c == ')')
        {
            if(s.top() == '(')
                return 1;
                
            while(s.size() != 0 && s.top() != '('){
                char c1 = s.top();
                s.pop();
                ans+=c1;
                flag = 0;
            }
            
            if(s.size() != 0 && s.top() == '('){
                flag = 1;
                s.pop();
            }
        }
        
        else
        {
            if(prec(c) > prec(s.top()))
                s.push(c);
            else
            {
                while(s.size() != 0 && prec(c) <= prec(s.top())){
                    char c1 = s.top();
                    s.pop();
                    ans+=c1;
                }
                    
                s.push(c);
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    cout<<braces("((a+b))")<<endl;
    return 0;
}

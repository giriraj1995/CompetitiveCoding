//
//  main.cpp
//  Infix to PostFix
//
//  Created by Giriraj Saigal on 09/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int precedenceChart(char c){
    if(c == '+' || c == '-'){
        return 0;
    }else if(c == '*' || c == '/'){
        return 1;
    }
    
    return -1;
}

string InFixToPostFix(string x){
    string ans;
    
    stack<char> s;
    
    for(char c : x){
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)){
            ans.push_back(c);
        } else {
            while(s.size() != 0 && precedenceChart(c) <= precedenceChart(s.top())){
                char m = s.top();
                s.pop();
                ans.push_back(m);
            }
            s.push(c);
        }
    }
    
    while(s.size() != 0){
        char m = s.top();
        ans.push_back(m);
        s.pop();
    }
    
    return ans;
}

int evaluate(string x){
    stack<int> s1;
    for(char c :x){
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)){
            s1.push(c-'0');
        }else{
            if(c == '+'){
                int p = s1.top();
                s1.pop();
                int q = s1.top();
                s1.pop();
                
                int r = p + q;
                
                s1.push(r);
            }else if(c == '*'){
                int p = s1.top();
                s1.pop();
                int q = s1.top();
                s1.pop();
                
                int r = p * q;
                
                s1.push(r);
            }else if(c == '-'){
                int p = s1.top();
                s1.pop();
                int q = s1.top();
                s1.pop();
                
                int r = q - p;
                
                s1.push(r);
            }else if(c == '/'){
                int p = s1.top();
                s1.pop();
                int q = s1.top();
                s1.pop();
                
                int r = q / p;
                
                s1.push(r);
            }
        }
    }
    
    return s1.top();
}

int main(int argc, const char * argv[]) {
    string x = "6+7*1-2";
    x = InFixToPostFix(x);
    cout<<evaluate(x)<<endl;
    return 0;
}

//
//  main.cpp
//  Balanced Parenthesis
//
//  Created by Giriraj Saigal on 01/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> A;

bool isBalanced(string x){
    
    stack<char> s;

    for(char c : x){
        if(c == '('){
            
            if(s.size() == 6)
                return false;
            
            s.push(c);
        }
        else if(c == ')'){
            
            if(s.size() == 0)
                return false;
            
            s.pop();
        }
    }
    
    return s.empty();
}

bool isPresent(vector<string> x, string y){
    
    for(string i : x){
        
        if(i == y)
            return true;
    }
    
    return false;
}


void solve(int open, int close, string out, int n){
    
    if((open == 0 && close == 0) || out.size() == n){
        if(isBalanced(out)){
            if(!isPresent(A,out)){
                A.push_back(out);
            }
        }
        return;
    } else if(open == 0){
        solve(0, close-1, out + ")", n);
    } else if(close == 0)
        solve(open-1,0, out + "(", n);
    
    solve(open-1,close,out+"(", n);
    solve(open,close-1,out+")", n);
}


int main(int argc, const char * argv[]) {
    int n = 5;
    solve(n,n,"", 10);
    
    for(string i:A){
        cout<<i<<endl;
    }
    cout<<"count:"<<A.size();
    cout<<endl;
    return 0;
}

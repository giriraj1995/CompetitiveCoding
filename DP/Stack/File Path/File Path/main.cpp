//
//  main.cpp
//  File Path
//
//  Created by Giriraj Saigal on 10/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

string simplifyPath(string A) {
    
    string x;
    int n = A.size();
    stack<string> s;
    int flag = 0;
    
    for(int i = 0; i < n ;){
        
        char c = A[i];
        
        if(c == '/' && flag == 0){
            flag = 1;
            x.clear();
            i++;
        }
        else if(c == '/' && flag == 1)
        {
            if(x.size() == 0)
            {
            }
            else if(x.compare(".") == 0)
            {
            }
            else if(x.compare("..") == 0)
            {
                if(s.size() != 0)
                {
                    s.pop();
                }
            }else
            {
                s.push(x);
            }
            flag = 0;
        }
        else
        {
            x.push_back(c);
            i++;
        }
    }
    
    string ans = "";
    
    stack<string> s1;
    
    while(s.size() != 0){
        string t = s.top();
        s.pop();
        s1.push(t);
    }
    
    while(s1.size() != 0){
        ans = ans + "/";
        string t = s1.top();
        s1.pop();
        ans = ans + t;
        
    }
    
    if(ans.size() == 0){
        return "/";
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<simplifyPath("/home//foo/")<<endl;
    return 0;
}

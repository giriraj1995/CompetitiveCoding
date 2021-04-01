//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by Giriraj Saigal on 04/03/21.
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

bool isValid(string s) {
       stack<char> st;
       
       for(char c : s) {
           if(c == '(' || c == '{' || c == '[') {
               st.push(c);
           }else{
               
               if(st.size() == 0)
                   return false;
               
               char t = st.top();
               st.pop();
               
               if(t == '(') {
                   if(c != ')')
                       return false;
                   else{
                       continue;
                   }
               }
               
               if(t == '{') {
                   if(c != '}')
                       return false;
                   else{
                       continue;
                   }
               }
               
               if(t == '[') {
                   if(c != ']')
                       return false;
                   else{
                       continue;
                   }
               }
           }
       }
       
       return true;
   }

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

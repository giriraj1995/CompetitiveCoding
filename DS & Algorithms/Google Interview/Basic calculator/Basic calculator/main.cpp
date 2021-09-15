//
//  main.cpp
//  Basic calculator
//
//  Created by Giriraj Saigal on 15/09/21.
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



    bool isoperator(char c) {
        if(c == '+' || c == '-'){
            return true;
        }
        return false;
    }
    
    int precedence(char c) {
        if(c == '+' || c == '-'){
            return 1;
        }
        
        if(c == '(')
            return 2;
        
        return 0;
    }
    
    int calculate(string s) {
        long long ans = 0;
        vector<char> vec;
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == ' ')
                continue;
            else if(c == '(')
                st.push('(');
            else if(c == ')'){
                while(st.top() != '('){
                    vec.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
            }
            else if(isoperator(c)){
                while(st.size() > 0 && precedence(c) >= precedence(st.top())){
                    vec.push_back(st.top());
                    st.pop();
                }
                
                st.push(c);
            }else{
                vec.push_back(c);
            }
        }
        
        while(st.size() != 0){
            vec.push_back(st.top());
            st.pop();
        }
        
        stack<int> st2;
        
        for(int i = 0; i < vec.size(); i++) {
            if(isoperator(vec[i])){
                int x = st2.top();
                st2.pop();
                int y = st2.top();
                st2.pop();
                int z;
                if(vec[i] == '+')
                    z = x+y;
                else
                    z = y-x;
                st2.push(z);
            }else{
                st2.push(vec[i] - '0');
            }
        }
               
        return st2.top();
    }

int calculate1(string s) {
        int sum = 0;
        int sign = 1;
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] <= '9' && s[i] >= '0') {
                int num = 0;
                
                while(i < s.size() && s[i] <= '9' && s[i] >= '0') {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                
                sum += num*sign;
                i--;
            }else if(s[i] == '-'){
                sign = -1;
            }else if(s[i] == '+'){
                sign = 1;
            }else if(s[i] == '('){
                st.push(sum);
                st.push(sign);
                
                sum = 0;
                sign = 1;
            }else if(s[i] == ')'){
                int sig = st.top();
                st.pop();
                
                sum = sig * sum;
                int x = st.top();
                st.pop();
                
                sum = sum + x;
            }
        }
        
        return sum;
    }

int main(int argc, const char * argv[]) {
    cout << calculate1("(1+(4+5+2)-30)+(6+8)") << endl;
    return 0;
}

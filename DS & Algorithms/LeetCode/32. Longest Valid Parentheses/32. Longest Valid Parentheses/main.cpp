//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by Giriraj Saigal on 25/03/21.
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
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        }else{
            if(st.size() != 0) {
                st.pop();
            }
            
            if(st.size() != 0) {
                ans = max(ans, i - st.top());
            }
            
            else {
                st.push(i);
            }
            
            
        }
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    longestValidParentheses(")()())");
    return 0;
}

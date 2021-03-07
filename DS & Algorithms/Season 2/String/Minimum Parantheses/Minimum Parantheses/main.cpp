//
//  main.cpp
//  Minimum Parantheses
//
//  Created by Giriraj Saigal on 07/03/21.
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

int solve(string A) {
    stack<char> st;
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            st.push(A[i]);
        }else{
            if(st.size() == 0) {
                ans++;
            }else{
                st.pop();
            }
        }
    }
    
    return ans + st.size();
}


int main(int argc, const char * argv[]) {
    return 0;
}

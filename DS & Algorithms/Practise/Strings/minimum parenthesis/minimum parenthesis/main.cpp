//
//  main.cpp
//  minimum parenthesis
//
//  Created by Giriraj Saigal on 28/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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
    
    stack<char> s;
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            s.push('(');
        }else{
            if(s.size() > 0) {
                s.pop();
            }else{
                ans++;
            }
        }
    }
    
    ans += s.size();
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  word break 2 again
//
//  Created by Giriraj Saigal on 23/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void solve(string A, vector<string> B, string prev, vector<string> &out) {
    
    if(A == "") {
        out.push_back(prev);
        return;
    }
    
    for(int i = 0; i < A.size(); i++) {
        
        string left = A.substr(0, i+1);
        if(find(B.begin(), B.end(), left) != B.end()){
            
            string right = A.substr(i+1);
            string new_prev;
            if(prev == ""){
                new_prev = left;
            }else{
                new_prev = prev + " " + left;
            }
            
            solve(right, B, new_prev, out);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    vector<string> ans;
    solve("catsanddog", {"cat", "cats", "and", "sand", "dog"}, "", ans);
    return 0;
}

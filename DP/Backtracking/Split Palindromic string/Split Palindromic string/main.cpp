//
//  main.cpp
//  Split Palindromic string
//
//  Created by Giriraj Saigal on 12/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool isPallindrome(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void fnc(string A, vector<string> &v, vector<vector<string>> &result) {
    // exit condition
    if (A.length() <= 0) {
        result.push_back(v);
        return;
    }
    
    int n = A.length();
    for(int i = 0; i < n; i++) {
        
        string copyString = A;
        string firstPart = A.substr(0, i + 1);
        string secondPart = A.substr(i + 1, n - i);
        
        if(isPallindrome(firstPart)) {
            v.push_back(firstPart);
            fnc(secondPart, v, result);
            // backtrack
            v.pop_back();
        }
    }
}

vector<vector<string> > partition(string A) {
    vector<vector<string>>result;
    vector<string>v;
    fnc(A, v, result);
    return result;
}


int main(int argc, const char * argv[]) {
    partition("efe");
    return 0;
}

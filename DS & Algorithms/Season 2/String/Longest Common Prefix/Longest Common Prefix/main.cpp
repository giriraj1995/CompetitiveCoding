//
//  main.cpp
//  Longest Common Prefix
//
//  Created by Giriraj Saigal on 07/02/21.
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

string longestCommonPrefix(vector<string> A) {
    int len = INT_MAX;
    int mod = 1000000007;
    
    for(string x : A) {
        len = min(len, (int)x.size());
    }
    
    
    vector<map<char,int>> v(len);
    int ans = len;
    for(string x : A) {
        int i = 0;
        int j = 0;
        
        while(i < len && j < x.size()) {
            v[i][x[j]]++;
            
            if(v[i].size() > 1 && ans > i) {
                ans = min(ans, i);
                break;
            }
            
            if(i >= ans) {
                break;
            }
            
            i++;
            j++;
        }
    }
    string k = "";
    
    for(int i = 0; i < ans; i++) {
        k += A[0][i];
    }
    
    return k;
}


int main(int argc, const char * argv[]) {
    longestCommonPrefix({"abcdefgh", "aefghijk", "abcefgh"});
    return 0;
}

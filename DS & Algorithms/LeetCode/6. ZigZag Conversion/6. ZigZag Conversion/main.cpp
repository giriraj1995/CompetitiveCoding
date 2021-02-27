//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by Giriraj Saigal on 26/02/21.
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

string convert(string s, int numRows) {
    int n = s.size();
    int i = 0;
    
    if(numRows == 1)
        return s;
    
    vector<vector<char>> hex(numRows);
    int j = 0;
    bool down = true;
    bool up = false;
    
    while(i < n) {
        hex[j].push_back(s[i]);
        
        if(j == 0) {
            down = true;
            up = false;
        }else if(j == numRows-1) {
            down = false;
            up = true;
        }
        
        if(down) {
            j++;
        }else{
            j--;
        }
        
        i++;
    }
    
    string ans = "";
    
    for(int i = 0; i < numRows; i++) {
        for(char c : hex[i]) {
            ans += c;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cout<<convert("girirajsaigal",4);
    return 0;
}

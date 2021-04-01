//
//  main.cpp
//  13. Roman To Integer
//
//  Created by Giriraj Saigal on 08/03/21.
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

int change(char c) {
    if(c == 'I')
        return 1;
    if(c == 'V')
        return 5;
    if(c == 'X')
        return 10;
    if(c == 'L')
        return 50;
    if(c == 'C')
        return 100;
    if(c == 'D')
        return 500;
    else
        return 1000;
}

int romanToInt(string s) {
    int j = s.size()-1;
    int ans = 0;
    
    while(j > 0) {
        int no = change(s[j]);
        int pre = change(s[j-1]);
        
        if(pre < no) {
            ans += no-pre;
            j -= 2;
        }else{
            ans += no;
            j -= 1;
        }
    }
    
    if(j == 0)
        ans += change(s[0]);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    romanToInt("MCMXCIV");
    return 0;
}

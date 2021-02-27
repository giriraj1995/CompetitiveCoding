//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by Giriraj Saigal on 27/02/21.
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

int myAtoi(string s) {
    int n = s.size();
    
    if(n == 0)
        return 0;
    
    int i = 0;
    while(s.size() > 0 && s[i] == ' '){
        i++;
    }
    
    bool isNeg = false;
    bool sign = false;
    long long no = 0;
    
    while(i < n) {
        if(s[i] == '+' && !sign) {
            i++;
            sign = true;
        }else if(s[i] == '-' && !sign){
            isNeg = true;
            sign = true;
            i++;
        }else if(s[i] >= '0' && s[i] <= '9'){
            sign = true;
            no = (no*10) + (s[i] - '0');
            
            if(isNeg) {
                if((no * (long long)-1) < INT_MIN)
                    return INT_MIN;
            }else{
                if(no > INT_MAX) {
                    return INT_MAX;
                }
            }
            
            i++;
        }else{
            break;
        }
    }
    
    return isNeg ? no * -1 : no;
}

int main(int argc, const char * argv[]) {
    cout<<myAtoi("-2147483648")<<endl;
    return 0;
}

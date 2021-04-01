//
//  main.cpp
//  Divide Integers
//
//  Created by Giriraj Saigal on 30/03/21.
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

int divide(int A, int B) {
    long sign = 1;
    
    if((A < 0 && B > 0) || (A > 0 && B < 0))
        sign = -1;
    long p = A;
    long q = B;
    long a = abs(p);
    long b = abs(q);
    
    long ans = 0;
    
    long x = b;
    
    while(x <= a) {
        int i = 0;
        do{
            if(x <= a) {
                i++;
                x = x * 2;
            }else {
                break;
            }
        }while(x < a);
        ans += pow(2,i-1);
        a = a - b*pow(2,i-1);
        x = b;
    }
    
    long ansfinal = sign * ans;
    cout<<INT_MAX<<endl;
    cout<<ansfinal;
    if((long)(ansfinal) > (long)INT_MAX) {
        INT_MAX;
    }
    
    return ansfinal;
}


int main(int argc, const char * argv[]) {
    cout<<divide(-2147483648,-1)<<endl;
    return 0;
}

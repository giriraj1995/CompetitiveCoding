//
//  main.cpp
//  Divide integers
//
//  Created by Giriraj Saigal on 04/01/21.
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

int divide(int b, int a) {
    int sign = -1;
    
    if((b < 0 && a < 0) || (b > 0 && a > 0))
        sign = 1;
    
    if(b == INT_MIN) {
        if(a == -1) {
            return INT_MAX;
        }
    }
    
    long x = a < 0 ? -(long)(a) : (a);
    long y = b < 0 ? -(long)(b) : (b);
    
    if(x > y) {
        return 0;
    }
    
    if(y == 0)
        return 0;
    
    if(x == 1)
        return sign * y;
        
    long ans = 0;
    long mul = 1;
    
    while(y > x) {
        if(y > x * mul) {
            mul = mul * 2;
        }else{
            ans += mul/2;
            y = y - x * (mul/2);
            mul = 1;
        }
    }
    
    if(ans == 0)
        return sign * 1;
    
    if(ans * sign > INT_MAX) {
        return INT_MAX;
    }
    
    return ans * sign;
}

int main(int argc, const char * argv[]) {
    cout<<divide(-5700836, -7169730)<<endl;
    return 0;
}

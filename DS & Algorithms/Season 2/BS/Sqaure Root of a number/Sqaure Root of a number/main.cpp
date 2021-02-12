//
//  main.cpp
//  Sqaure Root of a number
//
//  Created by Giriraj Saigal on 12/02/21.
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

int sqrt(int A) {
    if(A == 1)
        return 1;
    
    long long l = 2;
    long long h = A;
    
    while(l <= h) {
        long long m = l + (h-l)/2;
        if((long long)m * m == (long long)A) {
            return m;
        }else{
            if((long long)m*m < (long long)A) {
                l = m+1;
            }else{
                h = m-1;
            }
        }
    }
    
    return h;
}


int main(int argc, const char * argv[]) {
    sqrt(103);
    return 0;
}

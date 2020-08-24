//
//  main.cpp
//  gcd
//
//  Created by Giriraj Saigal on 23/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int gcd(int x, int y){
    int rem;
    int max, min;
    if(x > y){
        max = x;
        min = y;
    } else {
        max = y;
        min = x;
    }
    while(min > 0){
        rem = max % min;
        max = min;
        min = rem;
    }
    return max;
}

int cpFact(int A, int B) {
    // for(int i = A; i > 0; i--){
    //     if(gcd(i,B) == 1 && A%i == 0)
    //         return i;
    // }
    
    if(gcd(A,B) == 1)
        return A;
    else{
        int i = 2;
        while(i && i<=A){
            if(A%i == 0 && B%i == 0){
                if(gcd(A/i,B) == 1)
                    return A/i;
            }
            i++;
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    cpFact(24,36);
    return 0;
}

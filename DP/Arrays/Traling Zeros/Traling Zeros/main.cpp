//
//  main.cpp
//  Traling Zeros
//
//  Created by Giriraj Saigal on 20/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long long int fact(int x){
    int y=x;
    long long int mul = 1;
    while(y > 0)
    {
        mul *= y;
        y = y-1;
    }
    return mul;
}

int trailingZeroes(int A) {
    
    if(A == 0)
        return 0;
    
    long long int x = fact(A);
    string xx = to_string(x);
    int n = xx.size();
    int z = 0;
    for(int i = n-1; i >=0 ; i--)
    {
        if(xx[i] == '0')
            z++;
        else
            break;
            
    }
    
    return z;
}


int main(int argc, const char * argv[]) {
    trailingZeroes(9247);
    return 0;
}

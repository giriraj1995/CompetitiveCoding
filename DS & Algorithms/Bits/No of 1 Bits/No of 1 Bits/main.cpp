//
//  main.cpp
//  No of 1 Bits
//
//  Created by Giriraj Saigal on 27/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numSetBits(unsigned int A) {
    unsigned int x = A;
    int sum = 0;
    while(x){
        if(x & 1){
            sum++;
        }
        x = x>>1;
    }
    
    return sum;
}


int main(int argc, const char * argv[]) {
    numSetBits(11);
    return 0;
}

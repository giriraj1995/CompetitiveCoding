//
//  main.cpp
//  Reverse Bits
//
//  Created by Giriraj Saigal on 09/03/21.
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

unsigned int reverse(unsigned int A) {
    unsigned int x = 0;
    for(int i = 0; i < 32; i++) {
        int sh = A>>i;
        if(sh & 1) {
            x = x | 1<<(31-i);
        }
    }
    return x;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

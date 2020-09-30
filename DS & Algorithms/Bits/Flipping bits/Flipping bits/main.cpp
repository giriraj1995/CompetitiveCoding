//
//  main.cpp
//  Flipping bits
//
//  Created by Giriraj Saigal on 29/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


long flippingBits(long n) {
    long flipper = pow(2,32)-1;
    return flipper^n;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<flippingBits(1);
    return 0;
}

//
//  main.cpp
//  Trailing Zeros in Factorial
//
//  Created by Giriraj Saigal on 05/02/21.
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

int trailingZeroes(int A) {
    int ans = 0;
    
    while(A > 1) {
        ans += A/5;
        A = A/5;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {

    return 0;
}

//
//  main.cpp
//  Traling zeros
//
//  Created by Giriraj Saigal on 01/01/21.
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

int solve(int A) {
    int count = 0;
    for(int i = 0; i <= 31; i++) {
        int k = A >> i;
        if(k & 1) {
            break;
        }
        count++;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

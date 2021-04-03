//
//  main.cpp
//  Different Bits Sum Pairwise
//
//  Created by Giriraj Saigal on 03/04/21.
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

int cntBits(vector<int> A) {
    vector<int> x = vector<int>(32, 0);
    int mod = 1000000007;
    
    int n = (int)A.size();
    for(int no : A) {
        for(int i = 0; i < 32; i++) {
            if((no >> i) & 1){
                x[i]++;
            }
        }
    }

    long long ans = 0;
    
    for(int i = 0; i < 32; i++) {
        if((x[i] == 0) || ((n - x[i]) == 0))
            continue;
        ans = (ans + x[i] * (n - x[i])) % mod;
    }
    
    ans = (ans * 2) % mod;
    
    return 0;
}


int main(int argc, const char * argv[]) {
    cntBits({81, 13, 2, 7, 96 });
    return 0;
}

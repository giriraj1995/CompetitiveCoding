//
//  main.cpp
//  Distinct Initial Matrices
//
//  Created by Giriraj Saigal on 18/01/21.
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

int cntMatrix(vector<int> A) {
    long mod = 1000000007;
    int prd = A.size();
    long ans = 0;
    
    if(prd == 1)
        return 1;
       
    int i = 1;
    for(; i < A.size(); i++) {
        if(A[i] < A[i-1]) {
            break;
        }
    }
    
    vector<long> fact(prd+1);
    fact[0] = fact[1] = 1;
    
    for(int i = 2; i <= prd; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
        
    if(i == 1)
        return 1;
    
    int len = i;
    
        
    for(int i = 2; i <= len; i++) {
        if(len % i == 0 && prd % i == 0) {
            
            
            
            
            int colSize = i;
            int col = prd / i;
            long mul = 1;
            while(col--) {
                mul = (mul * fact[colSize]) % mod;
            }
            ans = (ans + mul) % mod;
        }
    }
    
    
    return (ans + 1) % mod;
}


int main(int argc, const char * argv[]) {
    cout<<cntMatrix({1, 4, 3, 2});
    return 0;
}

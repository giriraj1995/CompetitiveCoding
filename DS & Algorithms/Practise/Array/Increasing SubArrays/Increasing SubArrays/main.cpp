//
//  main.cpp
//  Increasing SubArrays
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
int cntInc(vector<int> A) {
    int mod = 1000000007;
    int n = A.size();
    
    if(n <= 1) {
        return 1;
    }
    
    A.push_back(INT_MIN);
    
    long ans = n;
    
    int i = 0, j = 1;
    for( ; j<=n ; j++) {
        
        if(i == j)
            continue;
            
        if(A[j] <= A[j-1]) {
            int len = j - i;
            ans = (ans + (((len * (len - 1)) % mod) / 2) % mod) % mod;
            i = j;
        }
        
    }
    
    return ans % mod;
}

int main(int argc, const char * argv[]) {
    cout<<cntInc({1,-1,2,3,4,-3,-1});
    return 0;
}

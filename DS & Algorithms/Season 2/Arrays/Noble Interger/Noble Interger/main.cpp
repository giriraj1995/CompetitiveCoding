//
//  main.cpp
//  Noble Interger
//
//  Created by Giriraj Saigal on 28/01/21.
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

int solve(vector<int> A) {
    sort(A.begin(), A.end());
    
    int n = A.size();
    for(int i = 0; i < n; i++) {
        int j = i+1;
        
        while(j < n && A[j] == A[i]) {
            j++;
        }
        
        if(A[i] == n - j) {
            return 1;
        }
    }
    
    
    return -1;
}


int main(int argc, const char * argv[]) {
    solve({-4, -2, 0, -1, -6 });
    return 0;
}

//
//  main.cpp
//  Next Similar No
//
//  Created by Giriraj Saigal on 13/11/20.
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

string solve(string A) {
    
    int n = A.size();
    
    if(n == 0 || n == 1)
        return "-1";
        
    int index = -1;
    
    for(int i = n - 2; i >= 0; i--) {
        if((A[i] - '0') < (A[i+1] - '0')){
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        return "-1";
    }
        
    int lowIndex = -1;
    int low = INT_MAX;

    for(int i = n-1; i > index ; i--) {
        
        if((A[i] - '0' < low) && (A[i] > A[index])) {
            low = A[i] - '0';
            lowIndex = i;
        }
    }
    
    char c = A[lowIndex];
    A[lowIndex] = A[index];
    A[index] = c;
    
    sort(A.begin() + index + 1, A.end());
    
    return A;
    
}


int main(int argc, const char * argv[]) {
    solve("218765");
    return 0;
}

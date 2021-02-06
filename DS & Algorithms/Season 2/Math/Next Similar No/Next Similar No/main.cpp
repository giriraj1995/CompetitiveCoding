//
//  main.cpp
//  Next Similar No
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

string solve(string A) {
    int ind = -1;
    int n = A.size();
    
    for(int i = n-2; i >= 0; i--) {
        if(A[i] < A[i+1])
        {
            ind = i;
            break;
        }
    }
    
    if(ind == -1)
        return to_string(ind);
    
        
    char c = CHAR_MAX;
    int ind2;
    
    for(int i = n-1; i > ind; i--) {
        if(A[i] > A[ind] && A[i] < c) {
            c = A[i];
            ind2 = i;
        }
    }
    
    char f = A[ind];
    A[ind] = A[ind2];
    A[ind2] = f;
    
    sort(A.begin() + ind+1, A.end());
    return A;
    
}


int main(int argc, const char * argv[]) {
    solve("218765");
    return 0;
}

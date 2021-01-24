//
//  main.cpp
//  Add One To Number
//
//  Created by Giriraj Saigal on 24/01/21.
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

vector<int> plusOne(vector<int> A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    A.push_back(0);
    
    int c = 1;
    
    for(int i = 0; i <= n; i++) {
        if(A[i] < 9) {
            A[i] += 1;
            c = 0;
            break;
        }else{
            A[i] = 0;
            c = 1;
        }
    }
    
    reverse(A.begin(), A.end());
    
    while(A.size() > 0 && A[0] == 0) {
        A.erase(A.begin());
    }
    
    return A;
}


int main(int argc, const char * argv[]) {
    plusOne({1, 2, 3, 9, 8, 9, 9});
    return 0;
}

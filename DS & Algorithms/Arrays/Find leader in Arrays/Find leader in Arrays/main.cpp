//
//  main.cpp
//  Find leader in Arrays
//
//  Created by Giriraj Saigal on 29/10/20.
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

vector<int> solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> ans1;
    
    if(n == 0 || n == 1)
        return A;
        
    int maximum = A[n-1];
    ans1.push_back(A[n-1]);

    for(int i = n-2; i >= 0; i--){
        if(A[i] > maximum){
            maximum = A[i];
            ans1.push_back(A[i]);
        }
    }
    
    return ans1;
    
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

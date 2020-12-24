//
//  main.cpp
//  Min lights to activate
//
//  Created by Giriraj Saigal on 24/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int solve(vector<int> &A, int B) {
    
    int count = 0;
    int indexToCheck = 0;
    int i = 0;
    int n = A.size();
    
    while(indexToCheck < n) {
        
        int i = indexToCheck + B - 1;
        
        if(i >= n)
            i = n-1;
        
        while(i >= indexToCheck - B + 1 && i >= 0 && A[i] != 1) {
            i--;
        }
        
        if(i < indexToCheck - B + 1 || i < 0)
            return -1;
        else
            count++;
        
        indexToCheck = i + B;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1, 0, 1, 0, 0, 0};
    int k = 4;
    solve(x,k);
    return 0;
}

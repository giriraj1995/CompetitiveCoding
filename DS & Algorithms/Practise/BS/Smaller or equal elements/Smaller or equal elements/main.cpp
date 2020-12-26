//
//  main.cpp
//  Smaller or equal elements
//
//  Created by Giriraj Saigal on 26/12/20.
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

int find(vector<int> &A, int k) {
    int i = 0;
    int j = A.size()-1;
    int res = -1;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(k == A[m]) {
            res = m;
            i = m + 1;
        }else{
            if(k > A[m]) {
                i = m + 1;
                res = m;
            }else{
                j = m - 1;
            }
        }
    }
    
    return res;
}

int solve(vector<int> &A, int B) {
    return find(A, B) + 1;
}


int main(int argc, const char * argv[]) {

    return 0;
}

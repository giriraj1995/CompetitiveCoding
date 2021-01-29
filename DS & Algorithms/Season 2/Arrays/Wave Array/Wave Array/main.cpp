//
//  main.cpp
//  Wave Array
//
//  Created by Giriraj Saigal on 29/01/21.
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

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

vector<int> wave(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    bool flag = true;
    for(int i = 0; i < n-1; i++) {
        if(flag) {
            if(A[i+1] > A[i]) {
                swap(&A[i+1], &A[i]);
            }
        }else {
            if(A[i] > A[i+1]) {
                swap(&A[i+1], &A[i]);
            }
        }
        
        flag = !flag;
    }
    return A;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

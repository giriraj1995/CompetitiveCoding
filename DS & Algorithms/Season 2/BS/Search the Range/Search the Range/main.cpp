//
//  main.cpp
//  Search the Range
//
//  Created by Giriraj Saigal on 11/02/21.
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

int start(vector<int> A, int B) {
    int i = 0;
    int j = A.size()-1;
    int res = -1;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(A[m] == B) {
            res = m;
            j = m-1;
        }else if(B < A[m]) {
            j = m-1;
        }else if(B > A[m]) {
            i = m+1;
        }
    }
    
    return res;
}

int end(vector<int> A, int B) {
    int i = 0;
    int j = A.size()-1;
    int res = -1;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(A[m] == B) {
            res = m;
            i = m+1;
        }else if(B < A[m]) {
            j = m-1;
        }else if(B > A[m]) {
            i = m+1;
        }
    }
    
    return res;
}

vector<int> searchRange(const vector<int> &A, int B) {
    return {start(A,B), end(A,B)};
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

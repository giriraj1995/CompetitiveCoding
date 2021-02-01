//
//  main.cpp
//  3 Repeat Number
//
//  Created by Giriraj Saigal on 31/01/21.
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

int repeatedNumber(const vector<int> &A) {
    int c1 = 0, c2 = 0;
    int ele1 = INT_MAX, ele2 = INT_MAX;
    int n = A.size();
    
    for(int i = 0; i < A.size(); i++) {
        
        if(A[i] == ele1) {
            c1++;
        }
        else if(A[i] == ele2) {
            c2++;
        }
        else if(c1 == 0) {
            ele1 = A[i];
            c1++;
        }
        else if(c2 == 0) {
            ele2 = A[i];
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    
    c1 = 0;
    c2 = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == ele1)
            c1++;
        if(A[i] == ele2)
            c2++;
    }
    
    if(c1 > n/3)
        return ele1;
        
    if(c2 > n/3)
        return ele2;
        
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

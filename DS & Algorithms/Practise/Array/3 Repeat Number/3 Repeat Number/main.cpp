//
//  main.cpp
//  3 Repeat Number
//
//  Created by Giriraj Saigal on 06/01/21.
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

int repeatedNumber(const vector<int> A) {
    int n = A.size();
    int c1 = 0;
    int c2 = 0;
    int ele1 = INT_MAX;
    int ele2 = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if(ele1 == A[i]) c1++;
        else if(ele2 == A[i]) c2++;
        else if(c1 == 0) {
            c1++;
            ele1 = A[i];
        }else if(c2 == 0) {
            c2++;
            ele2 = A[i];
        }else{
            c1--;
            c2--;
        }
    }
    
    c1 = 0;
    c2 = 0;
    
    for(int i = 0; i < n; i++) {
        if(ele1 == A[i]) c1++;
        if(ele2 == A[i]) c2++;
    }
    
    if(c1 > n/3) return ele1;
    if(c2 > n/3) return ele2;
    
    return -1;
    
}


int main(int argc, const char * argv[]) {
    cout<<repeatedNumber({1, 1, 1, 3, 1, 5, 6, 7, 8, 9, 10, 3, 2, 6})<<endl;
    return 0;
}

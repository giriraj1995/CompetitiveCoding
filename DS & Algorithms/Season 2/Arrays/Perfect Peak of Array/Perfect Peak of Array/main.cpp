//
//  main.cpp
//  Perfect Peak of Array
//
//  Created by Giriraj Saigal on 26/01/21.
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

int perfectPeak(vector<int> A) {
    int n = (int)A.size();
    
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    set<int> s;
    
    left[0] = A[0];
    for(int i = 1; i < n-1; i++) {
        left[i] = max(left[i-1], A[i-1]);
    }
    
    right[n-1] = A[n-1];
    s.insert(A[n-1]);
    for(int i = n-2; i >= 1; i--) {
        auto address = s.lower_bound(A[i]);
        if(address == s.begin()) {
            right[i] = 1;
        }else{
            right[i] = 0;
        }
        
        s.insert(A[i]);
    }
    
    for(int i = 1; i < n-1; i++) {
        if(A[i] > left[i] && 1 == right[i]) {
            return 1;
        }
    }
    
    return 0;
    
}


int main(int argc, const char * argv[]) {
    cout<<perfectPeak({5, 1, 4, 3, 6, 8, 10, 7, 9})<<endl;
    return 0;
}

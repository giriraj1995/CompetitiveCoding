//
//  main.cpp
//  Find Duplicate in Array
//
//  Created by Giriraj Saigal on 27/01/21.
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
    vector<int> B = A;
    int n = A.size();
    
    for(int i = 0; i < n; i++) {
        while(i+1 != B[i]){
            
            if(B[B[i]-1] == B[i])
                return B[i];
                
            int temp = B[B[i]-1];
            B[B[i]-1] = B[i];
            B[i] = temp;
        }
    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

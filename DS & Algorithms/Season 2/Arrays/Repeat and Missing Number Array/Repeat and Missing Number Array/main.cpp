//
//  main.cpp
//  Repeat and Missing Number Array
//
//  Created by Giriraj Saigal on 30/01/21.
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

vector<int> repeatedNumber(const vector<int> &A) {
    vector<int> B = A;
    int n = (int)A.size();
    
    for(int i = 0; i < n; i++) {
        while(i+1 != B[i]) {
            
            if(B[i] == B[B[i]-1]){
                break;
            }
            
            int temp = B[B[i]-1];
            B[B[i]-1] = B[i];
            B[i] = temp;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(B[i] != i+1) {
            return {B[i], i+1};
        }
    }
    
    return {-1};
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

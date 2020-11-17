//
//  main.cpp
//  Find majority Element
//
//  Created by Giriraj Saigal on 17/11/20.
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

int majorityElement(const vector<int> &A) {
    
    unordered_map<int, int> x;
    int n = A.size();
    for(int i : A){
        x[i]++;
    }
    
    for(auto i : x) {
        if(i.second > floor(n/2)){
            return i.first;
        }
    }
    
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

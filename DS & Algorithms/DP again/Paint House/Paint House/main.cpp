//
//  main.cpp
//  Paint House
//
//  Created by Giriraj Saigal on 28/10/20.
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

int solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int red = A[0][0];
    int blue = A[0][1];
    int green = A[0][2];
    
    for(int i=1; i<n; ++i){
        int newred = min(blue, green) + A[i][0];
        int newblue = min(red, green) + A[i][1];
        int newgreen = min(blue, red) + A[i][2];
        
        red = newred;
        blue = newblue;
        green = newgreen;
    }
    
    return min(min(red, blue), green);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

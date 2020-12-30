//
//  main.cpp
//  Balance Array
//
//  Created by Giriraj Saigal on 30/12/20.
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

int solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> evenLeft(n);
    vector<int> oddLeft(n);
    vector<int> evenRight(n);
    vector<int> oddRight(n);
    
    int sumodd = 0;
    int sumeven = 0;
    for(int i = 0; i < A.size(); i++) {
        if(i & 1) {
            oddLeft[i] = sumodd;
            evenLeft[i] = sumeven;
            sumodd += A[i];
        }else{
            evenLeft[i] = sumeven;
            oddLeft[i] = sumodd;
            sumeven += A[i];
        }
    }
    
    sumodd = 0;
    sumeven = 0;
    for(int i = A.size()-1; i >= 0; i--) {
        if(i & 1) {
            oddRight[i] = sumodd;
            evenRight[i] = sumeven;
            sumodd += A[i];
        }else{
            evenRight[i] = sumeven;
            oddRight[i] = sumodd;
            sumeven += A[i];
        }
    }
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++) {
        if(oddLeft[i] + evenRight[i] == oddRight[i] + evenLeft[i]){
            count++;
    }
    
    return count;
}


int main(int argc, const char * argv[]) {
    vector<int > x = {2, 1, 6, 4};
    solve(x);
    return 0;
}

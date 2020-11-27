//
//  main.cpp
//  gas station greedy
//
//  Created by Giriraj Saigal on 27/11/20.
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

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    int gas = 0;
    int starting_index = 0;
    int cur_index = 0;
    int flag = 0;
    
    while((starting_index < n && starting_index != cur_index) || flag == 0) {
        flag = 1;
        gas += A[cur_index];
        
        if(gas < B[cur_index]) {
            gas = 0;
            
            if((cur_index + 1) % n <= starting_index)
                return -1;
            
            starting_index = (cur_index + 1) % n;
            cur_index = (cur_index + 1) % n;
            flag = 0;
            continue;
        }
        
        gas -= B[cur_index];
        cur_index = (cur_index + 1) % n;
    }
    
    return starting_index < n ? starting_index : -1;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {4};
    vector<int> y = {3};
    
    cout<<canCompleteCircuit(x,y)<<endl;
    return 0;
}

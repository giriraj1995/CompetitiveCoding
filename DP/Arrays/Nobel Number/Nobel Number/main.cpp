//
//  main.cpp
//  Nobel Number
//
//  Created by Giriraj Saigal on 20/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return -1;
        
    if(n == 1)
        return A[0]==0?1:-1;
        
    sort(A.begin(), A.end());
    
    int prev = A[0];
    int curr;
    
    for(int i = 1; i < n; i++){
        curr = A[i];
        if(curr > prev){
            if(n-i == prev)
                return 1;
        }
        prev = curr;
    }
    
    return -1;
    
    // int count =0;
    
    // for(int i = 0; i < n; i++){
    //     int x = A[i];
    //     count = 0;
    //     for(int j = 0; j< n; j++){
    //         if(A[j] > x)
    //             count++;
    //     }
    //     if(count == x)
    //         return 1;
    // }
    
    // return -1;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {-4,-2,0,-1,-6};
    x.assign(5, 0);
    solve(x);
    return 0;
}

//
//  main.cpp
//  Square Root of a interger
//
//  Created by Giriraj Saigal on 28/11/20.
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

int solve(int n) {
    int i = 0;
    int j = n/2;
    
    while(i <= j) {
        
        int mid = i + (j-i)/2;
        
        if(mid * mid == n){
            return mid;
        }else{
            if(mid*mid < n) {
                i = mid+1;
            }else
                j = mid-1;
        }
    }
    return j;
}

int main(int argc, const char * argv[]) {
    cout<<solve(169)<<endl;
    return 0;
}

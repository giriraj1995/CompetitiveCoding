//
//  main.cpp
//  Sum of fibo numbers
//
//  Created by Giriraj Saigal on 16/12/20.
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

int lower_bound(vector<int> arr, int key) {
    int res = -1;
    int i = 0;
    int j = arr.size()-1;
    
    while(i <= j) {
        int m = i + (j - i)/2;
        
        if(arr[m] == key)
            return m;
        else{
            if(key < arr[m]) {
                j = m - 1;
            }else{
                i = m + 1;
                res = m;
            }
        }
    }
    
    return res;
}

int fibsum(int A) {
    
    if(A == 0)
        return A;

    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    
    while(1) {
        int next = fibo[fibo.size()-1] + fibo[fibo.size()-2];
        
        if(next <= A)
            fibo.push_back(next);
        else
            break;
        
    }
    
    int ans = 0;
    while(A != 0) {
        A = A - fibo[lower_bound(fibo, A)];
        ans++;
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    fibsum(1);
    return 0;
}

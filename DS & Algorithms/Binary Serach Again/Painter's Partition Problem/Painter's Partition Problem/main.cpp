//
//  main.cpp
//  Painter's Partition Problem
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

bool isvalid(int A, vector<int> C, int limit) {
    
    int sum = 0;
    int painters = 1;
    for(int i = 0; i < C.size(); i++) {
        
        sum += C[i];
        if(sum > limit){
            painters++;
            sum = C[i];
        }
        
        if(painters > A)
            return false;
    }
    
    return true;
}

 int paint(int A, int B, vector<int> C) {
    long long n = C.size();
    int m = INT_MIN;
    long long sum = 0;
    long long res = -1;
    
    for(int i = 0; i < C.size(); i++) {
        m = max(m, C[i]);
        sum += C[i];
    }
    
    long long i = m;
    long long j = sum;
    
    while(i <= j) {
        
        long long mid = i + (j-i)/2;
        
        if(isvalid(A, C, mid)){
            res = mid;
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }
    
    long long ans = (res * B) % 10000003;
    return ans;
}
int main(int argc, const char * argv[]) {
    cout<<paint(2,5,{10,20,30,40});
    return 0;
}

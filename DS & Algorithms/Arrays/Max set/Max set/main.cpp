//
//  main.cpp
//  Max set
//
//  Created by Giriraj Saigal on 22/12/20.
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

vector<int> maxset(vector<int> A) {
    
    if(A.size() == 0)
        return {};
    
    long long sum = 0;
    long long ans = 0;
    
    vector<int> arr, finalarr;
    
    map<int, vector<int>> mp;
    
    for(int i = 0; i < A.size(); i++) {
        
        if(A[i] < 0)
        {
            arr.clear();
            sum = 0;
            continue;
        }
        
        if(A[i] + sum >= A[i]) {
            sum = A[i] + sum;
            arr.push_back(A[i]);
        }else{
            sum = A[i];
            arr.clear();
            arr.push_back(A[i]);
        }
        
        if(sum == ans) {
            if(arr.size() > finalarr.size()){
                finalarr = arr;
            }
        }else
        if(sum > ans) {
            ans = sum;
            finalarr = arr;
        }
    }
    
    return finalarr;
}



int main(int argc, const char * argv[]) {
    maxset({10, -1, 2, 3, -4, 100});
    return 0;
}

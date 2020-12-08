//
//  main.cpp
//  Max ones after modification
//
//  Created by Giriraj Saigal on 07/12/20.
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

int calculate(vector<int> ze, int i, int j, int n) {
    
    int m = ze.size();
    
    if(j < m){
        j = ze[j];
    }else{
        j = n;
    }
    
    if(i-1 >= 0) {
        i = ze[i-1];
    }else{
        i = -1;
    }
    
    return j-i-1;
}

int solve(vector<int> A, int B) {
    int n = A.size();
    map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 0)
            mp[i]++;
    }
    
    vector<int> ze;
    for(auto m : mp) {
        ze.push_back(m.first);
    }
    
    int sum = INT_MIN;
    
    if(mp.size() <= B) {
        return A.size();
    }else{
        int b = B;
        int m = ze.size();
        
        int i = 0;
        
        while(i < b) {
            i++;
        }
        
        int j = 0;
        sum = max(sum, calculate(ze, j, i, n));
        j++;
        i++;
        
        while(i <= m) {
            sum = max(sum, calculate(ze, j, i, n));
            
            i++;
            j++;
        }
    }

    return sum;
}


int main(int argc, const char * argv[]) {
    solve({0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, 2);
    return 0;
}

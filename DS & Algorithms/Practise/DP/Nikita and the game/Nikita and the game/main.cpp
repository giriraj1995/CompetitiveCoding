//
//  main.cpp
//  Nikita and the game
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

long long solve(long long sum, int i, int j, vector<int> arr) {
        
    if(i >= j){
        return 0;
    }
    
    if(sum % 2 != 0){
        return 0;
    }
    
    if(sum == 0) {
        return j - i;
    }
    
    long long check = 0, half = sum/2;
    for(int k = i; k < j; k++) {
        check += arr[k];
        if(check == half) {
            
            long long left = 0, right = 0;
            
            if(k - i > j - k - 1)
                return 1 + solve(half, i, k, arr);
                
            if(k - i < j - k - 1)
                return 1 + solve(half, k+1, j, arr);
                
            left = solve(half, i, k, arr);
            right = solve(half, k+1, j, arr);
            
            return 1 + max(left, right);
            
        } else if(check > half){
            break;
        }
    }
    
    return 0;
}
int arraySplitting(vector<int> arr) {
    int n = arr.size();
    long long sum = 0;
    
    for(int i : arr) {
        sum += i;
    }
    
    if(sum == 0)
        return arr.size()-1;
        
    return solve(sum, 0, n-1, arr);
}

int main(int argc, const char * argv[]) {
    arraySplitting({2 ,2 ,2 ,3 ,3});
    return 0;
}

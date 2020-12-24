//
//  main.cpp
//  Flip
//
//  Created by Giriraj Saigal on 23/12/20.
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

vector<int> flip(string A) {
    
    int zeros = 0;
    int ones = 0;
    
    for(char c : A) {
        if(c == '0'){
            zeros++;
        }
        else{
            ones++;
        }
    }
    
    if(zeros == 0)
        return {};
        
    int i = 0, j = 0;
    
    zeros = 0;
    ones = 0;
    int l = -1, r = -2;
    int maxZero = INT_MIN;
    int minOne = INT_MAX;
    int flag = 0;
    while(j < A.size()) {
        
        if(A[j] == '0')
            zeros++;
        else
            ones++;
            
        if(zeros > ones && zeros >= maxZero && ones < minOne) {
            maxZero = zeros;
            minOne = ones;
            
            flag = 1;
            r = j;
            l = i;
            
        }else if(ones > zeros) {
            
            while(i <= j && ones >= zeros){
                if(A[i] == '0')
                    zeros--;
                
                if(A[i] == '1')
                    ones--;
                    
                i++;
            }
            
        }
        
        j++;
    }
    
    if(flag == 1)
        return {l+1, r+1};
    
    return {};
}

int main(int argc, const char * argv[]) {
    flip("00101011100100110111101100011101111011111000011");
    return 0;
}

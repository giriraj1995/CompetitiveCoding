//
//  main.cpp
//  Flip
//
//  Created by Giriraj Saigal on 25/01/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
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
    
    int C = 0;
    int n = A.size();
    int count = 0;
    int i = 0, j = 0;
    int low = -1, high = -1;
    
    while(j < n) {
        
        if(A[j] == '0') {
            C++;
        }else{
            C--;
        }
        
        if(C < 0) {
            j++;
            i = j;
            C = 0;
            continue;
        }
        
        if(C > count) {
            count = C;
            low = i;
            high = j;
        }
        
        j++;
    }
    
    if(low == -1) {
        return {};
    }
    
    return {low+1, high+1};
}


int main(int argc, const char * argv[]) {
    flip("1111111000010001111");
    return 0;
}

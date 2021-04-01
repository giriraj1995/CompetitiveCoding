//
//  main.cpp
//  Max Continuous Series of 1s
//
//  Created by Giriraj Saigal on 12/03/21.
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

vector<int> maxone(vector<int> A, int B) {
    int n = A.size();
    int z = 0;
    int i = 0;
    int j = 0;
    int len = 0;
    int st = 0;
    int en = 0;
    
    while(j < n) {
        if(A[j] == 0) {
            z++;
        }
        
        while(z > B) {
            if(A[i] == 0) {
                z--;
            }
            i++;
        }
        
        if(len < j-i+1) {
            len = j-i+1;
            st = i;
            en = j;
        }
    }
    
    vector<int> ans;
    
    while(st <= en) {
        ans.push_back(st);
        st++;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

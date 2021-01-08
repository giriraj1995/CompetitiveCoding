//
//  main.cpp
//  Max Continuous Series of 1s
//
//  Created by Giriraj Saigal on 08/01/21.
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
    int i = 0, j = 0;
    int n = A.size();
    int zeros = 0;
    int len = 0;
    int start = 0;
    int end = 0;
    
    while(j < n) {
        
        if(A[j] == 0) {
            zeros++;
        }
        
        if(zeros > B) {
            while(zeros > B) {
                if(A[i] == 0) {
                    zeros--;
                }
                i++;
            }
        }
        
        if(j - i + 1 > len) {
            start = i;
            end = j;
            len = j - i + 1;
        }
        
        j++;
    }
    
    vector<int> ans;
    for(int k = start; k <= end; k++)
        ans.push_back(k);
        
    return ans;
}


int main(int argc, const char * argv[]) {
    maxone({1,1,0,1,1,0,0,1,1,1}, 1);
    return 0;
}

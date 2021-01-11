//
//  main.cpp
//  Longest Subarray Length
//
//  Created by Giriraj Saigal on 11/01/21.
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

int solve(vector<int> A) {
    
    int j = 1;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 0)
            A[i] = -1;
    }
    
    int maxSum = A[0];
    int curSum = A[0];
    int ans = 0;
    int i = 0;
    
    while(j < A.size()) {
        
        if(curSum + A[j] >= A[j]) {
            curSum = curSum + A[j];
            
            if(curSum == 1)
                ans = max(j - i + 1, ans);
        }else{
            curSum = A[j];
            i = j;
            
            if(curSum == 1)
                ans = max(j - i + 1, ans);
        }
        j++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    solve({0, 1, 1, 0, 0, 1});
    return 0;
}

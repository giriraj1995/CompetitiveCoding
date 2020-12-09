//
//  main.cpp
//  Sliding window
//
//  Created by Giriraj Saigal on 09/12/20.
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

int solve(vector<int> A, int B) {
    
    int n = A.size();
    
    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;
    
    while(i < n && j < n) {
        if(sum + A[j] < B){
            sum += A[j];
            ans += (j - i + 1);
            j++;
        }else{
            sum -= A[i];
            i++;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({1, 11, 2, 3, 15}, 10);
    return 0;
}

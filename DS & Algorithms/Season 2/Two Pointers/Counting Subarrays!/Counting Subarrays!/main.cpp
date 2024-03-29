//
//  main.cpp
//  Counting Subarrays!
//
//  Created by Giriraj Saigal on 20/03/21.
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

int solve(vector<int> A, int B) {
    int n = (int)A.size();
    
    if(n == 0)
        return 0;
        
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = 0;
    
    for(int k : A) {
        if(k < B) {
            ans++;
        }
    }
    
    while(j < n) {
        sum += A[j];
        
        while(sum >= B) {
            sum -= A[i];
            i++;
        }
        
        if(i > j) {
            j++;
            continue;
        }
        
        int len = j - i;
        ans += len;
        j++;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({99, 59, 62, 64, 57, 8, 79, 90, 36, 66, 76, 87, 87, 34, 61, 31, 49, 29, 93, 34, 41, 67, 36, 11, 100, 38, 93, 83, 29, 53, 70, 45, 95, 9, 53, 48, 33, 36, 9, 65, 98, 44, 50, 16, 42, 90, 1, 13, 49, 24, 52, 75, 34, 92, 1, 55, 91, 98, 20, 81, 79, 32, 45, 41, 88, 100, 26, 84, 39, 93, 94, 53, 12, 61, 35, 41, 98, 86, 30, 41, 6, 92, 93, 11, 50, 79, 80, 72, 78, 74, 94, 21, 98, 27, 77, 91, 83, 79, 60, 19, 90, 60, 50, 25, 73, 81, 9, 68, 9, 78, 4, 71, 8, 97, 75, 23, 12, 20, 62, 57, 91, 64, 84, 17, 33, 53, 42, 55, 14, 63, 97, 61, 16, 5, 100, 37, 81, 99, 33, 88, 85, 41, 18, 7, 71, 42, 83, 50, 24, 59, 6, 22, 96, 97, 17, 79, 79, 80, 59, 78, 51, 8, 30, 82, 96, 79, 77, 54, 100, 85, 66, 94, 9, 73, 44, 30, 15, 69, 56, 92, 74, 23, 49, 52, 87, 45, 47, 78, 18, 30, 17, 75, 92, 70, 13, 47, 94, 92, 16, 50, 58, 41, 53, 37, 52, 88, 27, 63, 56, 84, 95, 81, 98, 66},66);
    return 0;
}

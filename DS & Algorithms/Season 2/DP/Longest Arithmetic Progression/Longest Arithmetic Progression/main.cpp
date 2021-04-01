//
//  main.cpp
//  Longest Arithmetic Progression
//
//  Created by Giriraj Saigal on 25/03/21.
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

int solve(const vector<int> A) {
    int n = A.size();
    map<int,int> x;
    vector<map<int,int>> arr(n);
    int ans = 1;
    
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < j; i++) {
            if(arr[i].find(A[j]-A[i]) != arr[i].end())
                arr[j][A[j] - A[i]] = arr[i][A[j]-A[i]] + 1;
            else
                arr[j][A[j]-A[i]]++;
            
            ans = max(ans, arr[j][A[j] - A[i]]);
        }
    }
    
    return ans+1;
}


int main(int argc, const char * argv[]) {
    solve({100, 10, 8, 300, 6, 1, 4, 2});
    return 0;
}

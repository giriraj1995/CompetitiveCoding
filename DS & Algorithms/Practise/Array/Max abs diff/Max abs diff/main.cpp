//
//  main.cpp
//  Max abs diff
//
//  Created by Giriraj Saigal on 28/12/20.
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

int maxArr(vector<int> A) {
    
    if(A.size() <= 1) {
        return 0;
    }
    
    set<int> As;
    
    for(int i = 0; i < A.size(); i++) {
        As.insert(A[i] + i + 1);
    }
    
    set<int> Ms;
    
    for(int i = 0; i < A.size(); i++) {
        Ms.insert(A[i] - i - 1);
    }
    
    int p = *As.begin();
    int q = *(--As.end());
    
    int ans = q - p;
    
    p = *Ms.begin();
    q = *(--Ms.end());
    
    ans = max(ans, q - p);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    maxArr({1,3,-1});
    return 0;
}

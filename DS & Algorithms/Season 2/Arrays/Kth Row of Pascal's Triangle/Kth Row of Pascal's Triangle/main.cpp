//
//  main.cpp
//  Kth Row of Pascal's Triangle
//
//  Created by Giriraj Saigal on 26/01/21.
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

vector<int> getRow(int A) {
    vector<int> ans(A+1, 1);
    
    for(int i = 3; i <= A+1; i++) {
        for(int j = i-2; j >= 1; j--) {
            ans[j] = ans[j] + ans[j-1];
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    getRow(1);
    return 0;
}

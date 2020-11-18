//
//  main.cpp
//  Mice
//
//  Created by Giriraj Saigal on 18/11/20.
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

int mice(vector<int> &A,vector<int> &B) {
    
    int n = A.size();
    
    if(n == 0)
        return 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ans = INT_MIN;
    
    for(int i = 0; i < A.size(); i++) {
        ans = max(ans, abs(A[i] - B[i]));
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

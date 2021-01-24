//
//  main.cpp
//  Pick from both sides!
//
//  Created by Giriraj Saigal on 24/01/21.
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

int solve(vector<int> &A, int B) {
    
    int sum = 0;
    
    for(int i = 0; i < B; i++) {
        sum += A[i];
    }
    
    int n = A.size();
    int ans = sum;
    int k = B-1;
    
    for(int j = n-1; j >= (n - B); j--) {
        sum += A[j];
        sum -= A[k];
        k--;
        
        ans = max(ans, sum);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

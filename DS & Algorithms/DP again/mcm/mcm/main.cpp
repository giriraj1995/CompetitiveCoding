//
//  main.cpp
//  mcm
//
//  Created by Giriraj Saigal on 21/11/20.
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

int solve_mcm(vector<int> x, int i, int j) {
    
    if(i+1 == j) {
        return 0;
    }
    
    if(i >= j){
        return 0;
    }
    
    int ans = INT_MAX;
    
    for(int k = i + 1; k < j ; k++) {
        
        int left = solve_mcm(x, i, k);
        int right = solve_mcm(x, k, j);
        
        int cost = x[i] * x[k] * x[j];
        
        ans = min(ans, cost + left + right);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {2,3,5,4};
    cout<<solve_mcm(x, 0, x.size()-1)<<endl;
    return 0;
}

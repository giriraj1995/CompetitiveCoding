//
//  main.cpp
//  Max consective gaps
//
//  Created by Giriraj Saigal on 24/12/20.
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

int maximumGap(const vector<int> &A) {
    
    int n = A.size();
    
    if(n <= 1)
        return 0;
        
    priority_queue<int> q;
    vector<int> arr(n);
    int ans = 0;
    
    for(int i : A){
        q.push(i);
    }
    
    for(int i = n-1; i >= 0; i--) {
        arr[i] = q.top();
        q.pop();
    }
    
    for(int i = 1; i < n; i++) {
        ans = max(ans, arr[i] - arr[i-1]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> x= {1, 10, 5};
    maximumGap(x);
    return 0;
}

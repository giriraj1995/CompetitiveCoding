//
//  main.cpp
//  Min Max
//
//  Created by Giriraj Saigal on 25/01/21.
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

int solve(vector<int> &A) {
    int low = INT_MAX;
    int high = INT_MIN;
    
    for(int i : A) {
        low = min(low, i);
        high = max(high, i);
    }
    
    return low + high;
}


int main(int argc, const char * argv[]) {
    cout<<INT_MAX<<endl;
    return 0;
}

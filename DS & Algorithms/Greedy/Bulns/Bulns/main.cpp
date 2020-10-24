//
//  main.cpp
//  Bulns
//
//  Created by Giriraj Saigal on 24/10/20.
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

int bulbs(vector<int> &A) {
    
    bool turn = true;
    int ans = 0;
    int n = A.size();
    
    for(int i = 0; i < n; i++) {
        
        if(A[i] == 0 && turn) {
            turn = !turn;
            ans++;
        }
        
        if(A[i] == 1 && !turn) {
            turn = !turn;
            ans++;
        }
        
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {0, 1, 0, 1};
    cout<<bulbs(x)<<endl;
    return 0;
}

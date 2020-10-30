//
//  main.cpp
//  ways to color 3xN board again
//
//  Created by Giriraj Saigal on 30/10/20.
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

int solve(int A) {
    
    vector<int> dp2(A+1);
    dp2[0] = 0;
    dp2[1] = 12;
    
    vector<int> dp3(A+1);
    
    dp3[0] = 0;
    dp3[1] = 24;
    
    for(int i = 2; i <= A; i++){
        dp2[i] = dp3[i-1]*5 + dp2[i-1]*7;
        dp3[i] = dp3[i-1]*11 + dp2[i-1]*10;
    }
    
    return dp2[A] + dp3[A];
    
}

int main(int argc, const char * argv[]) {
    int A = 2;
    cout<<solve(A)<<endl;
    return 0;
}

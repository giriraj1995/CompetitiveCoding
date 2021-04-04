//
//  main.cpp
//  Add Set bits from 1 to N
//
//  Created by Giriraj Saigal on 03/04/21.
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

int find(int A) {
    int x = 0;
    
    while((1<<x) <= A) {
        x++;
    }
    
    return x-1;
}

int solve(int A) {
    if(A == 0)
        return 0;
        
    int x = find(A);
    int first = (1 << (x-1)) * x;
    int second = A - (1<<x) + 1;
    int rest = A - (1<<x);
    
    return first + second + solve(rest);
}


int main(int argc, const char * argv[]) {
    cout<<solve(11);
    return 0;
}

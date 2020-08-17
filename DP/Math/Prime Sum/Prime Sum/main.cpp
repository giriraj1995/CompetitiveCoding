//
//  main.cpp
//  Prime Sum
//
//  Created by Giriraj Saigal on 17/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cmath"
using namespace std;

bool isPrime(int x){
    int count = 0;
    int n = sqrt(x);
    for(int i = 1; i <= n; i++)
    {
        if(x%i == 0)
            count++;
    }
    
    return count==1?true:false;
}

vector<int> solve(int A){
    
    vector<int> x;
    int diff;
    for(int i = 3; i < A; i = i+2)
    {
        if(isPrime(i)){
            x.push_back(i);
            diff = A - i;
            if(isPrime(diff)){
                x.push_back(diff);
                return x;
            }
            x.pop_back();
        }
    }
    return x;
}

int main(int argc, const char * argv[]) {
    solve(10);
    return 0;
}

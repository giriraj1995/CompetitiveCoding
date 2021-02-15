//
//  main.cpp
//  Largest Coprime Divisor
//
//  Created by Giriraj Saigal on 08/02/21.
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

int gcd(int x, int y) {
    if(x < y)
        gcd(y, x);
    
    if(y == 0)
        return x;
        
    return gcd(y, x%y);
}

int cpFact(int A, int B) {
    int x = A;
    int t = gcd(x,B);
    
    if(t == 1)
        return x;
    
    while(t != 1) {
        x = x/t;
        t = gcd(x,B);
        
        if(t == 1)
            return x;
    }
    
    return t;
}


int main(int argc, const char * argv[]) {
    cout<<cpFact(30,12)<<endl;
    return 0;
}

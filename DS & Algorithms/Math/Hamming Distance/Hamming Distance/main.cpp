//
//  main.cpp
//  Hamming Distance
//
//  Created by Giriraj Saigal on 19/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int hammingDis(int i, int j){
    
    int xi = i;
    int xj = j;
    
    vector<string> x;
    vector<string> y;
    int rem;
    while(xi > 0)
    {
        rem = xi%2;
        x.push_back(to_string(rem));
        xi = xi/2;
    }
    
    int n = x.size();
    
    while(n <= 20)
    {
        x.push_back(to_string(0));
        n++;
    }
    
    while(xj > 0)
    {
        rem = xj%2;
        y.push_back(to_string(rem));
        xj = xj/2;
    }
        
    n = y.size();
    
    while(n <= 20)
    {
        y.push_back(to_string(0));
        n++;
    }
    int diff = 0;
    for(n = 0; n <= 20; n++){
        if(x[n].compare(y[n]) != 0)
            diff++;
    }
    
    return diff;
}

int main(int argc, const char * argv[]) {
    hammingDis(20,5);
    return 0;
}

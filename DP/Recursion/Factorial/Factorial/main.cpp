//
//  main.cpp
//  Factorial
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int fact(int n){
    if(n == 1 || n == 0)
        return n;
    
    if(n < 0)
        return -1;
    
    return fact(n-1) * n;
}


int main(int argc, const char * argv[]) {
    cout<<fact(6)<<endl;
    return 0;
}

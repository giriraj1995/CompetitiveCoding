//
//  main.cpp
//  More Execption
//
//  Created by Giriraj Saigal on 22/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <queue>
#include <exception>
using namespace std;

class Calculator{
    public:
int power(int a, int b){
    if(a < 0 || b < 0){
        throw runtime_error("ok");
    }else{
        return pow(a,b);
    }
}
};

int main(int argc, const char * argv[]) {
    return 0;
}

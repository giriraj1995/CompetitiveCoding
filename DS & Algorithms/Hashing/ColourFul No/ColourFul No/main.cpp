//
//  main.cpp
//  ColourFul No
//
//  Created by Giriraj Saigal on 15/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
#include <map>
using namespace std;

int colorful(int A) {
    
    map<int, int> u;
    
    vector<int> x;
    int d = A;
    while(d){
        x.push_back(d%10);
        d = d/10;
    }
    
    for(int i = 1; i <= x.size(); i++){
        int mul = 1;
        for(int j = 1; j <= i; j++){
            mul *= x[j];
        }
        if(u.find(mul) == u.end()){
            u.insert(make_pair(mul, 0));
        }else
            return 0;
    }
    
    return 1;
    
}

int main(int argc, const char * argv[]) {
    colorful(23);
    return 0;
}

//
//  main.cpp
//  Step by Step
//
//  Created by Giriraj Saigal on 03/12/20.
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
    
    if(A == 0)
        return 0;
        
    int i = 0;
    long long x = 0;
    while(x != A) {
        i++;
        if(x + i < A){
            x += i;
        }else if(x + i > A) {
            x -= i;
            i++;
            x += i;
        }else{
            return i;
        }
    }
    
    return -1;
}

int solve2(int N ) {
N = abs(N);
int i = 1 ;
int s = 0 ;
while( s< N || (s-N) % 2 != 0 )
    s+=i++ ;
return i-1 ;
}


int main(int argc, const char * argv[]) {
    solve2(67);
    return 0;
}

//
//  main.cpp
//  Convert to Palindrome
//
//  Created by Giriraj Saigal on 28/02/21.
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

bool isPalin(string x) {
    int i = 0;
    int j = (int)x.size()-1;
    
    while(i < j) {
        if(x[i] != x[j]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
    
}

int solve(string x) {
    int i = 0;
    int j = (int)x.size()-1;
    
    while(i < j) {
        if(x[i] != x[j]) {
            if(isPalin(x.substr(0,i) + x.substr(i+1))
            || isPalin(x.substr(0,j) + x.substr(j+1)))
            {
                return true;
            }else{
                return false;
            }
        }
        
        i++;
        j--;
    }
    
    return true;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}

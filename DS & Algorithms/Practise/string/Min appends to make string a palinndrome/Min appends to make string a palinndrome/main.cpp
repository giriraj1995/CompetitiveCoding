//
//  main.cpp
//  Min appends to make string a palinndrome
//
//  Created by Giriraj Saigal on 07/01/21.
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

bool isPalindrom(string A, int i, int j) {
    while(i < j) {
        if(A[i] != A[j]) {
            return false;
        }
        
        i++;
        j--;
    }
    
    return true;
}


int solve(string A) {
    
    int n = A.size();
    
    if(isPalindrom(A, 0, n-1))
        return 0;
    
    if(n <= 1)
        return 0;
        
    int i = 0;
    int j = n-1;
    
    while(i <= j) {
        if(A[i] == A[j]) {
            if(isPalindrom(A, i, j)) {
                return i;
            }
        }
        
        i++;
    }
    
    return n;
}


int main(int argc, const char * argv[]) {
    cout<<solve("oqycntornscygodzdctxnhoc")<<endl;
    return 0;
}

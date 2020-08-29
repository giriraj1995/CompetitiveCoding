//
//  main.cpp
//  Binary Palindromic
//
//  Created by Giriraj Saigal on 28/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrom(int A){
    
    int h = A;
    int l=0;
    
    while(h){
        l++;
        h = h>>1;
    }
    
    int target = 0;
    int i = 0;
    int y = 0;
    
    for(int i = 0; i < l ; i++){
        
        int x = 1<<i;
        y = 0;
        
        if(A & x)
        {
            y = 1<<(l-i-1);
        }
        
        target = target | y;
    }
    
    if(target == A)
        return true;
    else
        return false;
}

int solve(int A) {
    
    int count=0;
    int i = 1;
    
    while(count < A){

        if(isPalindrom(i))
            count++;
        i++;
    }
    
    return i-1;
}



int main(int argc, const char * argv[]) {
    cout<<solve(9);
    return 0;
}

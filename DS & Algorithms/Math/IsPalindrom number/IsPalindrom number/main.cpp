//
//  main.cpp
//  IsPalindrom number
//
//  Created by Giriraj Saigal on 18/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int reverse(int A) {
    
    int flag = 0;
    
    if(A < 0){
        A = A * -1;
        flag = 1;
    }
    
    int rev = 0;
    
    while(A>0)
    {
        rev = rev*10 + A%10;
        A = A/10;
    }
    
    if(flag == 1)
    {
        rev = rev * -1;
    }
    
    return rev;
    
    
}

int isPalindrome(int A) {
    vector<int> x;
    int l;
    while(A/10 != 0)
    {
        l = A%10;
        x.push_back(l);
        A = A/10;
    }
    
    x.push_back(A);
    
    int n = x.size();
    
    int i = 0;
    int j = n-1;
    
    while(i < j)
    {
        if(x[i] != x[j])
            return false;
        
        i++;
        j--;
    }
    
    return true;
}


int main(int argc, const char * argv[]) {
    //reverse(-1146467285);
    cout<<pow(10, 2)<<endl;
    return 0;
}

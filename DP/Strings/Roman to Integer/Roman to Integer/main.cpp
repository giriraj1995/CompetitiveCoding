//
//  main.cpp
//  Roman to Integer
//
//  Created by Giriraj Saigal on 26/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int convert(char c){
    
        if(c == 'I' || c == 'i')
            return 1;
        
        if(c == 'V' || c == 'v')
            return 5;
            
        if(c == 'X' || c == 'x')
            return 10;
            
        if(c == 'L' || c == 'l')
            return 50;
            
        if(c == 'C' || c == 'c')
            return 100;
            
        if(c == 'D' || c == 'd')
            return 500;
            
        if(c == 'M' || c == 'm')
            return 1000;
            
    return -1;
}

int romanToInt(string A) {
    
    if(A.size() == 0)
        return 0;
    
    reverse(A.begin(), A.end());
    
    if(A.size() == 1)
    {
        return convert(A[0]);
    }
    
    int n = A.size();
    int i = 0;
    int sum = convert(A[0]);
    int pre = convert(A[0]);
    
    for(i = 1; i < n; i++){
        
        int cur = convert(A[i]);
        
        if(cur < pre){
            sum -= cur;
        } else
            sum += cur;
        
        pre = cur;
        
    }
    
    return sum;

}


int main(int argc, const char * argv[]) {
    cout<<romanToInt("LIX")<<endl;
    return 0;
}

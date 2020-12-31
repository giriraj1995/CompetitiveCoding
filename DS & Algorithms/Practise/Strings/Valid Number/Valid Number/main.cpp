//
//  main.cpp
//  Valid Number
//
//  Created by Giriraj Saigal on 31/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

int afterE(string g, int i, int j) {
    
    if(i == g.size())
        return 0;
    
    for(int k = i; k <= j; k++) {
        if(g[k] < '0' || g[k] > '9')
            return 0;
    }
    
    return 1;
}

int isNumber(const string A) {
    
    bool N = false;
    bool P = false;
    bool E = false;
    
    int i = 0;
    
    if(A.size() == 0)
        return 0;
    
    while(i < A.size() && A[i] == ' ')
        i++;

    if(i == A.size())
        return 0;
        
    int j = A.size()-1;
    
    while(A[j] == ' ')
        j--;
    
    for(; i <= j; i++) {
        if(A[i] >= '0' && A[i] <= '9'){
            continue;
        }else if(A[i] == '.' && !P) {
            P = true;
            
            if(i == A.size()-1){
                return false;
            }
            
            if(A[i+1] < '0' || A[i+1] > '9')
                return false;
                
        }else if(A[i] == '-' && !N) {
            N = true;
            
            if(i == A.size()-1){
                return false;
            }
            
            if(A[i+1] == '.') {
                return false;
            }
            
            if(i != 0 && A[i-1] != 'e')
                return false;
            
        }else if(A[i] == 'e') {
            if(A[i] == A.size()-1)
                return false;
            
            if(A[i+1] == '-'){
                return afterE(A, i+2, j);
            }else{
                return afterE(A, i+1, j);
            }
        }else{
            return false;
        }
    }
    
    return true;
}




int main(int argc, const char * argv[])
{
    isNumber("-01.1e-10");
    return 0;
}

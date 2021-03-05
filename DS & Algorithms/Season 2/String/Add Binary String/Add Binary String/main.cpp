//
//  main.cpp
//  Add Binary String
//
//  Created by Giriraj Saigal on 05/03/21.
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

string addBinary(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    if(n == 0 && m == 0)
        return "0";
        
    if(n == 0)
        return B;
    
    if(m == 0)
        return A;
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    string c(n+m,'0');
    
    int i = 0;
    int j = 0;
    int k = 0;
    int carry = 0;
    
    while(i < n && j < m) {
        if(carry == 0) {
            if(A[i] == '0' && B[j] == '0') {
                c[k] = '0';
                carry = 0;
            }else if(A[i] == '1' && B[j] == '0') {
                c[k] = '1';
                carry = 0;
            }else if(A[i] == '0' && B[j] == '1') {
                c[k] = '1';
                carry = 0;
            }else if(A[i] == '1' && B[j] == '1') {
                c[k] = '0';
                carry = 1;
            }
        }else{
            if(A[i] == '0' && B[j] == '0') {
                c[k] = '1';
                carry = 0;
            }else if(A[i] == '1' && B[j] == '0') {
                c[k] = '0';
                carry = 1;
            }else if(A[i] == '0' && B[j] == '1') {
                c[k] = '0';
                carry = 1;
            }else if(A[i] == '1' && B[j] == '1') {
                c[k] = '1';
                carry = 1;
            }
        }
        
        i++;
        j++;
        k++;
    }
    
    while(i < n) {
        if(carry == 0) {
            if(A[i] == '0') {
                c[k] = '0';
                carry = 0;
            }else if(A[i] == '1') {
                c[k] = '1';
                carry = 0;
            }
        }else{
            if(A[i] == '0') {
                c[k] = '1';
                carry = 0;
            }else if(A[i] == '1') {
                c[k] = '0';
                carry = 1;
            }
        }
        
        i++;
        k++;
    }
    
    while(j < m) {
        if(carry == 0) {
            if(B[j] == '0') {
                c[k] = '0';
                carry = 0;
            }else if(B[j] == '1') {
                c[k] = '1';
                carry = 0;
            }
        }else{
            if(B[j] == '0') {
                c[k] = '1';
                carry = 0;
            }else if(B[j] == '1') {
                c[k] = '0';
                carry = 1;
            }
        }
        
        j++;
        k++;
    }
    
    if(carry == 0) {
        c[k] = '0';
    }else{
        c[k] = '1';
    }

    reverse(c.begin(), c.end());
    
    while(c.size() > 0 && c[0] == '0')
        c.erase(c.begin());
    
    if(c.size() == 0)
        return "0";
    
    return c;
}


int main(int argc, const char * argv[]) {
    addBinary("1010110111001101101000","1000011011000000111100110");
    return 0;
}

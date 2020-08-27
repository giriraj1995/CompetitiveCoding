//
//  main.cpp
//  Add Binary Strings
//
//  Created by Giriraj Saigal on 27/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addZeros(string x, int n){
    int m = x.size();
    string ans = "";
    int z = n - m;
    while(z--){
        ans = ans + "0";
    }
    return ans + x;
}

string addBinary(string A, string B) {
    
    
    if(A.size() == 0)
        return B;
    
    if(B.size() == 0)
        return A;
        
    int n = A.size();
    int m = B.size();
    
    if(n < m){
        A = addZeros(A,m);
    } else if(m < n){
        B = addZeros(B,n);
    }
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    string ans = "";
    int s = A.size();
    int carry = 0;

    for(int i = 0 ; i < s ; i++){
        
        if(carry == 0){
            if(A[i] == '0' && B[i] == '0'){
                ans += '0';
                carry = 0;
            }
            else
            if((A[i] == '1' && B[i] == '0') || (A[i] == '0' && B[i] == '1')){
                ans += '1';
                carry = 0;
            }
            else
            if(A[i] == '1' && B[i] == '1'){
                ans += '0';
                carry = 1;
            }
        }else if(carry == 1){
            if(A[i] == '0' && B[i] == '0'){
                ans += '1';
                carry = 0;
            }
            
            if((A[i] == '1' && B[i] == '0') || (A[i] == '0' && B[i] == '1')){
                ans += '0';
                carry = 1;
            }
                
            if(A[i] == '1' && B[i] == '1'){
                ans += '1';
                carry = 1;
            }
        }
    }
    
    if(carry == 1)
        ans = ans + "1";
    
    reverse(ans.begin(), ans.end());
        
    return ans;
    
}



int main(int argc, const char * argv[]) {
    string x = "h";
    return 0;
}

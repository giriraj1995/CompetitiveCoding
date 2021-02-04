//
//  main.cpp
//  Next Smallest Palindrome! c+
//
//  Created by Giriraj Saigal on 04/02/21.
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

string add1(string A, int h) {
    string x = A.substr(0, h+1);
    reverse(x.begin(), x.end());
    x.push_back('0');
    int i = 0;
    int carry = 1;
    while(carry == 1) {
        if(x[i] < '9') {
            x[i] = (char)((int)x[i] + 1);
            carry = 0;
        }else{
            x[i] = '0';
            carry = 1;
        }
        
        i++;
    }
    reverse(x.begin(), x.end());
    
    while(x.size() > 0 && x[0] == '0') {
        x.erase(x.begin());
    }
    
    return x;
}

string solve(string A) {
    int n = (int)A.size();
    if(n & 1) {
        int h = n/2;
        int i = h-1;
        int j = h+1;
        while(i >= 0 && j < n) {
            if(A[i] > A[j]) {
                string k = A.substr(0,h);
                return k + A[h] + string(k.rbegin(), k.rend());
            }else if(A[i] < A[j]){
                string k = add1(A, h);
                string l = k.substr(0, k.size()-1);

                if((k.size() & 1) == 0){
                    return l + k[k.size()-1] + string(l.rbegin(), l.rend());
                }else{
                    return l  + string(l.rbegin(), l.rend());
                }
            }
            else{
                i--;
                j++;
            }
        }
        
        string k = add1(A, h);
        string l = k.substr(0, k.size()-1);

        if((k.size() & 1) == 0){
            return l + k[k.size()-1] + string(l.rbegin(), l.rend());
        }else{
            return l  + string(l.rbegin(), l.rend());
        }
    }else{
        int h = (n/2)-1;
        int j = n/2;
        int i = (n/2)-1;
        
        while(i >= 0 && j < n) {
            if(A[i] > A[j]) {
                string k = A.substr(0, h+1);
                return k + string(k.rbegin(), k.rend());
            }else if(A[i] < A[j]){
                string k = add1(A, h);
                return k + string(k.rbegin(), k.rend());
            }else{
                i--;
                j++;
            }
        }
        
        string k = add1(A, h);
        string l = k.substr(0, k.size()-1);
        return l + k[k.size()-1] + string(l.rbegin(), l.rend());
    }
    
    return "";
}

int gcd(int A, int B) {
    if(B > A)
        gcd(B,A);
    if(B == 0)
        return A;
    return gcd(B,A%B);
}



int main(int argc, const char * argv[]) {
    //cout<<solve("74094882455")<<endl;
    gcd(4,6);
    return 0;
}

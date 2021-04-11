//
//  main.cpp
//  Add Binary String 2
//
//  Created by Giriraj Saigal on 08/04/21.
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

    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        string c;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i = 0;
        int j = 0;
        int carry = 0;
        int k = 0;
        
        while(i < n && j < m) {
            if(carry == 0) {
                if(a[i] == '0' && b[j] == '0')
                    c.push_back('0');
                else if(b[j] == '0') {
                    c.push_back('1');
                }else if(a[i] == '0') {
                    c.push_back('1');
                }else{
                    c.push_back('0');
                    carry = 1;
                }
            }else{
                if(a[i] == '0' && b[j] == '0'){
                    c.push_back('1');
                    carry = 0;
                } else if(b[j] == '0') {
                    c.push_back('0');
                    carry = 1;
                }else if(a[i] == '0') {
                    c.push_back('0');
                    carry = 1;
                }else{
                    c.push_back('1');
                    carry = 1;
                }
            }
            
            i++;
            j++;
        }
        
        while(i < n) {
            if(carry == 0) {
                c.push_back(a[i]);
            }else{
                if(a[i] == '0') {
                    c.push_back('1');
                    carry = 0;
                }else{
                    c.push_back('0');
                    carry = 1;
                }
            }
            
            i++;
        }
        
        while(j < m) {
            if(carry == 0) {
                c.push_back(b[j]);
            }else{
                if(b[j] == '0') {
                    c.push_back('1');
                    carry = 0;
                }else{
                    c.push_back('0');
                    carry = 1;
                }
            }
            
            j++;
        }
        
        if(carry == 1) {
            c.push_back('1');
        }
        
        return string(c.rbegin(), c.rend());
    }

int main(int argc, const char * argv[]) {
    cout<<addBinary("1010", "1011");
    return 0;
}

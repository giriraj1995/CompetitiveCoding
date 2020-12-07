//
//  main.cpp
//  next smallest palindrom
//
//  Created by Giriraj Saigal on 07/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

bool check9(string A) {
    int n = A.size();
    
    for(char c : A){
        if(c != '9')
            return false;
    }
    
    return true;
}

string add1(string A) {
    
    reverse(A.begin(), A.end());
    
    int n = A.size();
    int i = 0;
    int flag = 0;
    while(i < n) {
        if(A[i] == '9') {
            A[i] = '0';
        }else{
            A[i] = A[i]+1;
            flag = 1;
            break;
        }
        
        i++;
    }
    
    if(flag == 0) {
        A = A + "1";
    }
    
    reverse(A.begin(), A.end());
    
    return A;
}

string handleEven(string A) {
    int n = A.size();
    int j = n/2;
    int i = n/2-1;
    string x = A.substr(0, i+1);

    int t = 0;
    int flag = 0;
    while(i-t >= 0 && j+t < n){
        if(A[i-t] != A[j+t]) {
            flag = 1;
            if(A[i-t] > A[j+t]) {
                return x + string(x.rbegin(), x.rend());
            }else{
                x = add1(x);
                return x + string(x.rbegin(), x.rend());
            }
        }
        
        t++;
    }
    
    if(flag == 0) {
        x = add1(x);
        return x + string(x.rbegin(), x.rend());
    }
    
    return "0";
}

string handleOdd(string A) {
    int n = A.size();
    
    int h = n/2;
    
    string x = A.substr(0, h);
    
    int i = 1;
    int flag = 0;
    while(h - i >= 0 && h + i < n) {
        if(A[h-i] != A[h+i]){
            flag = 1;
            if(A[h-i] > A[h+i]) {
                return x + A[h] + string(x.rbegin(), x.rend());
            }else{
                if(A[h] != '9'){
                    A[h] = A[h]+1;
                    return x + A[h] + string(x.rbegin(), x.rend());
                }else{
                    x = add1(x);
                    return x + "0" + string(x.rbegin(), x.rend());
                }
            }
        }
        i++;
    }
    return "0";
}

string solve(string A) {
    
    int n = A.size();
    
    if(check9(A)){
        return "1" + string(n-1, '0') + "1";
    }
    
    if(n == 1) {
        return to_string((A[0] - '0')+1);
    }
    
    if(n & 1) {
        return handleOdd(A);
    }else
        return handleEven(A);
}


int main(int argc, const char * argv[]) {
    cout<<solve("74")<<endl;
    return 0;
}

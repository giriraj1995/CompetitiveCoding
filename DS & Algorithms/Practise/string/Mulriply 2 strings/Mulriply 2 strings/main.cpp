//
//  main.cpp
//  Mulriply 2 strings
//
//  Created by Giriraj Saigal on 15/01/21.
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
string multiply(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    string res(n+m, '0');
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            int num = ((A[i] - '0') * (B[j] - '0')) + (res[i+j+1] - '0');
            res[i+j+1] = num % 10 + '0';
            res[i+j] += num/10;
        }
    }
    
    while(res.size() > 0 && res[0] != '0') {
        res.erase(res.begin());
    }
    
    return res;
    
//    int n = A.length(),m = B.length();
//    string res(n+m,'0');
//
//    for(int i=n-1;i>=0;i--){
//        for(int j=m-1;j>=0;j--){
//            int num = (A[i] - '0') * (B[j] - '0') + res[i+j+1] - '0';
//            res[i+j+1] = num%10 + '0';
//            res[i+j] += num/10;
//        }
//    }
//    for(int i=0;i<res.length();i++) if(res[i] != '0') return res.substr(i);
//    return "0";
}

int main(int argc, const char * argv[]) {
    multiply("123", "456");
    return 0;
}

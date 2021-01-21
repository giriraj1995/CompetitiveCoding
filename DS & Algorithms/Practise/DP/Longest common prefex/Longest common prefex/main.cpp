//
//  main.cpp
//  Longest common prefex
//
//  Created by Giriraj Saigal on 21/01/21.
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

int LCS(string a, string b) {
    int n = a.size();
    int m = b.size();
    
    int i = 0;
    int c = 0;
    
    while(i < n && i < m && a[i] == b[i]) {
        c++;
        i++;
    }
    
    return c;
}

int LCPrefix(vector<string> A, int B) {
    int mod = 1000000007;
    int n = A.size();
    A.push_back("");
    int i = 0; int j = 0;
    int ans = 0;
    while(j <= n) {
        
        if(i == j && j == n) {
            break;
        }
        
        if(LCS(A[i], A[j]) < B) {
            int len = j - i;
            ans = (ans + (((len) * (len + 1)) % mod / 2)) % mod;
            --j;
            i = j+1;
        }
        j++;
    }
    return ans % mod;
}


int main(int argc, const char * argv[]) {
    cout<<LCPrefix({"iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwtef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef", "iotedxwlef"},10);
    return 0;
}

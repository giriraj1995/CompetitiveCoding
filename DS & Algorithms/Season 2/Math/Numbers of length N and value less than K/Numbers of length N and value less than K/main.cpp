//
//  main.cpp
//  Numbers of length N and value less than K
//
//  Created by Giriraj Saigal on 06/02/21.
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

int solve(vector<int> A, int B, int C) {
    string c = to_string(C);
    int M = (int)c.size();
    int N = (int)A.size();
    
    if(B > M) {
        return 0;
    }else if(B < M) {
        if(B == 1) {
            return N;
        }
        
        if(A[0] == 0) {
            return N-1 * pow(N,B-1);
        }else{
            return pow(N,B);
        }
    }else if(B == 1) {
        int ans = 0;
        
        for(int i = 0; i < N; i++) {
            if(A[i] < (c[0] - '0')) {
                ans++;
            }else if(A[i] > (c[0] - '0'))
                break;
        }
        
        return ans;
    }
    else {
        int ans = 0;
        bool flag = false;
        for(int i = 0; i < N; i++) {
            if(A[i] <= (c[0] - '0') && A[i] != 0) {
                ans++;
                
                if(A[i] == (c[0] - '0'))
                    flag = true;
            }else if(A[i] > (c[0] - '0'))
                break;
        }
        
        ans = ans*pow(N,B-1);

        if(!flag)
            return ans;
        
        int n = N;
        for(int i = 1; i < B; i++) {
            int ele = c[i]-'0';
            if(i != B-1) {
                int k;
                for(k = 0; k < n; k++) {
                    if(A[k] > ele) {
                        break;
                    }
                }
                
                ans -= (n-k)*pow(N,B-i-1);
            }else{
                int k;
                for(k = 0; k < n; k++) {
                    if(A[k] >= ele) {
                        break;
                    }
                }
                
                ans -= (n-k);
            }
        }
        
        return ans;
    }
}


int main(int argc, const char * argv[]) {
    cout<<solve({0, 2, 3, 4, 5, 7, 8, 9}, 5, 86587)<<endl;
    return 0;
}

//
//  main.cpp
//  Numbers of length N and value less than K 2
//
//  Created by Giriraj Saigal on 08/02/21.
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
    int n = A.size();
    
    if(n == 0)
        return 0;
    
    string c = to_string(C);
    vector<int> temp(c.size());
    
    for(int i = 0; i < c.size(); i++) {
        temp[i] = c[i] - '0';
    }
    
    if(B > temp.size()) {
        return 0;
    }else if(B < temp.size()) {
        if(B == 1) {
            return (int)A.size();
        }
        if(A[0] == 0) {
            return (n-1) * pow(n,B-1);
        }else{
            return pow(n, B);
        }
    }else{
        if(B == 1) {
            int ans = 0;
            for(int i = 0; i < n; i++) {
                if(A[i] < temp[0])
                    ans++;
                else{
                    break;
                }
            }
            return ans;
        }
        
        int ans = 0;
        int j = 0;
        bool flag = false;
        
        for(int i = 0; i < n; i++) {
            if(A[i] > 0 && A[i] <= temp[j]) {
                ans++;
                if(A[i] == temp[j]) {
                    flag = true;
                }
            }else if(A[i] > temp[j]) {
                break;
            }
        }
        
        ans = ans*pow(n,B-1);
        j++;
        
        while(flag == true && j < B) {
            flag = false;
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(A[i] > temp[j]) {
                    count++;
                }
                
                if(A[i] == temp[j]) {
                    flag = true;
                }
            }
            
            ans -= count * pow(n,B-j-1);
            j++;
        }
        
        if(flag == true && j == B)
            ans--;
            
        return ans;
    }
}


int main(int argc, const char * argv[]) {
    cout<<solve({0, 1, 3, 4, 6, 7},4,59172)<<endl;
    return 0;
}

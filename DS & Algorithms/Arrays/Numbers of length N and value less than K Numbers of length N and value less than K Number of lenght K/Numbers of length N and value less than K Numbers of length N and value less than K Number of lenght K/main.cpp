//
//  main.cpp
//  Numbers of length N and value less than K Numbers of length N and value less than K Number of lenght K
//
//  Created by Giriraj Saigal on 23/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int solve(vector<int> &A, int B, int C) {
    int ans = 0;
    long long int lc = 0, c = C, w = 0;
    
    if(A.size() == 0)
        return 0;
    
    while(c>0)
    {
        c = c/10;
        lc++;
    }
    
    if(B > lc)
    {
        return 0;
    } else if(lc > B){
        
        int z = 0;
        int b = B;

        for(int i:A)
        {
            if(i == 0)
                z++;
        }
        
        int n = (int)A.size();
        ans = (n-z) * pow(n,b-1);
        if(B == 1 && A[0] == 0) ans++;
        return ans;
    } else {
        if(B == 1){
            for(int o:A){
                if(o < C){
                    ans++;
                }
            }
            return ans;
        } else {
            vector<int> temp(B);
            for(int i = B-1; i >= 0; i--){
                temp[i] = C%10;
                C = C/10;
            }
            
            int flag = 0; int j = 0;
            int n = A.size();
            int count =0;
            
            for(int i = 0; i<n; i++){
                if(A[i] == 0) continue;
                if(A[i] > temp[j]) break;
                count++;
            }
            
            ans += count * pow(n,B-1);
            
            for(int i = 0; i<n; i++){
                if(A[i] == temp[j])
                    flag = 1;
            }
            
            j++;
            
            while(flag == 1 && j<=B-1){
                int countx = 0;
                flag = 0;
                for(int i = 0; i < n; i++){
                    if(A[i] == temp[j])
                        flag = 1;
                    if(A[i] > temp[j])
                        countx++;
                }
                
                ans -= countx * pow(n,B-1-j);
                j++;
            }
            
            if(j == B && flag == 1){
                ans--;
            }
            
            return ans;
            
        }
    }
    
}



int main(int argc, const char * argv[]) {
    vector<int> x = {0, 1, 5};
    solve(x, 1, 2);
    return 0;
}

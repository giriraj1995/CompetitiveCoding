//
//  main.cpp
//  Minimum lights to activate
//
//  Created by Giriraj Saigal on 30/11/20.
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

int solve(vector<int> A, int B) {
    
    vector<int> lights;
    int n = A.size();
    
    if(n == 0)
        return -1;
    
    int k = 0;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 1){
            lights.push_back(i);
        }
    }
    
    if(lights.size() ==0)
        return -1;
        
    int ans = 0;
    for(int i = 0; i < n;) {
        
        int check = i;
        int till = i + B - 1;
        vector<int> ok;
        int rightmostLight = -1;
        
        for(int j = i; j <= till && j < n; j++) {
            if(A[j] == 1)
                rightmostLight = j;
        }
        
        if(rightmostLight == -1)
            return -1;
        else{
            ans++;
            
            int f = rightmostLight + 1;
            till = f + B - 1;
            
            while(f < n && f <= till){
                if(A[f] == 1)
                    rightmostLight = f;
                f++;
            }
            
            if(f == n)
                break;
            
            i = rightmostLight;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    solve({0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0}, 12);
    return 0;
}

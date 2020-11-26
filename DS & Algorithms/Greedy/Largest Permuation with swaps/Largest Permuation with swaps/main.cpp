//
//  main.cpp
//  Largest Permuation with swaps
//
//  Created by Giriraj Saigal on 25/11/20.
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

//partially accepted
vector<int> solve(vector<int> A, int B) {
    
    if(B == 0)
        return A;
        
    int n = A.size();
    
    for(int i = 1; i <= B; i++) {
        
        int index = -1;
        
        for(int k = n-2; k >= 0; k--) {
            if(A[k] < A[k+1])
            {
                index = k;
                break;
            }
        }
        
        if(index == -1){
            return A;
        }
        
        int m = INT_MIN;
        int x;
        
        for(int j = i-1; j < n; j++) {
            if(A[j] > m)
            {
                m = A[j];
                x = j;
            }
        }
        
        if(x != i-1)
        {
            int temp = A[x];
            A[x] = A[i-1];
            A[i-1] = temp;
        }else{
            B++;
        }
        
    }
    
    return A;

}

//more effiencit next_permutation
vector<int> solve2(vector<int> A, int B) {
    
    if(B == 0)
        return A;
        
    int n = A.size();
    
    for(int i = 1; i <= B; i++) {
        
        int index = -1;
        
        for(int k = 0; k < n-1; k++) {
            if(A[k] < A[k+1])
            {
                index = k;
                break;
            }
        }
        
        if(index == -1){
            return A;
        }
        
        int m = INT_MIN;
        int x;
        
        for(int j = index+1; j < n; j++) {
            if(A[j] > m)
            {
                m = A[j];
                x = j;
            }
        }
        
        int temp = A[x];
        A[x] = A[index];
        A[index] = temp;
        
    }
    
    return A;

}

//using maps
vector<int> solve3(vector<int> A, int B) {
    
    map<int, int, greater<int>> mp;
    
    for(int i = 0; i<A.size(); i++)
        mp[A[i]] = i;
        
     
    int i = 0;
    int n = A.size();
    
        
    for(auto k : mp){
        if(k.first == A[i]){
            i++;
            continue;
        }else{
            int ele = k.first;
            int index = k.second;
            mp[A[i]] = index;
            int temp = A[index];
            A[index] = A[i];
            A[i] = temp;
            mp[ele] = i;
            B--;
            i++;
            if(B == 0)
                return A;
        }
    }
    
    return A;

    
}


int main(int argc, const char * argv[]) {
    solve3({3, 2, 4, 1, 5 }, 3);
    return 0;
}

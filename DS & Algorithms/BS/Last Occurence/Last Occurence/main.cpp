//
//  main.cpp
//  Last Occurance in Sorted Array
//
//  Created by Giriraj Saigal on 15/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){return a>b?a:b;}

int firstOcc(vector<int> &A, int i, int j ,int key){
    int r;
    if(i <= j){
        int m = i + (j-i)/2;
        if(A[m] == key){
            
            r = firstOcc(A, m+1, j, key);
            
            if(r < 0)
                return m;
            
            return max(m, r);
        } else {
            
            if(key < A[m]){
                return firstOcc(A, i, m-1, key);
            }
            else{
                return firstOcc(A, m+1, j, key);
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    vector<int> A = {1,4,10,10,10,10,14,18};
    int n = (int)A.size();
    
    int key = 10;
    
    cout<<firstOcc(A, 0, n-1, key)<<endl;
    
    return 0;
}


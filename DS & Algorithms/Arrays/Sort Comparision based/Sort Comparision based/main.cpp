//
//  main.cpp
//  Sort Comparision based
//
//  Created by Giriraj Saigal on 19/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cmath"
using namespace std;

int myCompare(int a, int b){
    
    int x,y;
    
    int bl = 0, al = 0;
    
    int bd = b;
    int ad = a;
    
    while(bd > 0)
    {
        bd = bd / 10;
        bl++;
    }
    
    while(ad > 0)
    {
        ad = ad / 10;
        al++;
    }
    
    x = a * pow(10,bl) + b;
    y = b * pow(10,al) + a;
    
    return x>y?b:a;
}

void merge(vector<int> &A, int i, int m, int j){
    
    int l = i;
    int k = i;
    int h = m+1;
    
    vector<int> B = A;
    
    while(l <= m && h <= j){
        
        if(myCompare(A[l],A[h]) == A[l]){
            B[k] = A[l];
            k++;
            l++;
        } else if(myCompare(A[l],A[h]) == A[h]){
            B[k] = A[h];
            k++;
            h++;
        }
    }
    
    while(l <= m){
        B[k] = A[l];
        k++;
        l++;
    }
    
    while(h <= j){
        B[k] = A[h];
        k++;
        h++;
    }
    
    for(int t = i; t<= j; t++){
        A[t] = B[t];
    }
}

void mergesort(vector<int> &A, int i, int j){
    if(i < j){
        int m = i + (j-i)/2;
        
        mergesort(A,i,m);
        mergesort(A,m+1,j);
        merge(A,i,m,j);
        
    }
}

int main(int argc, const char * argv[]) {
    vector<int> x = {8,89};
    mergesort(x, 0, 1);
    return 0;
}

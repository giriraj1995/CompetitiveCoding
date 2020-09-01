//
//  main.cpp
//  MergeSort
//
//  Created by Giriraj Saigal on 01/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int i, int m, int j){
    
    int p = i;
    int q = m+1;
    int k = i;
    vector<int> arr(A.size(),0);
    while(p <= m && q <= j){
        
        if(A[p] < A[q])
            arr[k++] = A[p++];
        else
            arr[k++] = A[q++];
    }
    
    while(p <= m)
        arr[k++] = A[p++];
        
    while(q <= j)
        arr[k++] = A[q++];
        
        
    for(int d = i; d<=j ; d++){
        A[d] = arr[d];
    }
    
}

void mergeSort(vector<int> &A, int i, int j){
    
    int n = (int)A.size();
    int g;
    int s=0,e=0,m=0;
    for(g = 2; g < n+1; g = g*2){
        
        for(int i = 0; i+g-1<n ; i = i + g){
            s = i;
            e = i + g - 1;
            m = s + (e-s)/2;
            merge(A,s,m,e);
        }
     merge(A,s,s+g-1,(int)A.size()-1);
    }
    
}

void sortColors(vector<int> &A) {
    
    return mergeSort(A, 0, (int)A.size()-1);
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {2,5,7,9,5,3,5,2,4,5};
    sortColors(x);
    return 0;
}


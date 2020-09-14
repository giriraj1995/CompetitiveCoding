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
    
    if(i < j){
        
        int m = i + (j-i)/2;
        
        mergeSort(A,i,m);
        mergeSort(A,m+1,j);
        merge(A,i,m,j);
        
    }
}

void sortColors(vector<int> &A) {
    
    return mergeSort(A, 0, A.size()-1);
    
}


int main(int argc, const char * argv[]) {
    vector<int> x = {2,46,7,3,6,8,3,7,8};
    sortColors(x);
    return 0;
}

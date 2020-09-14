//
//  main.cpp
//  BinarySearch
//
//  Created by Giriraj Saigal on 15/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;

int binarySearch(vector<int> &A, int i, int j,int key){
    calls++;
    
    if(i == j)
    {
        if(key == A[i])
            return i;
        else
            return -1;
    } else
    if(i < j){
        int m = (i + j)/2;
        
        if(key == A[m]){
            return m;
        } else {
            if(key < A[m])
            {
                return binarySearch(A, i, m-1, key);
            } else {
                return binarySearch(A, m+1, j, key);
            }
        }
    }
    return -1;
}

int binarySearch2(vector<int> &A,int i, int j, int key){
    calls++;
    
    while(i <= j)
    {
        int m = i + (j-i)/2; //interger Overflow saved
        if(key == A[m])
            return m;
        else{
            if(key < A[m])
            {
                j = m-1;
            } else {
                i = m+1;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {1,3,5,7,8,9};
    cout<<binarySearch2(A,0,(int)A.size()-1,9)<<endl;
    cout<<calls<<endl;
    return 0;
}

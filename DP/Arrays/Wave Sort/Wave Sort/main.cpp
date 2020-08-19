//
//  main.cpp
//  Wave Sort
//
//  Created by Giriraj Saigal on 19/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

vector<int> wave(vector<int> &A) {
    
    int n = (int)A.size();
    int flag = 0;
    for(int i = 1; i < n; i++){
        
        if(flag == 0){
            if(A[i] > A[i-1]){
                swap(&A[i], &A[i-1]);
            }
            flag = 1;
        }else if(flag == 1){
            if(A[i] < A[i-1]){
                swap(&A[i], &A[i-1]);
            }
            flag = 0;
        }
    }
    
    return A;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1,2,3,4};
    wave(x);
    return 0;
}

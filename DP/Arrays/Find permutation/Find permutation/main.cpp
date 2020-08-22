//
//  main.cpp
//  Find permutation
//
//  Created by Giriraj Saigal on 22/08/20.
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

vector<int> findPerm(const string A, int B) {
    vector<int> x;
    if(B == 0 || B<0)
        return x;
        
    for(int i = 1; i <= B; i++){
        x.push_back(i);
    }
    
    for(int i = 1; i < B; i++){
        if(A[i-1] == 'I'){
            if(x[i] < x[i-1]){
                swap(&x[i], &x[i-1]);
            }
        }else if(A[i-1] == 'D'){
            if(x[i] > x[i-1]){
                swap(&x[i], &x[i-1]);
            }
        }
    }
    
    return x;
    
}


int main(int argc, const char * argv[]) {
    string a = "ID";
    int b = 3;
    
    findPerm(a,b);
    return 0;
}

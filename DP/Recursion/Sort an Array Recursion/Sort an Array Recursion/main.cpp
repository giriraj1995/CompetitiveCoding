//
//  main.cpp
//  Sort an Array Recursion
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int calls = 0;

void insert(vector<int> &A,int x){
    calls++;
    if(A[A.size()-1] <= x || A.size() == 0){
        A.push_back(x);
        return;
    }
    
    int d = A[A.size()-1];
    A.pop_back();
    insert(A, x);
    A.push_back(d);
    
}

void sorting(vector<int> &A){
    calls++;
    if(A.size() == 1){
        return;
    }
    
    int val = A[A.size()-1];
    A.pop_back();

    sorting(A);
    
    insert(A,val);
    
}

int main(int argc, const char * argv[]) {
    vector<int> x = {3,9,5,2,7,1,6,6,4,6,7,2,4,6,9,9,8,6,3,1,2};
    sorting(x);
    cout<<calls;
    return 0;
}


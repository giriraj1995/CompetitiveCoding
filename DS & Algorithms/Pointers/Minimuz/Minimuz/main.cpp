//
//  main.cpp
//  Minimuz
//
//  Created by Giriraj Saigal on 31/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int closest(vector<int> x, int key){
    
    int i = 0;
    int j = x.size()-1;
    
    while(i <= j){
        
        int m = i + (j-i)/2;
        
        if(x[m] == key)
            return m;
        else{
            if(key < x[m])
                j = m-1;
            else
                i = m+1;
        }
    }
    
    if(j == -1)
        return i;
    else if(i == x.size()){
        return j;
    }
    
    int d = abs(key - x[i]);
    
    if(abs(key - x[j]) < d)
    {
        return j;
    }else
        return i;
}

int maximum(int a, int b, int c){
    if(a > b){
        if(a > c)
            return a;
        else
            return c;
    } else {
        if(b > c)
            return b;
        else
            return c;
    }
}

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    
    if(A.size() == 0|| B.size() == 0|| C.size() == 0)
        return 0;
    
    int min = INT_MAX;
    int max = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        
        int j = closest(B, A[i]);
        int k = closest(C, A[i]);
        
        int res1 = abs(A[i] - B[j]);
        int res2 = abs(B[j] - C[k]);
        int res3 = abs(A[i] - C[k]);
        
        max = maximum(res1, res2, res3);
        
        if(max < min)
            min = max;
    }
    
    return min;
    
}


int main(int argc, const char * argv[]) {
    vector<int> a = {10, 4, 10};
    vector<int> b = {-5, -4, 1,10,60};
    vector<int> c = {3,4,5,8,10, 12};
    
    cout<<minimize(a,b,c)<<endl;
    return 0;
}

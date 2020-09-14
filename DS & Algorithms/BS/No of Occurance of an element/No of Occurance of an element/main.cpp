//
//  main.cpp
//  No of Occurance of an element
//
//  Created by Giriraj Saigal on 15/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int bs(vector<int> A, int i ,int j, int key){
    if(i<=j)
    {
        int m = i + (j-i)/2;
        if(key == A[m]){
            int l = bs(A, i, m-1, key);
            int r = bs(A, m+1, j, key);
            return 1+l+r;
        } else {
            if(key < A[m]){
                return bs(A, i, m-1, key);
            } else {
                return bs(A, m+1, j, key);
            }
        }
    }else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> A = {2,4,10,10,10,10,10,10,10,10,10,10,18,18,19,20};
    int key = 201;
    cout<<"Count of Key: "<<key<<" is "<<bs(A,0,(int)A.size()-1,key)<<endl;
    return 0;
}

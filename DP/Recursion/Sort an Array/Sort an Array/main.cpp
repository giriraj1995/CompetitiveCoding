//
//  main.cpp
//  Sort an Array
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void sorting(vector<int> &A, int n){
    
    if(n == A.size() || n == 0)
        return;
    
    if(A[n-1] > A[n]){
        int temp = A[n];
        A[n] = A[n-1];
        A[n-1] = temp;
        sorting(A, n-1);
    }
    
    sorting(A, n+1);

}

int main(int argc, const char * argv[]) {
    vector<int> x = {3,9,5,2,7,1,6,8,3,4,6,2,5,7,8,4,6,7,4,6};
    sorting(x,1);
    return 0;
}

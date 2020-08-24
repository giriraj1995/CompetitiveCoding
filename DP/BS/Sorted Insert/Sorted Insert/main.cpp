//
//  main.cpp
//  Sorted Insert
//
//  Created by Giriraj Saigal on 23/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> &A, int B){
    int i = 0;
    int j = A.size()-1;
    int x = B;
    
    while(i <= j){
        int m = i + (j-i)/2;
        if(A[m] == x){
            return m;
        } else {
            if(x < A[m]){
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
    }
    
    return i;
}


int searchInsert(vector<int> &A, int B) {
    
    if(A.size() == 0)
        return 0;
    
    return bs(A, B);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1, 3, 5, 6};
    return 0;
}

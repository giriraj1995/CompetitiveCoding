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
    int large = B;
    int small = 1;
    
    vector<int> res;
    
    for (int i = 0; i < A.size(); i++) {
        if(A[i] == 'I'){
            res.push_back(small);
            small++;
        } else {
            res.push_back(large);
            large--;
        }
    }
    
    if(A[A.size()-1] == 'I'){
        res.push_back(small);
    } else {
        res.push_back(large);
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    string a = "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD";
    int b = 354;
    
    findPerm(a,b);
    return 0;
}

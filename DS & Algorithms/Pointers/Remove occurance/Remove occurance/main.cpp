//
//  main.cpp
//  Remove occurance
//
//  Created by Giriraj Saigal on 31/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &A, int B) {
    
    if(A.size() == 0)
        return 0;
        
    int x = A[A.size()-1];
    A.pop_back();
    removeElement(A,B);
    
    if(x != B)
        A.push_back(x);
        
    return A.size();
}


int main(int argc, const char * argv[]) {
    vector<int> x = {4,1,1,2,1,3};
    removeElement(x,1);
    return 0;
}

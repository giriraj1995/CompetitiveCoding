//
//  main.cpp
//  Remove Duplicates
//
//  Created by Giriraj Saigal on 15/03/21.
//  Copyright © 2021 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int removeDuplicates(vector<int> A) {
    int n = A.size();
    if(n == 0)
        return 0;
        
    int prev = A[0];
    int count = 1;
    int i = 1;
    
    while(i < A.size()) {
        if(A[i] == prev) {
            count++;
            
            if(count > 2) {
                count = 2;
                A.erase(A.begin()+i);
                continue;
            }
            
            i++;
        }else{
            prev = A[i];
            count = 1;
            i++;
        }
    }
    
    return A.size();
}

int main(int argc, const char * argv[]) {
    removeDuplicates({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
    return 0;
}

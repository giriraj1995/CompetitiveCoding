//
//  main.cpp
//  Diffk
//
//  Created by Giriraj Saigal on 19/03/21.
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

int diffPossible(vector<int> A, int B) {
    int n = A.size();
    int i = 0;
    int j = 1;
    
    while(i < n-1 && j < n) {
        if(A[j] - A[i] == B) {
            return 1;
        }else if(A[j] - A[i] > B) {
            while(A[j] - A[i] > B && i!=j) {
                i++;
            }
        }else if(A[j] - A[i] < B) {
            j++;
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    diffPossible({0, 1, 9, 10, 13, 17, 17, 17, 23, 25, 29, 30, 37, 38, 39, 39, 40, 41, 42, 60, 64, 70, 70, 70, 72, 75, 85, 85, 90, 91, 91, 93, 95},83);
    return 0;
}

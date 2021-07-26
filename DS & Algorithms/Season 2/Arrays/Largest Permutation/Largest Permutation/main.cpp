//
//  main.cpp
//  Largest Permutation
//
//  Created by Giriraj Saigal on 26/07/21.
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

vector<int> solve(vector<int> A, int B) {
    
    int i = 0;
    while(i < A.size() && B) {
        int x = A[i];
        int ind = -1;
        int high = x;
        
        for(int k = i+1; k < A.size(); k++) {
            if(A[k] > high) {
                high = A[k];
                ind = k;
            }
        }
        
        if(ind != -1) {
            B--;
            
            int temp = A[ind];
            A[ind] = A[i];
            A[i] = temp;
            
        }
        
        i++;
    }
    
    return A;
}

int main(int argc, const char * argv[]) {
    solve({1,2,3,4,5}, 2);
    return 0;
}

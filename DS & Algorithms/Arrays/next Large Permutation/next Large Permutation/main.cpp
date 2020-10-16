//
//  main.cpp
//  next Large Permutation
//
//  Created by Giriraj Saigal on 16/10/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    
    int n = A.size();
    int ind = -1;
    for (int i=n-2; i>=0; i--) {
        if (A[i] < A[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        sort(A.begin(), A.end());
    } else if (ind + 1 < n){
        sort(A.begin() + ind + 1, A.end());
        for (int i=ind+1; i<n; i++) {
            if (A[i] > A[ind]) {
                int tmp = A[i];
                A[i] = A[ind];
                A[ind] = tmp;
                break;
            }
        }
    }
    return A;
}

int main(int argc, const char * argv[]) {
    vector<int> x = { 444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52};
    nextPermutation(x);
    return 0;
}

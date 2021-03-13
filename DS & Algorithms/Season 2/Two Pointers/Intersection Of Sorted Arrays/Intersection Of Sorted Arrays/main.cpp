//
//  main.cpp
//  Intersection Of Sorted Arrays
//
//  Created by Giriraj Saigal on 13/03/21.
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

vector<int> intersect(const vector<int> A, const vector<int> B) {
    int n = A.size();
    int m = B.size();
    
    if(n == 0 && m == 0) {
        return {};
    }
    
    if(n == 0) {
        return B;
    }
    
    if(m == 0) {
        return A;
    }
    
    int i = 0;
    int j = 0;
    vector<int> ans;
    
    while(i < n && j < m) {
        if(A[i] == B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        }else{
            if(A[i] < B[j]) {
                i++;
            }else{
                j++;
            }
        }
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    vector<int> res = intersect({1},{1});
    return 0;
}

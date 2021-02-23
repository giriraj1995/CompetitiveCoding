//
//  main.cpp
//  Rotated Sorted Array Search
//
//  Created by Giriraj Saigal on 23/02/21.
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

int search_sorted(vector<int> A, int i, int j, int key) {
    while(i <= j) {
        int m = i + (j-i)/2;
        if(A[m] == key)
            return m;
        else{
            if(key < A[m]) {
                j = m-1;
            }else{
                i = m+1;
            }
        }
    }
    
    return -1;
}
 
int search(const vector<int> A, int B) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    
    while(l <= h) {
        int m = l + (h-l)/2;
        if(A[0] < A[m]) {
            l = m+1;
        }else{
            h = m-1;
        }
    }
    
    int x = search_sorted(A, 0, h, B);
    
    if(x != -1)
        return x;
        
    return search_sorted(A, h+1, A.size()-1, B);
}


int main(int argc, const char * argv[]) {
    search({4, 5, 6, 7, 0, 1, 2, 3}, 10);
    return 0;
}

//
//  main.cpp
//  Search in Bitonic Array
//
//  Created by Giriraj Saigal on 10/02/21.
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

int find(vector<int> A) {
    int i = 0;
    int j = A.size()-1;
    int start = i;
    int end = j;
    while(i <= j) {
        int m = i + (j-i)/2;
        if(m > start && m < end) {
            if(A[m-1] < A[m] && A[m] > A[m+1]) {
                return m;
            }else if(A[m-1] > A[m]) {
                j = m-1;
            }else if(A[m-1] < A[m]) {
                i = m+1;
            }
        }else if(m == start) {
            if(A[m] > A[m+1]) {
                return m;
            }else{
                i = m+1;
            }
        }else if(m == end) {
            if(A[m] > A[m-1]) {
                return m;
            }else{
                j = m-1;
            }
        }
    }
    
    return -1;
}

int findele(vector<int> A, int key) {
    int i = 0;
    int j = A.size()-1;
    int start = i;
    int end = j;
    while(i <= j) {
        int m = i + (j-i)/2;
        if(A[m] == key) {
            return m;
        }else if(key < A[m]){
            j = m-1;
        }else{
            i = m+1;
        }
    }
    
    return -1;
}

int solve(vector<int> A, int B) {
    int n = find(A)+1;
    int m = n;
    vector<int> arr1,arr2;
    int i = 0;
    
    while(n--) {
        arr1.push_back(A[i++]);
    }
    
    int k = A.size()-1;
    while(k >= i) {
        arr2.push_back(A[k--]);
    }
    
    int x = findele(arr1, B);
    
    if(x != -1)
        return x;
    
    int y = findele(arr2, B);

    if(y != -1)
        return A.size()-y-1;
        
    return -1;
    
}


int main(int argc, const char * argv[]) {
    cout<<solve({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11}, 12)<<endl;
    return 0;
}

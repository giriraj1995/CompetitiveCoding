//
//  main.cpp
//  QuickSort
//
//  Created by Giriraj Saigal on 08/01/21.
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

int partition(vector<char> &arr, int i, int j) {
    int pivot = i;
    int p = i;
    int q = j;
    
    do {
        do{
            p++;
        }while(p <= j && arr[p] < arr[pivot]);
        
        do{
            q--;
        }while(q > i && arr[q] >= arr[pivot]);
        
        if(p < q)
            swap(arr[p], arr[q]);
    }while(p < q);
    
    if(q >= 0 && q < j)
        swap(arr[pivot], arr[q]);
    
    return q;
}

void quickSort(vector<char> &arr, int i, int j) {
    if(i < j) {
        int p = partition(arr, i, j);
        quickSort(arr, i, p);
        quickSort(arr, p+1, j);
    }
}

void matchPairs(char nuts[], char bolts[], int n) {
    vector<char> c;
    for(int i = 0; i < n; i++) {
        c.push_back(nuts[i]);
    }
    c.push_back(CHAR_MAX);
    
    quickSort(c, 0, n);
    c.pop_back();
    
    for(int i = 0; i < n; i++) {
        nuts[i] = bolts[i] = c[i];
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    char ok[] = {'^', '&', '%', '@', '#', '*', '$', '~', '!'};
    matchPairs(ok, ok, 9);
    return 0;
}

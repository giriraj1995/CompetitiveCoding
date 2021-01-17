//
//  main.cpp
//  heap sort
//
//  Created by Giriraj Saigal on 17/01/21.
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

// Main function to do heap sort. This function uses buildHeap()
//  and heapify()

void heapify(int arr[], int n, int i)  {
    vector<int> ar;
    
    ar.push_back(0);
    
    for(int i =0; i < n; i++)
        ar.push_back(arr[i]);
        
    int t = 1;
    int temp = ar[t];
    
    while(t*2 <= n) {
        int next = t * 2;
        
        if(next+1 <= n && ar[next+1] > ar[next]) {
            next = next + 1;
        }
        
        if(temp < ar[next]) {
            int x = ar[next];
            ar[next] = ar[t];
            ar[t] = x;
        }
        
        t = next;
    }
    
    for(int i =0; i < n; i++)
        arr[i] = ar[i+1];
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  {
    vector<int> ar;
    
    ar.push_back(0);
    
    for(int i =0; i < n; i++)
        ar.push_back(arr[i]);
        
    for(int i = n; i >= 1; i--) {
        int t = i;
        int temp = ar[i];
        
        while(t > 1 && temp > ar[t/2]){
            ar[t] = ar[t/2];
            t = t/2;
        }
        
        ar[t] = temp;
    }
    
    for(int i = 1; i <= n; i++) {
        arr[i-1] = ar[i];
    }
}


void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// The functions should be written in a way that array become sorted
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[].
// n is size of heap. This function  is used in above heapSor()

int main(int argc, const char * argv[]) {
    int arr[] = {4,1,3,9,7};
    heapSort(arr, 5);
    return 0;
}

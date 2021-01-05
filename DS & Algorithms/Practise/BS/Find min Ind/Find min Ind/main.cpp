//
//  main.cpp
//  Find min Ind
//
//  Created by Giriraj Saigal on 05/01/21.
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

int findMin(int arr[], int n) {
    int i = 0;
    int j = n-1;
    
    while(i <= j) {
        int m = i + (j-i)/2;
        if(m > 0 && m < n-1) {
            if(arr[m] < arr[m+1] && arr[m] < arr[m-1]) {
                return m;
            }else if(arr[0] < arr[m]) {
                i = m+1;
            }else if(arr[0] > arr[m]) {
                j = m-1;
            }
        }else{
            if(m == 0 && arr[m] < arr[m+1]) {
                return m;
            }else if(m == 0 && arr[m] > arr[m+1]){
                i = m+1;
            }else if(m == n-1 && arr[m] < arr[m-1]){
                return m;
            }else if(m == n-1 && arr[m] > arr[m-1]){
                j = m-1;
            }
        }
    }
    
    return -1;
}
int findKRotation(int arr[], int n) {
    if(n <= 1)
        return 0;
       
   if(n == 2) {
       if(arr[0] > arr[1])
            return 1;
       else
            return 0;
   }
   
    int res = findMin(arr, n);
    
   return res == -1 ? 0 : res;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5};
    cout<<findKRotation(arr, 5);
    return 0;
}

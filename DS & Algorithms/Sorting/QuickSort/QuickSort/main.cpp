//
//  main.cpp
//  QuickSort
//
//  Created by Giriraj Saigal on 22/09/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int swaps = 0;

int partition(vector<int> &arr, int i, int j){

    int pivot = arr[i];
    int k = i;

    while(i < j){
        do{i++;}while(arr[i] <= pivot);
        do{j--;}while(arr[j] > pivot);
        if(i < j){
            swaps++;
            int h = arr[i];
            arr[i] = arr[j];
            arr[j] = h;
        }
    }

    if(j != k){
        swaps++;
        int h = arr[k];
        arr[k] = arr[j];
        arr[j] = h;
    }

    return j;
}

void quickSort(vector<int> &arr, int i, int j){

    if(i < j){
        int p = partition(arr, i , j);
        quickSort(arr, i, p);
        quickSort(arr, p+1, j);
    }

}

// Complete the minimumSwaps function below.
int minimumSwaps1(vector<int> arr) {

    arr.push_back(INT_MAX);
    quickSort(arr, 0, arr.size() - 1);
    return swaps;
}

int minimumSwaps(vector<int> arr) {

    for(int i = 0; i < arr.size(); i++){

        if(arr[i] == i + 1){
            continue;
        }

        int g = arr[arr[i]-1];
        arr[arr[i] - 1] = arr[i];
        arr[i] = g;
        swaps++;
        i--;
    }

    return swaps;
}

int main(int argc, const char * argv[]) {
    cout<<minimumSwaps({4 ,3 ,1 ,2});
    return 0;
}

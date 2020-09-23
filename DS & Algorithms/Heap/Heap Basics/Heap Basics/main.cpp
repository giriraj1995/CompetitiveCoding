#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct MinHeap{
    vector<long long int> arr;
}*minHeap;

void insert(long long int x){
    minHeap->arr.push_back(x);
    int i = minHeap->arr.size() - 1;
    int temp = minHeap->arr[i];
    while(i/2 >= 1){
        if(minHeap->arr[i/2] > temp){
            minHeap->arr[i] = minHeap->arr[i/2];
            i = i/2;
        }else{
            break;
        }
    }
    minHeap->arr[i] = temp;
}

void heapify(int c){

    int n = minHeap->arr.size();
    int j = 2*c;

    while(j < n){
        int minChild = minHeap->arr[j];

        if(j + 1 < n){
            if(minChild > minHeap->arr[j+1]){
                j = j+1;
            }
        }

        if(minHeap->arr[c] > minHeap->arr[j]){
            long long int k = minHeap->arr[j];
            minHeap->arr[j] = minHeap->arr[c];
            minHeap->arr[c] = k;
        }else{
            break;
        }
        c = j;
        j = 2*c;
    }
}

void remove(long long int x){
    int i;
    for(i = 1; i < minHeap->arr.size(); i++){

        if(minHeap->arr[i] == x){

            long long y = minHeap->arr[minHeap->arr.size() - 1];
            minHeap->arr.pop_back();
            minHeap->arr[i] = y;
            break;
        }

    }

    if(i == minHeap->arr.size())
        return;
    else{
        heapify(i);
    }
}

void minElement(){
    
    if(minHeap->arr.size() == 1)
        return;
    else{
        cout<<endl<<minHeap->arr[1]<<endl;
    }
    
}

int main() {
    
    minHeap = new MinHeap();
    minHeap->arr.push_back(-1);
    int t;
    cin>>t;

    while(t--){

        int q;
        cin>>q;
        long long int k;

        if(q == 1){
            cin>>k;
            insert(k);
        }else if(q == 2){
            cin>>k;
            remove(k);
        }else{
            minElement();
        }

    }
    return 0;
}



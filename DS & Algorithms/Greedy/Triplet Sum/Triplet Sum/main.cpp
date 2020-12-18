//
//  main.cpp
//  Triplet Sum
//
//  Created by Giriraj Saigal on 17/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

long find(vector<int> arr, int ele) {
    int i = 0;
    int j = arr.size()-1;
    int res = -1;
    while(i <= j) {
        int m = i + (j-i)/2;
        
        if(arr[m] == ele){
            res = m;
            i = m + 1;
        }else if(ele < arr[m]) {
            j = m - 1;
        }else{
            res = m;
            i = m + 1;
        }
    }
    
    return res+1;
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
        if(a.size() == 0 || b.size() == 0||c.size() == 0)
        return 0;
        
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<int> A;
        
    for(int i = 0 ; i < a.size(); i++) {
        if(i == 0){
            A.push_back(a[i]);
        }
        else {
            if(a[i] != A[A.size()-1]){
                A.push_back(a[i]);
            }
        }
    }
    
    vector<int> C;
    
    for(int i = 0 ; i < c.size(); i++) {
        if(i == 0)
            C.push_back(c[i]);
        else {
            if(c[i] != C[C.size()-1]){
                C.push_back(c[i]);
            }
        }
    }
    
    long ans = 0;
    unordered_set<int> store;
    
    for(int j = 0; j < b.size(); j++) {
        int ele = b[j];
        
        if(store.find(ele) == store.end())
        {
            store.insert(ele);
            long x = find(A, ele);
            long y = find(C, ele);
            ans += x * y;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    triplets({1, 4, 5}, {2, 3, 3}, {1, 2, 3});
    return 0;
}

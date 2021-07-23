//
//  main.cpp
//  Min unsorted Array
//
//  Created by Giriraj Saigal on 22/08/20..
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> x, int i, int j){
    
    int k = i;
    
    while(k <= j-1){
        if(x[k] > x[k+1])
            return false;
        k++;
    }
    
    return true;
}

vector<int> subUnsort(vector<int> &A) {
    
//    vector<int> x;
//
//    if(A.size() == 0 || A.size() == 1){
//        x.push_back(-1);
//        return x;
//    }
//
//    if(isSorted(A, 0, A.size()-1)){
//        x.push_back(-1);
//        return x;
//    }
//
//    int n = A.size();
//    int res = INT_MAX;
//    vector<int> y;
//    int l,h;
//
//    for(int i = 0; i < n; i++){
//        for(int j = n-1; j>=i; j--){
//            y = A;
//            sort(y.begin()+i,y.begin()+j+1);
//            if(isSorted(y,0,y.size()-1)){
//                res = min(res, j-i+1);
//                l = i;
//                h = j;
//            }
//        }
//    }
//
//    y.clear();
//
//    for(int i = l; i <=h; i++)
//        y.push_back(A[i]);
    
    vector<int> B = A;
    sort(B.begin(), B.end());
    
    int n = B.size();
    bool found = false;
    vector<int> ans;
    
    for(int i = 0; i < n ; i++){
        if(A[i] != B[i]){
            ans.push_back(i);
            found = false;
            for(int j = n-1; j > i; j--){
                if(A[j] != B[j]){
                    found = true;
                    ans.push_back(j);
                    break;
                }
            }
            if(!found)
                break;
        }
    }
    
    if(ans.size() == 0){
        ans.push_back(-1);
    }
    
    return ans;
    
}


int main(int argc, const char * argv[]) {
    vector<int> x={1, 3, 2, 4, 5};
    subUnsort(x);
    return 0;
}

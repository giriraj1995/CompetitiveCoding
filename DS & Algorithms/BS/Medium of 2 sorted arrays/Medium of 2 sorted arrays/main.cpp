//
//  main.cpp
//  Medium of 2 sorted arrays
//
//  Created by Giriraj Saigal on 24/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getLeft(vector<int> x, int p){
    if(p == 0){
        return INT_MIN;
    } else
        return x[p-1];
}


int getRight(vector<int> x, int p){
    if(p == x.size()){
        return INT_MAX;
    } else
        return x[p];
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    vector<int> s;
    vector<int> l;
    
    if(A.size() > B.size()){
        s = B;
        l = A;
    } else {
        s = A;
        l = B;
    }
    
    int lo = 0;
    int hi = (int)s.size();
    int cn = (int)s.size() + (int)l.size();
    
    while(lo <= hi){
        int x = lo + (hi-lo)/2;
        int y = (cn+1)/2 - x;
        
        int leftS = getLeft(s,x);
        int rightS = getRight(s,x);
        
        int leftL = getLeft(l,y);
        int rightL = getRight(l,y);
        
        if(leftS <= rightL && leftL <= rightS){
            if(cn % 2 == 0){
                return (max(leftL, leftS) + min(rightS,rightL))/2.0;
            } else {
                return max(leftL, leftS);
            }
        } else {
            if(leftS > rightL)
                hi = x - 1;
            else
                lo = x + 1;
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    vector<int> s = {0,23};
    vector<int> l;
    
    cout<<findMedianSortedArrays(s,l);

    return 0;
}

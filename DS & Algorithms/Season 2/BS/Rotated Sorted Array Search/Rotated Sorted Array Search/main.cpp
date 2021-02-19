//
//  main.cpp
//  Rotated Sorted Array Search
//
//  Created by Giriraj Saigal on 19/02/21.
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

int findPivot(const vector<int> &A){
    int l=0,h=A.size()-1;
    while(l<=h){
        int mid=h-(h-l)/2;
        if(A[mid]>A[0])
            l=mid+1;
        else
            h=mid-1;
    }
    return h;
    
}
int isPresent(const vector<int> &A,int l,int h,int val){
    
    while(l<=h){
        int mid=h-(h-l)/2;
        if(A[mid]==val)
            return mid;
        else if(A[mid]<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
    
    
}
int search(const vector<int> &A, int B) {
    int pivot=findPivot(A);
    if(B==A[pivot])
        return pivot;
    else if(B<A[0])
        return isPresent(A,pivot+1,A.size()-1,B);
    else
        return isPresent(A,0,pivot,B);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}

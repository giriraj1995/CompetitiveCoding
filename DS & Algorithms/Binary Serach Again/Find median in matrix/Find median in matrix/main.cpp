//
//  main.cpp
//  Find median in matrix
//
//  Created by Giriraj Saigal on 28/11/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

int solve(vector<vector<int> > &A, int n, int m){
    int min = INT_MAX;
    int max = INT_MIN;
    
    for(int i = 0 ; i < n; i++ )
    {
        if(A[i][0] < min)
            min = A[i][0];
        
        if(A[i][m-1] > max)
            max = A[i][m-1];
    }
    
    while(min <= max){
        int mid = min + (max-min)/2;
        int count = 0;
        int desired = (n*m+1)/2;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < m; j++){
                if(A[i][j] <= mid)
                    count++;
                else
                    break;
            }
        }
        
        if(count < desired)
            min = mid + 1;
        else
            max = mid - 1;
    }
    
    return min;
}



//int findMedian(vector<vector<int> > A) {
//    int rows = A.size();
//    int cols = A[0].size();
//    return solve(A, rows, cols);
//}

int findMedian(vector<vector<int> > A) {
    
    int n = A.size();
    int m = A[0].size();
    
    int min = INT_MAX;
    int max = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        
        if(A[i][0] < min)
            min = A[i][0];
            
        if(A[i][m-1] > max)
            max = A[i][m-1];
        
    }
    
    while(min <= max) {
        
        int mid = min + (max-min)/2;
        int c = 0;
        int d = (n*m+1)/2;
    
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                if(A[i][j] <= mid)
                    c++;
                else
                    break;
                
            }
            
        }
        
        if(c < d){
            min = mid + 1;
        }else
            max = mid - 1;
    }
    
    return min;
}


int main(int argc, const char * argv[]) {
    findMedian( {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}});
    return 0;
}

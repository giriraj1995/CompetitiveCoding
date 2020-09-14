//
//  main.cpp
//  Median in a row wise sorted matrix
//
//  Created by Giriraj Saigal on 16/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
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
            max = mid;
    }
    
    return min;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x;
    
    vector<int> x0 = {1,3,5};
    x.push_back(x0);
    
    vector<int> x1 = {2,6,9};
    x.push_back(x1);
    
    vector<int> x2 = {3,6,9};
    x.push_back(x2);
    
    solve(x, 3, 3);
    
    return 0;
}

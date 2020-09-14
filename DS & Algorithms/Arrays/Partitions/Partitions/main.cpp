//
//  main.cpp
//  Partitions
//
//  Created by Giriraj Saigal on 14/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int main(int argc, const char * argv[]) {
    int A = 5;
    vector<int> B = {3,3,-3,3,3};
    int n = A;
    int sum = 0;
    
    for(int i = 0; i<n; i++)
    {
        sum += B[i];
    }
    
    double sx = sum/3;
    int s = sum/3;
    
    if(sum%3 != 0)
        return 0;
        
    if(sx > (double)s)
        return 0;
        
    if(A < 3)
        return 0;
    
    int i = 0;
    int j = n-1;
    
    int leftsum = 0;
    int rightsum = 0;
    int count = 0;
    
    while(i < n-2){
        leftsum += B[i];
        if(leftsum == s){
            j = n-1;
            rightsum = 0;
            while(i < j-1){
                rightsum += B[j];
                if(rightsum == s){
                    count++;
                }
                j--;
            }
        }
        i++;
    }
    return count;
    return 0;
}

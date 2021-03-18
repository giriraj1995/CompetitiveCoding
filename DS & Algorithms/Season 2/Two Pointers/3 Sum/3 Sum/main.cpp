//
//  main.cpp
//  3 Sum
//
//  Created by Giriraj Saigal on 18/03/21.
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

int threeSumClosest(vector<int> &A, int B) {
    int n = (int)A.size();
    
    if(n < 3) {
        return 0;
    }
    
    int sum = 0;
    int x = INT_MAX;
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n-2; i++) {
        int low = i+1;
        int high = n-1;
        
        while(low < high) {
            
            if(abs(A[i] + A[low] + A[high] - B) < x) {
                sum = A[i] + A[low] + A[high];
                x = abs(A[i] + A[low] + A[high] - B);
            }
            
            if((A[i] + A[low] + A[high]) == B) {
                return B;
            }else{
                if((A[i] + A[low] + A[high]) < B) {
                    low++;
                }else{
                    high--;
                }
            }
        }
    }
    
    return sum;
    
}


int main(int argc, const char * argv[]) {
    vector<int> A = {2, 1, -9, -7, -8, 2, -8, 2, 3, -8};
    cout<<threeSumClosest(A, -1)<<endl;
    return 0;
}

//
//  main.cpp
//  Min unsorted Array
//
//  Created by Giriraj Saigal on 04/09/21.
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
vector<int> subUnsort(vector<int> A) {
    int n = A.size();
    
    if(n == 0 || n == 1){
        return {-1};
    }
    
    int start = -1;
    int end = -1;
    int i = 0;
    
    for(; i < n-1; i++) {
        if(A[i] > A[i+1]){
            break;
        }
    }
    
    if(i == n-1)
        return {-1};
    
    start = i;

    for(i = n-1; i > 0; i--) {
        if(A[i] < A[i-1]){
            break;
        }
    }
    
    end = i;
    
    int low = A[start];
    int high = A[start];
    
    for(i = start; i <= end; i++) {
        low = min(low, A[i]);
        high = max(high, A[i]);
    }
    
    for(i = 0; i < n; i++) {
        if(A[i] > low){
            start = i;
            break;
        }
    }
    
    for(i = n-1; i >= 0; i--){
        if(A[i] < high){
            end = i;
            break;
        }
    }
    
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    
    return ans;
}


int main(int argc, const char * argv[]) {
    subUnsort({4,15,4,4,15,18,20});
    return 0;
}

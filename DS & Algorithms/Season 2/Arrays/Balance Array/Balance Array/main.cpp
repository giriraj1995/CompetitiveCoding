//
//  main.cpp
//  Balance Array
//
//  Created by Giriraj Saigal on 27/01/21.
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

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> evenSumLeft(n);
    vector<int> oddSumLeft(n);
    vector<int> evenSumRight(n);
    vector<int> oddSumRight(n);
    
    int evensum = 0;
    int oddsum = 0;
    
    for(int i = 0; i < n; i++) {
        evenSumLeft[i] = evensum;
        oddSumLeft[i] = oddsum;
        
        if(i % 2 == 0) {
            evensum += A[i];
        }else{
            oddsum += A[i];
        }
    }
    
    
    evensum = 0;
    oddsum = 0;
    
    for(int i = n-1; i >= 0; i--) {
        evenSumRight[i] = evensum;
        oddSumRight[i] = oddsum;
        
        if(i % 2 == 0) {
            evensum += A[i];
        }else{
            oddsum += A[i];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(evenSumLeft[i] + oddSumRight[i] == evenSumRight[i] + oddSumLeft[i]) {
            ans++;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  Min no of insertions at the front to make a string palindrom
//
//  Created by Giriraj Saigal on 24/02/21.
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

int solve(string A) {
    int n = A.size();
    
    if(n == 0 || n == 1)
        return 0;
    
    int ans = 0;
    
    int i = 0;
    int j = n-1;
    
    while(i <= j) {
        if(A[i] == A[j]) {
            i++;
            j--;
        }else{
            
            if(i == 0) {
                j--;
            }
            
            i = 0;
            
            ans = n - j -1;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<solve("hqghumeaylnlfdxfi");
    return 0;
}

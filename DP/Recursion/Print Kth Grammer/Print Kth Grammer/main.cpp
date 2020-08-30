//
//  main.cpp
//  Print Kth Grammer
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void show(vector<vector<int>> &A, int n, int k){
    
}

void solve(int n, int k, vector<vector<int>> &A){
    
    if(n < 1 || k < 1){
        return;
    }
    
    if(n == 1){
        vector<int> x = {0};
        A.push_back(x);
        return;
    }
    
    
    solve(n-1, k, A);
    
    show(A,n,k);
}

int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}

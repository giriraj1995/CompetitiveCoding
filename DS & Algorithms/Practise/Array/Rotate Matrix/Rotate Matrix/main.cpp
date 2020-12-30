//
//  main.cpp
//  Rotate Matrix
//
//  Created by Giriraj Saigal on 30/12/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
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

void rotate(vector<vector<int> > &A) {
    
    int n = A.size()-1;
    
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(A[i][j] == 0) {
                A[i][j] = INT_MAX;
            }
        }
    }
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            
            int p = i;
            int q = j;
            
            while(A[p][q] < 0) {
                int r = p, m = q;;
                
                m = p;
                r = n - q;
                
                p = r;
                q = m;
            }
            
            int x = j;
            int y = n - i;
            
            while(A[x][y] < 0){
                int r = x, m = y;
                
                m = x;
                r = n - y;
                
                x = r;
                y = m;
            }
            
            int temp = A[p][q];
            A[p][q] = A[x][y];
            A[x][y] = temp;
            
            A[x][y] = -A[x][y];
        }
    }
    
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(A[i][j] < 0) {
                A[i][j] = -A[i][j];
            }
            
            if(A[i][j] == INT_MAX) {
                A[i][j] = 0;
            }
        }
    }
    
}



int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    vector<vector<int>> A(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>A[i][j];
        }
    }
    rotate(A);
    return 0;
}

//
//  main.cpp
//  Rotate Matrix
//
//  Created by Giriraj Saigal on 28/01/21.
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

void rotate(vector<vector<int> > &A) {
    int n = (int)A.size()-1;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(A[i][j] == 0)
                A[i][j] = INT_MAX/2;
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            
            int xx = i;
            int yy = j;
            
            while(A[xx][yy] < 0) {
                int p = n - yy;
                int q = xx;
                xx = p;
                yy = q;
            }
            
            int xd = j;
            int yd = n - i;
            
            while(A[xd][yd] < 0) {
                int p = yd;
                int q = n - xd;
                xd = p;
                yd = q;
            }
            
            if(A[xx][yy] != A[xd][yd]) {
                int temp = A[xx][yy];
                A[xx][yy] = A[xd][yd];
                A[xd][yd] = temp;
            }
            
            A[xd][yd] = -A[xd][yd];
            
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(A[i][j] < 0)
                A[i][j] = -A[i][j];
                
            if(A[i][j] == INT_MAX/2) {
                A[i][j] = 0;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    vector<vector<int> > A = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(A);
    return 0;
}

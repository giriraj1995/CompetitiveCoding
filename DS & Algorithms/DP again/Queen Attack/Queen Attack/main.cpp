//
//  main.cpp
//  Queen Attack
//
//  Created by Giriraj Saigal on 24/11/20.
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

vector<vector<int> > queenAttack(vector<string> A) {
        
    int n = A.size();
    
    int m = A[0].size();
        
    vector<vector<int>> x(n, vector<int>(m , 0)), ans(n, vector<int>(m , 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(A[i][j] == '1')
                x[i][j] = 1;
        }
    }

    vector<vector<int>> A1 = x, A2 = x, A3 = x, A4 = x, A5 = x, A6 = x, A7 = x, A8 = x;
    
    
    //up
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            
            if(i + 1 < n){
                A1[i][j] += (A1[i+1][j]);
            }
        }
    }
    
    //down
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(i - 1 >= 0)
                A2[i][j] += (A2[i-1][j]);
        }
    }
    
    //left
    
    for(int i = 0; i < n; i++) {
        for(int j = m - 1; j >= 0; j--) {
            if(j + 1 < m)
                A3[i][j] += (A3[i][j+1]);
        }
    }
    
    //right
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j - 1 >= 0)
                A4[i][j] += (A4[i][j-1]);
        }
    }
    
    //diagonal Left up
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(j + 1 < m && i + 1 < n) {
                A5[i][j] += A5[i+1][j+1];
            }
        }
    }
    
    //diagonal right up
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(j + 1 < m && i - 1 >= 0) {
                A6[i][j] += A6[i-1][j+1];
            }
        }
    }
    
        
    //diagonal Left down
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j - 1 >=0 && i - 1 >= 0) {
                A7[i][j] += A7[i-1][j-1];
            }
        }
    }
    
    //diagonal right down
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + 1 < n&& j - 1 >= 0)
                A8[i][j] += A8[i+1][j-1];
        }
    }
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            ans[i][j] += A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j] + A5[i][j] + A6[i][j] + A7[i][j] + A8[i][j];
            
            if(x[i][j] == 1){
                ans[i][j] -= 8;
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    queenAttack({{"010"},{"100"},{"001"}});
    return 0;
}

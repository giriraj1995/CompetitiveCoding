//
//  main.cpp
//  48. Rotate Image
//
//  Created by Giriraj Saigal on 30/04/21.
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

void rotate(vector<vector<int>> M) {
    int n = M.size();
    vector<vector<bool>> neg(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(M[i][j] < 0) {
                neg[i][j] = true;
                M[i][j] = abs(M[i][j]);
            }else if(M[i][j] == 0) {
                M[i][j] = INT_MAX;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //to Replace
            int x = i;
            int y = j;
            while(M[x][y] < 0) {
                int p = n-1-y;
                int q = x;
                x = p;
                y = q;
            }
            
            //90 degree to replace
            int a = j;
            int b = n-1-i;
            while(M[a][b] < 0) {
                int p = b;
                int q = n-1-a;
                a = p;
                b = q;
            }
            
            int temp = M[x][y];
            M[x][y] = M[a][b];
            M[a][b] = temp;
            
            M[a][b] = -1 * M[a][b];
        }
    }
    
    for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    M[i][j] = abs(M[i][j]);
                    if(M[i][j] == INT_MAX) {
                        M[i][j] = 0;
                    }
                }
            }
  
    
    for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(neg[i][j]) {
                        M[j][n-1-i] = -1 * M[j][n-1-i];
                    }
                }
            }
    return;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> x = {{43,39,3,33,37,20,14}
        ,{9,18,9,-1,40,22,38},{14,42,3,23,12,14,32},{18,31,45,11,8,-1,31},{28,44,14,23,40,24,13},{29,45,33,45,20,0,45},{12,23,35,32,22,39,8}};
    rotate(x);
    return 0;
}
